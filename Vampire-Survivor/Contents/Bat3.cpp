#include "PreCompile.h"
#include "Bat3.h"

ABat3::ABat3() 
{
}

ABat3::~ABat3() 
{
}

void ABat3::BeginPlay()
{
	Super::BeginPlay();

	Renderer->SetAutoSize(1.5f, true);
	Renderer->CreateAnimation("Idle", "Bat3", 0.05f, true, 0, 1);
	Renderer->CreateAnimation("Death", "Bat3", 0.05f, false, 3, 14);
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

void ABat3::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}

