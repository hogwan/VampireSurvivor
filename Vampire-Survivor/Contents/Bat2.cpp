#include "PreCompile.h"
#include "Bat2.h"

ABat2::ABat2() 
{
}

ABat2::~ABat2() 
{
}

void ABat2::BeginPlay()
{
	Super::BeginPlay();

	Renderer->SetAutoSize(1.5f, true);
	Renderer->CreateAnimation("Idle", "Bat2", 0.05f, true, 0, 1);
	Renderer->CreateAnimation("Death", "Bat2", 0.05f, false, 3, 14);
	Renderer->SetOrder(ERenderOrder::Monster);
	Renderer->ChangeAnimation("Idle");

	Collider->SetScale(FVector(20.f, 20.f, 10.f));

	Data.MaxHp = 10.f;
	Data.Speed = 42.f;
	Data.Power = 5.f;
	Data.Knockback = 1.f;
	Data.MaxKnockBack = 3.f;
	Data.XP = 1;
}

void ABat2::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}

