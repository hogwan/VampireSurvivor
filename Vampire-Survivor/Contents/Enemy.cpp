#include "PreCompile.h"
#include "Enemy.h"
#include "Player.h"
#include <EngineBase/EngineRandom.h>
#include <EngineCore/SpriteInstancingRender.h>
#include "SpawnerManager.h"
#include "Exp.h"

AEnemy::AEnemy() 
{
}

AEnemy::~AEnemy() 
{
	
}

void AEnemy::BeginPlay()
{
	GetWorld()->InstancingOn<USpriteInstancingRender>(ERenderOrder::Monster);

	Super::BeginPlay();

	PushPower = 100.f;

	Collider->SetCollisionGroup(ECollisionOrder::Monster);
	Collider->SetCollisionType(ECollisionType::CirCle);

	State.CreateState("ChasePlayer");
	State.CreateState("KnockBack");

	State.SetStartFunction("ChasePlayer", std::bind(&AEnemy::ChasePlayerStart,this));
	State.SetUpdateFunction("ChasePlayer", std::bind(&AEnemy::ChasePlayer, this, std::placeholders::_1));

	State.SetStartFunction("KnockBack", std::bind(&AEnemy::KnockBackStart, this));
	State.SetUpdateFunction("KnockBack", std::bind(&AEnemy::KnockBack, this, std::placeholders::_1));

	State.ChangeState("ChasePlayer");
}

void AEnemy::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	DeathLogic();
	RepositionLogic();
	ColLogic(_DeltaTime);
	SpriteDirCheck();
	State.Update(_DeltaTime);
}

void AEnemy::ActiveOn()
{
	Super::ActiveOn();
	Data.Hp = Data.MaxHp;
}

void AEnemy::ActiveOff()
{
	Super::ActiveOff();
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

void AEnemy::ColLogic(float _DeltaTime)
{
	Collider->CollisionStay(ECollisionOrder::Monster, [=](std::shared_ptr<UCollision> _Collision)
		{
			AActor* Opponent = _Collision->GetActor();

			if (this == Opponent)
				return;

			FVector OpponentPos = Opponent->GetActorLocation();
			FVector CurPos = GetActorLocation();

			FVector PushDir = CurPos - OpponentPos;
			PushDir.Z = 0.f;
			PushDir.Normalize3D();
			FVector PushVector = PushDir * PushPower;

			AddActorLocation(PushVector * _DeltaTime);
		}
	);

	Collider->CollisionStay(ECollisionOrder::Player, [=](std::shared_ptr<UCollision> _Collision)
		{
			APlayer* Opponent = dynamic_cast<APlayer*>(_Collision->GetActor());

			FPlayerData* PlayerData = Opponent->GetPlayerDataReference();
			if (PlayerData->Hp < 0.f)
			{
				return;
			}

			PlayerData->Hp -= Data.Power * _DeltaTime;

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
		std::shared_ptr<AExp> Exp = GetWorld()->SpawnActor<AExp>("Exp");
		Exp->SetActorLocation(GetActorLocation());
		Exp->SetExp(Data.XP);

		Destroy();
		--USpawnerManager::EnemyCount;
		++UContentsValue::KillCount;
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

void AEnemy::KnockBackStart()
{
	Renderer->SetPlusColor(FVector(0.5f, 0.5f, 0.5f, 1.f));
}

void AEnemy::KnockBack(float _DeltaTime)
{
	AccTime += _DeltaTime;
	if (AccTime > KnockBackTime)
	{
		AccTime = 0.f;
		State.ChangeState("ChasePlayer");
		return;
	}

	AddActorLocation(KnockBackVector * _DeltaTime);
}

void AEnemy::ChasePlayerStart()
{
	Renderer->SetPlusColor(FVector(0.0f, 0.0f, 0.0f, 1.f));
}

void AEnemy::ChasePlayer(float _DeltaTime)
{
	MoveLogic();
	AddActorLocation(MoveVector * _DeltaTime);
}

