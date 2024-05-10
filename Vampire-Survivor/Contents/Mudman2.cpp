#include "PreCompile.h"
#include "Mudman2.h"

AMudman2::AMudman2() 
{
}

AMudman2::~AMudman2() 
{
}

void AMudman2::BeginPlay()
{
	Data.MaxHp = 15.f;
	Data.Speed = 100.f;
	Data.Power = 10.f;
	Data.Knockback = 0.3f;
	Data.MaxKnockBack = 3.f;
	Data.XP = 2.5;

	Super::BeginPlay();

	Renderer->SetAutoSize(1.5f, true);
	Renderer->CreateAnimation("Idle", "Mudman2", 0.1f, true, 0, 2);
	Renderer->CreateAnimation("Death", "Mudman2", 0.05f, false, 3, 14);
	Renderer->SetOrder(ERenderOrder::Mudman2);
	Renderer->ChangeAnimation("Idle");

	Collider->SetScale(FVector(40.f, 40.f, 10.f));

}

void AMudman2::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}

