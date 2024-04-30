#include "PreCompile.h"
#include "KnifeUnit.h"
#include "Knife.h"
#include "Enemy.h"
#include "Player.h"

AKnifeUnit::AKnifeUnit()
{
}

AKnifeUnit::~AKnifeUnit()
{
}

void AKnifeUnit::BeginPlay()
{
	Super::BeginPlay();

	Renderer->SetSprite("Knife_1.png");
	Renderer->SetAutoSize(2.f, true);
	Renderer->SetOrder(ERenderOrder::PlayerWeapon);

	Collider->SetCollisionGroup(ECollisionOrder::PlayerWeapon);
	Collider->SetCollisionType(ECollisionType::RotRect);
	Collider->SetScale(FVector(20.f, 30.f, 10.f));


	Penetration = UKnife::Data.Penetration;


}

void AKnifeUnit::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	Release();
	if (Penetration <= 0)
	{
		Destroy();
	}

	ColLogic();
	AddActorLocation(MoveVector * _DeltaTime);

	FVector a =GetActorLocation();
	int b = 0;
}

void AKnifeUnit::ColLogic()
{
	Collider->CollisionEnter(ECollisionOrder::Monster, [=](std::shared_ptr<UCollision> _Collision)
		{
			AEnemy* Opponent = dynamic_cast<AEnemy*>(_Collision->GetActor());

			Opponent->GetEnemyData().Hp -= UKnife::Data.Damage;
			Opponent->SetKnockBack(MoveVector.Normalize3DReturn() * UKnife::Data.KnockbackPower);
			Opponent->State.ChangeState("KnockBack");
			--Penetration;
		}
	);
}

void AKnifeUnit::Release()
{
	FVector PlayerPos = UContentsValue::Player->GetActorLocation();
	FVector CurPos = GetActorLocation();

	if ((PlayerPos - CurPos).Size3D() > 1500.f)
	{
		Destroy();
	}
}

