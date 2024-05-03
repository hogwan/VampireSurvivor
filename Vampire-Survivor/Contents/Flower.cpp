#include "PreCompile.h"
#include "Flower.h"

AFlower::AFlower() 
{
}

AFlower::~AFlower() 
{
}

void AFlower::BeginPlay()
{
	Data.MaxHp = 3.f;
	Data.Speed = 20.f;
	Data.Power = 1.f;
	Data.Knockback = 1.f;
	Data.MaxKnockBack = 3.f;
	Data.XP = 2.f;

	Super::BeginPlay();

	Renderer->SetAutoSize(1.5f, true);
	Renderer->CreateAnimation("Idle", "Flower", 0.1f, true, 0, 2);
	Renderer->CreateAnimation("Death", "Flower", 0.05f, false, 3, 14);
	Renderer->SetOrder(ERenderOrder::Monster);
	Renderer->ChangeAnimation("Idle");

	Collider->SetScale(FVector(20.f, 20.f, 10.f));

}

void AFlower::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}

