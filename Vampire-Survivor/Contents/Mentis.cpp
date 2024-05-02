#include "PreCompile.h"
#include "Mentis.h"

AMentis::AMentis() 
{
}

AMentis::~AMentis() 
{
}

void AMentis::BeginPlay()
{
	Super::BeginPlay();

	Renderer->SetAutoSize(1.5f, true);
	Renderer->CreateAnimation("Idle", "Mentis", 0.1f, true, 0, 2);
	Renderer->CreateAnimation("Death", "Mentis", 0.05f, false, 3, 14);
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

void AMentis::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}
