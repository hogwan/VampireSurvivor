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
	Data.MaxHp = 50.f;
	Data.Speed = 80.f;
	Data.Power = 20.f;
	Data.Knockback = 0.f;
	Data.MaxKnockBack = 3.f;
	Data.XP = 3;

	Super::BeginPlay();

	Renderer->SetAutoSize(1.5f, true);
	Renderer->CreateAnimation("Idle", "Mentis", 0.1f, true, 0, 2);
	Renderer->CreateAnimation("Death", "Mentis", 0.05f, false, 3, 14);
	Renderer->SetOrder(ERenderOrder::Monster);
	Renderer->ChangeAnimation("Idle");

	Collider->SetScale(FVector(20.f, 20.f, 10.f));

}

void AMentis::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}

