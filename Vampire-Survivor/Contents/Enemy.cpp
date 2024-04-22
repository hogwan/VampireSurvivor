#include "PreCompile.h"
#include "Enemy.h"
#include "Player.h"
#include <EngineBase/EngineRandom.h>

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
	DeathLogic();
	RepositionLogic();
	MoveLogic();
	ColLogic();

	AddActorLocation(MoveVector * _DeltaTime);
	SpriteDirCheck();
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

	Collider->CollisionStay(ECollisionOrder::PlayerWeapon, [=](std::shared_ptr<UCollision> _Collision)
		{
			AActor* Opponent = _Collision->GetActor();
			Opponent;

			if (this == Opponent)
				return;

			Data.Hp -= 20.f;

		}
	);

	Collider->CollisionStay(ECollisionOrder::Monster, [=](std::shared_ptr<UCollision> _Collision)
		{
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

	Collider->CollisionStay(ECollisionOrder::Player, [=](std::shared_ptr<UCollision> _Collision)
		{
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

void AEnemy::DeathLogic()
{
	if (Data.Hp < 0.f)
	{
		ActiveOff();
	}
}

void AEnemy::RepositionLogic()
{
	FVector PlayerPos = UContentsValue::Player->GetActorLocation();
	PlayerPos.Z = 0.f;

	FVector CurPos = GetActorLocation();
	CurPos.Z = 0.f;

	float Distance = (PlayerPos - CurPos).Size3D();

	if (Distance > 1500.f)
	{
		PlayerPos += UContentsValue::Player->GetPlayerDir() * 1000.f;

		float RandomX = UEngineRandom::MainRandom.RandomFloat(-300.f, 300.f);
		float RandomY = UEngineRandom::MainRandom.RandomFloat(-300.f, 300.f);

		PlayerPos += FVector(RandomX, RandomY, 0.f);
		SetActorLocation(PlayerPos);
	}

}

void AEnemy::SpriteDirCheck()
{
	if (MoveVector.X > 0.f)
	{
		SpriteDir = EEngineDir::Right;
	}
	else
	{
		SpriteDir = EEngineDir::Left;
	}
}

