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
	Super::BeginPlay();

	Renderer->SetAutoSize(1.5f, true);
	Renderer->CreateAnimation("Idle", "Mudman1", 0.1f, true, 0, 2);
	Renderer->CreateAnimation("Death", "Mudman1", 0.05f, false, 3, 14);
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

void AMudman1::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}

