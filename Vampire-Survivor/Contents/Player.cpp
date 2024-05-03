#include "PreCompile.h"
#include "Player.h"
#include "Enemy.h"
#include "SpawnerManager.h"
#include "UIManager.h"
#include "PlayGameMode.h"


APlayer::APlayer()
{
	DetectCollider = CreateDefaultSubObject<UCollision>("Collider");
	DetectCollider->SetupAttachment(Root);
	InputOn();
}

APlayer::~APlayer()
{
}

void APlayer::BeginPlay()
{
	Super::BeginPlay();
	StatusInit();

	Renderer->SetSprite("Player.png", 0);
	Renderer->SetAutoSize(1.5f, true);
	Renderer->SetOrder(ERenderOrder::Player);

	Collider->SetCollisionGroup(ECollisionOrder::Player);
	Collider->SetCollisionType(ECollisionType::CirCle);
	Collider->SetScale(FVector(30.f, 30.f, 20.f));

	DetectCollider->SetCollisionGroup(ECollisionOrder::Detect);
	DetectCollider->SetCollisionType(ECollisionType::CirCle);
	DetectCollider->SetScale(FVector(DetectDistance, DetectDistance, 10.f));
	PushPower = 10.f;


}

void APlayer::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	MoveVector = FVector::Zero;
	MoveLogic();
	ColLogic();
	LevelUpLogic();
	
	AddActorLocation(MoveVector * _DeltaTime);

	NearEnemyCheck();
	RandomEnemyCheck();

	DebugMessageFunction(_DeltaTime);

	int a = 0;
}

void APlayer::NearEnemyCheck()
{
	NearestEnemy = nullptr;
	float Min = 999999.f;
	DetectCollider->CollisionStay(ECollisionOrder::Monster, [&](std::shared_ptr<UCollision> _Collision)
		{
			AEnemy* Monster = dynamic_cast<AEnemy*>(_Collision->GetActor());

			FVector DistanceVector = Monster->GetActorLocation() - GetActorLocation();
			float Distance = DistanceVector.Size3D();

			if (Distance < Min)
			{
				Min = Distance;
				NearestEnemy = Monster;
			}
		}
	);
}

void APlayer::RandomEnemyCheck()
{
	RandomEnemy = nullptr;
	DetectCollider->CollisionStay(ECollisionOrder::Monster, [&](std::shared_ptr<UCollision> _Collision)
		{
			AEnemy* Monster = dynamic_cast<AEnemy*>(_Collision->GetActor());

			RandomEnemy = Monster;
		}
	);
}

void APlayer::DebugMessageFunction(float _Delta)
{
	{
		std::string Msg = std::format("Frame : {}\n", 1.0f / _Delta);
		UEngineDebugMsgWindow::PushMsg(Msg);
	}

	{
		std::string Msg = std::format("EnemyCount : {}\n", USpawnerManager::EnemyCount);
		UEngineDebugMsgWindow::PushMsg(Msg);
	}

	{
		std::string Msg = std::format("Level : {}\n", Data.Level);
		UEngineDebugMsgWindow::PushMsg(Msg);
	}
}

void APlayer::LevelUpLogic()
{
	if (Data.Level == UContentsValue::MaxLevel) return;

	float CurExp = Data.CurExp;
	float MaxExp = Data.TargetExp;

	++UContentsValue::PlayerLevel;

	if (CurExp >= MaxExp)
	{
		++Data.Level;
		Data.CurExp -= Data.TargetExp;
		Data.TargetExp = 5.f * static_cast<float>(pow(Data.Level, 2));
		APlayGameMode::PlayUIManager->LevelUpEventStart();
	}
}

void APlayer::StatusInit()
{
	Data.MaxHealth = 100.f;
}

void APlayer::MoveLogic()
{
	FVector TempVector = FVector::Zero;
	if (IsPress(VK_RIGHT) && IsPress(VK_UP)) //ºÏµ¿
	{
		DirVector = FVector(1.f, 1.f, 0.f);
		TempVector = FVector(1.f, 1.f, 0.f);
		ECurDir = AActorDir::NE;
		SpriteDir = EEngineDir::Right;
	}
	else if (IsPress(VK_RIGHT) && IsPress(VK_DOWN)) // ³²µ¿
	{
		DirVector = FVector(1.f, -1.f, 0.f);
		TempVector = FVector(1.f, -1.f, 0.f);
		ECurDir = AActorDir::SE;
		SpriteDir = EEngineDir::Right;
	}
	else if (IsPress(VK_LEFT) && IsPress(VK_DOWN)) //³²¼­
	{
		DirVector = FVector(-1.f, -1.f, 0.f);
		TempVector = FVector(-1.f, -1.f, 0.f);
		ECurDir = AActorDir::SW;
		SpriteDir = EEngineDir::Left;
	}
	else if (IsPress(VK_LEFT) && IsPress(VK_UP)) // ºÏ¼­
	{
		DirVector = FVector(-1.f, 1.f, 0.f);
		TempVector = FVector(-1.f, 1.f, 0.f);
		ECurDir = AActorDir::NW;
		SpriteDir = EEngineDir::Left;
	}
	else if (IsPress(VK_UP)) // ºÏ
	{
		DirVector = FVector(0.f, 1.f, 0.f);
		TempVector = FVector(0.f, 1.f, 0.f);
		ECurDir = AActorDir::N;
	}
	else if (IsPress(VK_RIGHT)) // µ¿
	{
		DirVector = FVector(1.f, 0.f, 0.f);
		TempVector = FVector(1.f, 0.f, 0.f);
		ECurDir = AActorDir::E;
		SpriteDir = EEngineDir::Right;
	}
	else if (IsPress(VK_DOWN)) // ³²
	{
		DirVector = FVector(0.f, -1.f, 0.f);
		TempVector = FVector(0.f, -1.f, 0.f);
		ECurDir = AActorDir::S;
	}
	else if (IsPress(VK_LEFT)) // ¼­
	{
		DirVector = FVector(-1.f, 0.f, 0.f);
		TempVector = FVector(-1.f, 0.f, 0.f);
		ECurDir = AActorDir::W;
		SpriteDir = EEngineDir::Left;
	}


	TempVector.Normalize3D();
	MoveVector = TempVector * Data.MoveSpeed;
}

void APlayer::ColLogic()
{
	Collider->CollisionStay(ECollisionOrder::Monster, [=](std::shared_ptr<UCollision> _Collision)
		{
			AActor* Opponent = _Collision->GetActor();

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

