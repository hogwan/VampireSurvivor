#include "PreCompile.h"
#include "KingBibleUnit.h"
#include "Enemy.h"
#include "KingBible.h"
#include "Player.h"

AKingBibleUnit::AKingBibleUnit()
{
}

AKingBibleUnit::~AKingBibleUnit()
{
}

void AKingBibleUnit::BeginPlay()
{
	Super::BeginPlay();
	Renderer->SetSprite("KingBible_0.png");
	Renderer->SetAutoSize(2.f, true);
	Renderer->SetOrder(ERenderOrder::PlayerWeapon);

	Collider->SetScale(FVector(30.f, 30.f, 10.f));
	Collider->SetCollisionGroup(ECollisionOrder::PlayerWeapon);
	Collider->SetCollisionType(ECollisionType::RotRect);
}

void AKingBibleUnit::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	ColLogic();
}

void AKingBibleUnit::ColLogic()
{
	Collider->CollisionEnter(ECollisionOrder::Monster, [=](std::shared_ptr<UCollision> _Collision)
		{
			AEnemy* Opponent = dynamic_cast<AEnemy*>(_Collision->GetActor());

			FVector EnemyPos = Opponent->GetActorLocation();
			FVector PlayerPos = UContentsValue::Player->GetActorLocation();

			FVector DirVector = (EnemyPos - PlayerPos).Normalize3DReturn();

			Opponent->GetEnemyData().Hp -= UKingBible::Data.Damage;
			Opponent->SetKnockBack(DirVector * UKingBible::Data.KnockbackPower);
			Opponent->State.ChangeState("KnockBack");
		}
	);
}
