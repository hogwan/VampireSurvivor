#include "PreCompile.h"
#include "SantaWaterUnit.h"
#include "SantaWater.h"
#include "Enemy.h"

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
	Renderer->SetAutoSize(2.f, true);
	Renderer->SetOrder(ERenderOrder::PlayerWeapon);
	Renderer->CreateAnimation("Broken","SantaWaterBroken",0.2f,true);

	Collider->SetCollisionGroup(ECollisionOrder::PlayerWeapon);
	Collider->SetCollisionType(ECollisionType::RotRect);
	Collider->SetScale(FVector(60.f, 60.f, 10.f));

	StateInit();
}

void ASantaWaterUnit::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	State.Update(_DeltaTime);
}

void ASantaWaterUnit::ColLogic()
{
	Collider->SetScale(Collider->GetLocalScale() * USantaWater::Data.Area);
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
		State.ChangeState("Spread");
		return;
	}
}

void ASantaWaterUnit::Spread(float _DeltaTime)
{
	RemainTime -= _DeltaTime;
	if (RemainTime < 0.f)
	{
		RemainTime = DamageTerm;
		ColLogic();
	}
}

void ASantaWaterUnit::StateInit()
{
	State.CreateState("Fall");
	State.CreateState("Broken");
	State.CreateState("Spread");

	State.SetStartFunction("Fall", [=]
		{
			Renderer->SetSprite("SantaWater_0.png");
		});
	State.SetUpdateFunction("Fall", std::bind(&ASantaWaterUnit::Fall, this, std::placeholders::_1));

	State.SetStartFunction("Broken", [=]
		{
			Renderer->ChangeAnimation("Broken");
		});
	State.SetUpdateFunction("Broken", std::bind(&ASantaWaterUnit::Broken, this, std::placeholders::_1));

	State.SetStartFunction("Spread", [=]
		{
			//Renderer->SetSprite("");
		});
	State.SetUpdateFunction("Spread", std::bind(&ASantaWaterUnit::Spread, this, std::placeholders::_1));

	State.ChangeState("Fall");
}
