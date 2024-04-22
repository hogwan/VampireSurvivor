#include "PreCompile.h"
#include "Player.h"

APlayer::APlayer()
{

	InputOn();
}

APlayer::~APlayer()
{
}

void APlayer::BeginPlay()
{
	Super::BeginPlay();

	Renderer->SetSprite("Player.png", 0);
	Renderer->SetAutoSize(1.f, true);
	Renderer->SetOrder(ERenderOrder::Player);

	Collider->SetCollisionGroup(ECollisionOrder::Player);
	Collider->SetCollisionType(ECollisionType::CirCle);
	Collider->SetScale(FVector(30.f, 30.f, 20.f));
	PushPower = 10.f;
}

void APlayer::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	MoveVector = FVector::Zero;
	MoveLogic();
	ColLogic();
	
	AddActorLocation(MoveVector * _DeltaTime);
}

void APlayer::MoveLogic()
{
	DirVector = FVector::Zero;
	if (IsPress(VK_RIGHT) && IsPress(VK_UP)) //ºÏµ¿
	{
		DirVector = FVector(1.f, 1.f, 0.f);
		ECurDir = AActorDir::NE;
		SpriteDir = EEngineDir::Right;
	}
	else if (IsPress(VK_RIGHT) && IsPress(VK_DOWN)) // ³²µ¿
	{
		DirVector = FVector(1.f, -1.f, 0.f);
		ECurDir = AActorDir::SE;
		SpriteDir = EEngineDir::Right;
	}
	else if (IsPress(VK_LEFT) && IsPress(VK_DOWN)) //³²¼­
	{
		DirVector = FVector(-1.f, -1.f, 0.f);
		ECurDir = AActorDir::SW;
		SpriteDir = EEngineDir::Left;
	}
	else if (IsPress(VK_LEFT) && IsPress(VK_UP)) // ºÏ¼­
	{
		DirVector = FVector(-1.f, 1.f, 0.f);
		ECurDir = AActorDir::NW;
		SpriteDir = EEngineDir::Left;
	}
	else if (IsPress(VK_UP)) // ºÏ
	{
		DirVector = FVector(0.f, 1.f, 0.f);
		ECurDir = AActorDir::N;
	}
	else if (IsPress(VK_RIGHT)) // µ¿
	{
		DirVector = FVector(1.f, 0.f, 0.f);
		ECurDir = AActorDir::E;
		SpriteDir = EEngineDir::Right;
	}
	else if (IsPress(VK_DOWN)) // ³²
	{
		DirVector = FVector(0.f, -1.f, 0.f);
		ECurDir = AActorDir::S;
	}
	else if (IsPress(VK_LEFT)) // ¼­
	{
		DirVector = FVector(-1.f, 0.f, 0.f);
		ECurDir = AActorDir::W;
		SpriteDir = EEngineDir::Left;
	}


	DirVector.Normalize3D();
	MoveVector = DirVector * MoveSpeed;
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
