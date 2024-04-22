#include "PreCompile.h"
#include "Player.h"

APlayer::APlayer()
{

	Collision = CreateDefaultSubObject<UCollision>("Collision");
	Collision->SetupAttachment(Root);

	Collision->SetCollisionGroup(ECollisionOrder::Player);
	Collision->SetCollisionType(ECollisionType::Rect);

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
}

void APlayer::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	MoveLogic();
	ColLogic(_DeltaTime);
	

	AddActorLocation(MoveVector * _DeltaTime);
}

void APlayer::MoveLogic()
{
	FVector DirVector = FVector::Zero;
	if (IsPress(VK_RIGHT) && IsPress(VK_UP)) //ºÏµ¿
	{
		DirVector = FVector(1.f, 1.f, 0.f);
		CurDir = AActorDir::NE;
	}
	else if (IsPress(VK_RIGHT) && IsPress(VK_DOWN)) // ³²µ¿
	{
		DirVector = FVector(1.f, -1.f, 0.f);
		CurDir = AActorDir::SE;
	}
	else if (IsPress(VK_LEFT) && IsPress(VK_DOWN)) //³²¼­
	{
		DirVector = FVector(-1.f, -1.f, 0.f);
		CurDir = AActorDir::SW;
	}
	else if (IsPress(VK_LEFT) && IsPress(VK_UP)) // ºÏ¼­
	{
		DirVector = FVector(-1.f, 1.f, 0.f);
		CurDir = AActorDir::NW;
	}
	else if (IsPress(VK_UP)) // ºÏ
	{
		DirVector = FVector(0.f, 1.f, 0.f);
		CurDir = AActorDir::N;
	}
	else if (IsPress(VK_RIGHT)) // µ¿
	{
		DirVector = FVector(1.f, 0.f, 0.f);
		CurDir = AActorDir::E;
	}
	else if (IsPress(VK_DOWN)) // ³²
	{
		DirVector = FVector(0.f, -1.f, 0.f);
		CurDir = AActorDir::S;
	}
	else if (IsPress(VK_LEFT)) // ¼­
	{
		DirVector = FVector(-1.f, 0.f, 0.f);
		CurDir = AActorDir::W;
	}


	DirVector.Normalize3D();
	MoveVector = DirVector * MoveSpeed;
}

void APlayer::ColLogic(float _DeltaTime)
{
}
