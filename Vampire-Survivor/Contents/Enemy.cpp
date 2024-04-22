#include "PreCompile.h"
#include "Enemy.h"
#include "Player.h"

AEnemy::AEnemy() 
{
}

AEnemy::~AEnemy() 
{
}

void AEnemy::BeginPlay()
{
	Super::BeginPlay();
	PushPower = 100.f;

	Collider->SetCollisionGroup(ECollisionOrder::Monster);
	Collider->SetCollisionType(ECollisionType::CirCle);
}

void AEnemy::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	Death();
	MoveLogic();
	ColLogic();

	AddActorLocation(MoveVector * _DeltaTime);
}

void AEnemy::MoveLogic()
{
	MoveVector = FVector::Zero;
	FVector PlayerPos = UContentsValue::Player->GetActorLocation();
	FVector CurPos = GetActorLocation();

	FVector DirVector = PlayerPos - CurPos;
	DirVector.Z = 0.f;
	DirVector.Normalize3D();

	MoveVector = DirVector * Data.Speed;
}

void AEnemy::ColLogic()
{
	Collider->CollisionStay(ECollisionOrder::Monster, [=](std::shared_ptr<UCollision> _Collision)
		{
			this;
			AActor* Opponent = _Collision->GetActor();
			Opponent;

			if (this == Opponent)
				return;


			FVector OpponentPos = Opponent->GetActorLocation();
			FVector CurPos = GetActorLocation();

			FVector PushDir = CurPos - OpponentPos;
			PushDir.Z = 0.f;
			PushDir.Normalize3D();
			FVector PushVector = PushDir * PushPower;

			MoveVector += PushVector;
		}
	);
}

void AEnemy::Death()
{
	if (Data.Hp < 0.f)
	{
		ActiveOff();
	}
}

