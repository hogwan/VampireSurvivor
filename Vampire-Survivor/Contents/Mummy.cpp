#include "PreCompile.h"
#include "Mummy.h"

AMummy::AMummy() 
{
}

AMummy::~AMummy() 
{
}

void AMummy::BeginPlay()
{
	Data.MaxHp = 1.5f;
	Data.Speed = 140.f;
	Data.Power = 3.f;
	Data.Knockback = 1.f;
	Data.MaxKnockBack = 3.f;
	Data.XP = 2;

	Super::BeginPlay();

	Renderer->SetAutoSize(1.5f, true);
	Renderer->CreateAnimation("Idle", "Mummy", 0.1f, true, 0, 2);
	Renderer->CreateAnimation("Death", "Mummy", 0.05f, false, 3, 14);
	Renderer->SetOrder(ERenderOrder::Mummy);
	Renderer->ChangeAnimation("Idle");

	Collider->SetScale(FVector(40.f, 40.f, 10.f));

}

void AMummy::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}

