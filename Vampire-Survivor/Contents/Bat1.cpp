#include "PreCompile.h"
#include "Bat1.h"
#include <EngineCore/SpriteInstancingRender.h>

EPollingOrder ABat1::PollingOrder = EPollingOrder::Bat1;

ABat1::ABat1() 
{
}

ABat1::~ABat1() 
{
}

void ABat1::BeginPlay()
{
	Super::BeginPlay();

	Renderer->SetAutoSize(1.5f, true);
	Renderer->CreateAnimation("Idle", "Bat1", 0.05f, true, 0, 1);
	Renderer->CreateAnimation("Death", "Bat1", 0.05f, false, 3, 14);
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

void ABat1::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}

