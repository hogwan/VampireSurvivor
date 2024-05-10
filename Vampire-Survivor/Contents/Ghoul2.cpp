#include "PreCompile.h"
#include "Ghoul2.h"

AGhoul2::AGhoul2() 
{
}

AGhoul2::~AGhoul2() 
{
}

void AGhoul2::BeginPlay()
{
	Data.MaxHp = 1.f;
	Data.Speed = 100.f;
	Data.Power = 10.f;
	Data.Knockback = 0.8f;
	Data.MaxKnockBack = 3.f;
	Data.XP = 1.f;

	Super::BeginPlay();

	Renderer->SetAutoSize(1.5f, true);
	Renderer->CreateAnimation("Idle", "Ghoul2", 0.1f, true, 0, 2);
	Renderer->CreateAnimation("Death", "Ghoul2", 0.05f, false, 3, 14);
	Renderer->SetOrder(ERenderOrder::Ghoul2);
	Renderer->ChangeAnimation("Idle");

	Collider->SetScale(FVector(40.f, 40.f, 10.f));

}

void AGhoul2::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}

