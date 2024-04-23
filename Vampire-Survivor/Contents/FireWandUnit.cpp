#include "PreCompile.h"
#include "FireWandUnit.h"
#include "FireWand.h"
#include "Enemy.h"

AFireWandUnit::AFireWandUnit()
{
}

AFireWandUnit::~AFireWandUnit()
{
}

void AFireWandUnit::BeginPlay()
{
	Super::BeginPlay();

	Renderer->SetSprite("FireWand_0.png");
	Renderer->SetAutoSize(2.f, true);
	Renderer->SetOrder(ERenderOrder::PlayerWeapon);

	Collider->SetCollisionGroup(ECollisionOrder::PlayerWeapon);
	Collider->SetCollisionType(ECollisionType::RotRect);
	Collider->SetScale(FVector(32.f, 36.f, 10.f));

	RemainTime = UFireWand::Data.Duration;
}

void AFireWandUnit::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	RemainTime -= _DeltaTime;
	if (RemainTime < 0.f)
	{
		Destroy();
	}
	ColLogic();
	DirCheck();

	AddActorLocation(MoveVector * _DeltaTime);

}

void AFireWandUnit::ColLogic()
{
	Collider->CollisionEnter(ECollisionOrder::Monster, [=](std::shared_ptr<UCollision> _Collision)
		{
			AEnemy* Opponent = dynamic_cast<AEnemy*>(_Collision->GetActor());

			Opponent->GetEnemyData().Hp -= UFireWand::Data.Damage;
			Destroy();
		}
	);
}

void AFireWandUnit::DirCheck()
{
	FVector Dir = MoveVector.Normalize3DReturn();

	if (Dir.X < 0.f)
	{
		SetActorRotation(FVector(0.f, 0.f, 180.f - Dir.Y * 90.f));
	}
	else
	{
		SetActorRotation(FVector(0.f, 0.f, Dir.Y * 90.f));
	}
}