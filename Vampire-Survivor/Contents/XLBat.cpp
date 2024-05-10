#include "PreCompile.h"
#include "XLBat.h"

AXLBat::AXLBat() 
{
}

AXLBat::~AXLBat() 
{
}

void AXLBat::BeginPlay()
{
	Data.MaxHp = 27.f;
	Data.Speed = 140.f;
	Data.Power = 10.f;
	Data.Knockback = 0.1f;
	Data.MaxKnockBack = 3.f;
	Data.XP = 2.5;
	Super::BeginPlay();

	Renderer->SetAutoSize(1.5f, true);
	Renderer->CreateAnimation("Idle", "XLBat", 0.1f, true, 0, 2);
	Renderer->CreateAnimation("Death", "XLBat", 0.05f, false, 3, 14);
	Renderer->SetOrder(ERenderOrder::XLBat);
	Renderer->ChangeAnimation("Idle");

	Collider->SetScale(FVector(50.f, 50.f, 10.f));

}

void AXLBat::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}

