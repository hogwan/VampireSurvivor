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
	Data.MaxHp = 0.5f;
	Data.Speed = 140.f;
	Data.Power = 5.f;
	Data.Knockback = 1.f;
	Data.MaxKnockBack = 3.f;
	Data.XP = 1.f;

	Super::BeginPlay();

	Renderer->SetAutoSize(1.5f, true);
	Renderer->CreateAnimation("Idle", "Bat3", 0.05f, true, 0, 1);
	Renderer->CreateAnimation("Death", "Bat3", 0.05f, false, 3, 14);
	Renderer->SetOrder(ERenderOrder::Bat3);
	Renderer->ChangeAnimation("Idle");

	Collider->SetScale(FVector(30.f, 30.f, 10.f));

}

void ABat3::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}

