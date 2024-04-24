#include "PreCompile.h"
#include "Player.h"
#include "Enemy.h"

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
	
	AddActorLocation(MoveVector * _DeltaTime);

	NearEnemyCheck();
	RandomEnemyCheck();
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

			if (Distance < DetectDistance)
			{
				if (Distance < Min)
				{
					Min = Distance;
					NearestEnemy = Monster;
				}
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

void APlayer::MoveLogic()
{
	FVector TempVector = FVector::Zero;
	if (IsPress(VK_RIGHT) && IsPress(VK_UP)) //�ϵ�
	{
		DirVector = FVector(1.f, 1.f, 0.f);
		TempVector = FVector(1.f, 1.f, 0.f);
		ECurDir = AActorDir::NE;
		SpriteDir = EEngineDir::Right;
	}
	else if (IsPress(VK_RIGHT) && IsPress(VK_DOWN)) // ����
	{
		DirVector = FVector(1.f, -1.f, 0.f);
		TempVector = FVector(1.f, -1.f, 0.f);
		ECurDir = AActorDir::SE;
		SpriteDir = EEngineDir::Right;
	}
	else if (IsPress(VK_LEFT) && IsPress(VK_DOWN)) //����
	{
		DirVector = FVector(-1.f, -1.f, 0.f);
		TempVector = FVector(-1.f, -1.f, 0.f);
		ECurDir = AActorDir::SW;
		SpriteDir = EEngineDir::Left;
	}
	else if (IsPress(VK_LEFT) && IsPress(VK_UP)) // �ϼ�
	{
		DirVector = FVector(-1.f, 1.f, 0.f);
		TempVector = FVector(-1.f, 1.f, 0.f);
		ECurDir = AActorDir::NW;
		SpriteDir = EEngineDir::Left;
	}
	else if (IsPress(VK_UP)) // ��
	{
		DirVector = FVector(0.f, 1.f, 0.f);
		TempVector = FVector(0.f, 1.f, 0.f);
		ECurDir = AActorDir::N;
	}
	else if (IsPress(VK_RIGHT)) // ��
	{
		DirVector = FVector(1.f, 0.f, 0.f);
		TempVector = FVector(1.f, 0.f, 0.f);
		ECurDir = AActorDir::E;
		SpriteDir = EEngineDir::Right;
	}
	else if (IsPress(VK_DOWN)) // ��
	{
		DirVector = FVector(0.f, -1.f, 0.f);
		TempVector = FVector(0.f, -1.f, 0.f);
		ECurDir = AActorDir::S;
	}
	else if (IsPress(VK_LEFT)) // ��
	{
		DirVector = FVector(-1.f, 0.f, 0.f);
		TempVector = FVector(-1.f, 0.f, 0.f);
		ECurDir = AActorDir::W;
		SpriteDir = EEngineDir::Left;
	}


	TempVector.Normalize3D();
	MoveVector = TempVector * MoveSpeed;
}

void APlayer::ColLogic()
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
