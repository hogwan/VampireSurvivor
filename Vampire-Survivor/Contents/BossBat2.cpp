#include "PreCompile.h"
#include "BossBat2.h"

ABossBat2::ABossBat2() 
{
}

ABossBat2::~ABossBat2() 
{
}

void ABossBat2::BeginPlay()
{
	Data.MaxHp = 5.f;
	Data.Speed = 140.f;
	Data.Power = 10.f;
	Data.Knockback = 1.f;
	Data.MaxKnockBack = 3.f;
	Data.XP = 30.f;

	Super::BeginPlay();

	Renderer->SetAutoSize(1.5f, true);
	Renderer->CreateAnimation("Idle", "BossBat2", 0.05f, true, 0, 1);
	Renderer->CreateAnimation("Death", "BossBat2", 0.05f, false, 3, 14);
	Renderer->SetOrder(ERenderOrder::Monster);
	Renderer->ChangeAnimation("Idle");

	Collider->SetScale(FVector(30.f, 30.f, 10.f));
}

void ABossBat2::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}
