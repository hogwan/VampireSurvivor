#include "PreCompile.h"
#include "ThunderShock.h"
#include "LightingRing.h"
#include "Enemy.h"

AThunderShock::AThunderShock()
{
}

AThunderShock::~AThunderShock()
{
}

void AThunderShock::BeginPlay()
{
	Super::BeginPlay();

	Renderer->SetSprite("ThunderShockFX.png");
	Renderer->SetScale(FVector(1.f, 1.f, 10.f));
	Renderer->SetOrder(ERenderOrder::Particle);

	Collider->SetCollisionGroup(ECollisionOrder::PlayerWeapon);
	Collider->SetCollisionType(ECollisionType::RotRect);
	Collider->SetScale(FVector(1.f, 1.f, 10.f));

	SetActorScale3D(FVector(ULightingRing::Data.Area, ULightingRing::Data.Area, 0.f));
	int a = 0;
}

void AThunderShock::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	LiveTime -= _DeltaTime;
	if (LiveTime < 0.f)
	{
		Destroy();
	}

	ColLogic();
	Renderer->AddScale(IncreaseTerm * _DeltaTime);
	Collider->AddScale(IncreaseTerm * _DeltaTime);

	Alpha -= AlphaDecrease * _DeltaTime;
	Renderer->SetMulColor({ 1.f, 1.f, 1.f, Alpha });
}

void AThunderShock::ColLogic()
{
	Collider->CollisionEnter(ECollisionOrder::Monster, [=](std::shared_ptr<UCollision> _Collision)
		{
			AEnemy* Opponent = dynamic_cast<AEnemy*>(_Collision->GetActor());

			Opponent->GetEnemyData().Hp -= ULightingRing::Data.Damage;
		}
	);
}
