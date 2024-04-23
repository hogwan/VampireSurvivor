#include "PreCompile.h"
#include "MagicWandUnit.h"
#include "MagicWand.h"
#include "Enemy.h"

AMagicWandUnit::AMagicWandUnit() 
{

}

AMagicWandUnit::~AMagicWandUnit() 
{
}

void AMagicWandUnit::BeginPlay()
{
	Super::BeginPlay();
	Renderer->CreateAnimation("Flying", "MagicWand", 0, 1, 0.1f, true);
	Renderer->SetAutoSize(1.f, true);
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
			--Penetration;
		}
	);
}

