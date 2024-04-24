#include "PreCompile.h"
#include "SantaWaterUnit.h"
#include "SantaWater.h"
#include "Enemy.h"
#include "SantaWaterFlame.h"
#include <EngineBase/EngineRandom.h>

ASantaWaterUnit::ASantaWaterUnit() 
{
}

ASantaWaterUnit::~ASantaWaterUnit() 
{
}

void ASantaWaterUnit::BeginPlay()
{
	Super::BeginPlay();

	Renderer->SetSprite("SantaWaterBottle_0.png");
	Renderer->SetScale(FVector(32.f, 32.f, 10.f));
	Renderer->SetOrder(ERenderOrder::PlayerWeapon);
	Renderer->CreateAnimation("Broken","SantaWaterBroken",0.1f,false);

	Collider->SetCollisionGroup(ECollisionOrder::PlayerWeapon);
	Collider->SetCollisionType(ECollisionType::RotRect);
	Collider->SetScale(FVector(60.f, 60.f, 10.f));

	Duration = USantaWater::Data.Duration;
	StateInit();

	
}

void ASantaWaterUnit::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	State.Update(_DeltaTime);
	
}

void ASantaWaterUnit::ColLogic()
{
	Collider->CollisionStay(ECollisionOrder::Monster, [=](std::shared_ptr<UCollision> _Collision)
		{
			AEnemy* Opponent = dynamic_cast<AEnemy*>(_Collision->GetActor());

			Opponent->GetEnemyData().Hp -= USantaWater::Data.Damage;
		}
	);
}

void ASantaWaterUnit::Fall(float _DeltaTime)
{
	AddActorLocation(Gravity * _DeltaTime);
	AddActorRotation(FVector(0.f, 0.f, RotationSpeed * _DeltaTime));

	FVector CurPos = GetActorLocation();
	if (CurPos.Y < TargetPos.Y)
	{
		State.ChangeState("Broken");
		return;
	}
}

void ASantaWaterUnit::Broken(float _DeltaTime)
{
	if (Renderer->IsCurAnimationEnd())
	{
		Renderer->AnimationReset();
		State.ChangeState("Spread");
		return;
	}
}

void ASantaWaterUnit::Spread(float _DeltaTime)
{
	SetActorScale3D(FVector(USantaWater::Data.Area, USantaWater::Data.Area, 1.f));
	RemainTime -= _DeltaTime;
	if (RemainTime < 0.f)
	{
		RemainTime = DamageTerm;
		ColLogic();
	}

	Duration -= _DeltaTime;
	if (Duration < 0.f)
	{
		Destroy();
	}

	SpawnFlame(_DeltaTime);
}

void ASantaWaterUnit::SpawnFlame(float _DeltaTime)
{
	FlameSpawnRemainTime -= _DeltaTime;
	if (FlameSpawnRemainTime < 0.f)
	{
		FlameSpawnRemainTime = FlameSpawnTime;
		std::shared_ptr<ASantaWaterFlame> Flame = GetWorld()->SpawnActor<ASantaWaterFlame>("Flame");

		float r = Renderer->GetLocalScale().X/2.f;
		float Y = UEngineRandom::MainRandom.RandomFloat(-r, r);
		float X = UEngineRandom::MainRandom.RandomFloat(-r, r);
		
		Flame->SetActorLocation(GetActorLocation() + FVector(X, Y, 10.f));
	}
	
}

void ASantaWaterUnit::StateInit()
{
	State.CreateState("Fall");
	State.CreateState("Broken");
	State.CreateState("Spread");

	State.SetStartFunction("Fall", [=]
		{
			Renderer->SetSprite("SantaWaterBottle_0.png");
		});
	State.SetUpdateFunction("Fall", std::bind(&ASantaWaterUnit::Fall, this, std::placeholders::_1));

	State.SetStartFunction("Broken", [=]
		{
			Renderer->SetScale(FVector(50.f, 50.f, 10.f));
			Renderer->ChangeAnimation("Broken");
		});
	State.SetUpdateFunction("Broken", std::bind(&ASantaWaterUnit::Broken, this, std::placeholders::_1));

	State.SetStartFunction("Spread", [=]
		{
			Renderer->SetSprite("CircleFX.png");
			Renderer->SetScale(FVector(100.f, 100.f, 10.f));
			Renderer->SetPlusColor({ 0.f, 0.f, 0.5f });
		});
	State.SetUpdateFunction("Spread", std::bind(&ASantaWaterUnit::Spread, this, std::placeholders::_1));

	State.ChangeState("Fall");
}
