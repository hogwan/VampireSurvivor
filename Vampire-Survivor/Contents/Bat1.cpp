#include "PreCompile.h"
#include "Bat1.h"
#include <EngineCore/SpriteInstancingRender.h>

ABat1::ABat1() 
{
}

ABat1::~ABat1() 
{
}

void ABat1::BeginPlay()
{
	Data.MaxHp = 0.1f;
	Data.Speed = 140.f;
	Data.Power = 5.f;
	Data.Knockback = 1.f;
	Data.MaxKnockBack = 3.f;
	Data.XP = 1.f;

	Super::BeginPlay();

	Renderer->SetAutoSize(1.5f, true);
	Renderer->CreateAnimation("Idle", "Bat1", 0.05f, true, 0, 1);
	Renderer->CreateAnimation("Death", "Bat1", 0.05f, false, 3, 14);
	Renderer->SetOrder(ERenderOrder::Bat1);
	Renderer->ChangeAnimation("Idle");

	Collider->SetScale(FVector(30.f, 30.f, 10.f));


	
}

void ABat1::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}

