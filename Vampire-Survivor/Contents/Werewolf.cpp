#include "PreCompile.h"
#include "Werewolf.h"

AWerewolf::AWerewolf() 
{
}

AWerewolf::~AWerewolf() 
{
}

void AWerewolf::BeginPlay()
{
	Data.MaxHp = 18.f;
	Data.Speed = 130.f;
	Data.Power = 14.f;
	Data.Knockback = 0.8f;
	Data.MaxKnockBack = 3.f;
	Data.XP = 2;

	Super::BeginPlay();

	Renderer->SetAutoSize(1.5f, true);
	Renderer->CreateAnimation("Idle", "Werewolf", 0.1f, true, 0, 2);
	Renderer->CreateAnimation("Death", "Werewolf", 0.05f, false, 3, 14);
	Renderer->SetOrder(ERenderOrder::Werewolf);
	Renderer->ChangeAnimation("Idle");

	Collider->SetScale(FVector(40.f, 40.f, 10.f));

}

void AWerewolf::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}

