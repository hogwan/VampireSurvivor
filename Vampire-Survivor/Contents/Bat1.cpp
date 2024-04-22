#include "PreCompile.h"
#include "Bat1.h"

EPollingOrder ABat1::PollingOrder = EPollingOrder::Bat1;

ABat1::ABat1() 
{
}

ABat1::~ABat1() 
{
}

void ABat1::BeginPlay()
{
	Super::BeginPlay();

	Renderer->SetAutoSize(1.f, true);
	Renderer->CreateAnimation("Idle", "BatIDLE.png", 0.1f, 0, 3, true);
	Renderer->SetOrder(ERenderOrder::Monster);
	Renderer->ChangeAnimation("Idle");

	Collider->SetScale(FVector(20.f, 20.f, 10.f));

	Data.MaxHp = 10.f;
	Data.Speed = 50.f;
	Data.Power = 5.f;
	Data.Knockback = 1.f;
	Data.MaxKnockBack = 3.f;
	Data.XP = 1;
}

void ABat1::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}

