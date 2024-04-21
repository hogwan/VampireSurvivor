#include "PreCompile.h"
#include "Player.h"

APlayer::APlayer()
{
	
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("Root");

	Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	Renderer->SetupAttachment(Root);
	Renderer->SetPivot(EPivot::BOT);

	Collision = CreateDefaultSubObject<UCollision>("Collision");
	Collision->SetupAttachment(Root);

	Collision->SetCollisionGroup(ECollisionOrder::Player);
	Collision->SetCollisionType(ECollisionType::Rect);

	SetRoot(Root);

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

	if (IsPress(VK_RIGHT))
	{
		AddActorLocation(FVector::Right * 1000.f * _DeltaTime);
	}

	if (IsPress(VK_LEFT))
	{
		AddActorLocation(FVector::Left * 1000.f * _DeltaTime);
	}

	if (IsPress(VK_UP))
	{
		AddActorLocation(FVector::Up* 1000.f * _DeltaTime);
	}

	if (IsPress(VK_DOWN))
	{
		AddActorLocation(FVector::Down * 1000.f * _DeltaTime);
	}
}
