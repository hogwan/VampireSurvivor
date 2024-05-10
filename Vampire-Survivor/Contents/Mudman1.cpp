#include "PreCompile.h"
#include "Mudman1.h"

AMudman1::AMudman1() 
{
}

AMudman1::~AMudman1() 
{
}

void AMudman1::BeginPlay()
{
	Data.MaxHp = 7.f;
	Data.Speed = 100.f;
	Data.Power = 10.f;
	Data.Knockback = 0.3f;
	Data.MaxKnockBack = 3.f;
	Data.XP = 2.5f;
	Super::BeginPlay();

	Renderer->SetAutoSize(1.5f, true);
	Renderer->CreateAnimation("Idle", "Mudman1", 0.1f, true, 0, 2);
	Renderer->CreateAnimation("Death", "Mudman1", 0.05f, false, 3, 14);
	Renderer->SetOrder(ERenderOrder::Mudman1);
	Renderer->ChangeAnimation("Idle");

	Collider->SetScale(FVector(40.f, 40.f, 10.f));

}

void AMudman1::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}

