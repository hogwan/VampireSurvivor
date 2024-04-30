#include "PreCompile.h"
#include "MagicWandUnit.h"
#include "MagicWand.h"
#include "Enemy.h"
#include "Player.h"

AMagicWandUnit::AMagicWandUnit() 
{

}

AMagicWandUnit::~AMagicWandUnit() 
{
}

void AMagicWandUnit::BeginPlay()
{
	Super::BeginPlay();
	Renderer->CreateAnimation("Flying", "MagicWand", 0.1f, true);
	Renderer->SetAutoSize(2.f, true);
	Renderer->SetOrder(ERenderOrder::PlayerWeapon);

	Renderer->ChangeAnimation("Flying");

	Collider->SetCollisionGroup(ECollisionOrder::PlayerWeapon);
	Collider->SetCollisionType(ECollisionType::CirCle);
	Collider->SetScale(FVector(30.f, 30.f, 10.f));

	Penetration = UMagicWand::Data.Penetration;
}

void AMagicWandUnit::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	Release();
	if (Penetration <= 0)
	{
		Destroy();
	}

	ColLogic();
	AddActorLocation(MoveVector * _DeltaTime);
}

void AMagicWandUnit::ColLogic()
{
	Collider->CollisionEnter(ECollisionOrder::Monster, [=](std::shared_ptr<UCollision> _Collision)
		{
			AEnemy* Opponent = dynamic_cast<AEnemy*>(_Collision->GetActor());

			Opponent->GetEnemyData().Hp -= UMagicWand::Data.Damage;
			Opponent->SetKnockBack(MoveVector.Normalize3DReturn() * UMagicWand::Data.KnockbackPower);
			Opponent->State.ChangeState("KnockBack");
			--Penetration;
		}
	);
}

void AMagicWandUnit::Release()
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

