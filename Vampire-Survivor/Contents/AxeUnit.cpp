#include "PreCompile.h"
#include "AxeUnit.h"
#include "Axe.h"
#include "Enemy.h"
#include "Player.h"

AAxeUnit::AAxeUnit()
{
}

AAxeUnit::~AAxeUnit()
{
}

void AAxeUnit::BeginPlay()
{
	Super::BeginPlay();

	Renderer->SetSprite("Axe_0.png");
	Renderer->SetAutoSize(2.f, true);
	Renderer->SetOrder(ERenderOrder::PlayerWeapon);

	Collider->SetCollisionGroup(ECollisionOrder::PlayerWeapon);
	Collider->SetCollisionType(ECollisionType::RotRect);
	Collider->SetScale(FVector(32.f, 36.f, 10.f));

	Penetration = UAxe::Data.Penetration;
}

void AAxeUnit::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	if (Penetration <= 0)
	{
		Destroy();
	}
	Release();

	ColLogic();

	if (MoveVector.X < 0)
	{
		AddActorRotation(FVector(0.f, 0.f, RotationSpeed * _DeltaTime));
	}
	else
	{
		AddActorRotation(FVector(0.f, 0.f, -RotationSpeed * _DeltaTime));
	}


	MoveVector += Gravity * _DeltaTime;

	AddActorLocation(MoveVector * _DeltaTime);
}

void AAxeUnit::ColLogic()
{
	Collider->CollisionEnter(ECollisionOrder::Monster, [=](std::shared_ptr<UCollision> _Collision)
		{
			AEnemy* Opponent = dynamic_cast<AEnemy*>(_Collision->GetActor());

			Opponent->GetEnemyData().Hp -= UAxe::Data.Damage;
			--Penetration;
		}
	);
}

void AAxeUnit::Release()
{
	FVector PlayerPos = UContentsValue::Player->GetActorLocation();
	FVector CurPos = GetActorLocation();

	PlayerPos.Z = 0;
	CurPos.Z = 0;

	float Distance = (PlayerPos - CurPos).Size3D();
	if (Distance > 1500.f)
	{
		Destroy();
	}
}
