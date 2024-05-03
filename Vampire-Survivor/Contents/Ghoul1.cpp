#include "PreCompile.h"
#include "Ghoul1.h"

AGhoul1::AGhoul1() 
{
}

AGhoul1::~AGhoul1() 
{
}

void AGhoul1::BeginPlay()
{
	Data.MaxHp = 1.f;
	Data.Speed = 100.f;
	Data.Power = 10.f;
	Data.Knockback = 0.8f;
	Data.MaxKnockBack = 3.f;
	Data.XP = 1.f;

	Super::BeginPlay();

	Renderer->SetAutoSize(1.5f, true);
	Renderer->CreateAnimation("Idle", "Ghoul1", 0.1f, true, 0, 2);
	Renderer->CreateAnimation("Death", "Ghoul1", 0.05f, false, 3, 14);
	Renderer->SetOrder(ERenderOrder::Monster);
	Renderer->ChangeAnimation("Idle");

	Collider->SetScale(FVector(20.f, 20.f, 10.f));


}

void AGhoul1::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}

