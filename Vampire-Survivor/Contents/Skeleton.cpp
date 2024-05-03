#include "PreCompile.h"
#include "Skeleton.h"

ASkeleton::ASkeleton() 
{
}

ASkeleton::~ASkeleton() 
{
}

void ASkeleton::BeginPlay()
{
	Data.MaxHp = 1.5f;
	Data.Speed = 100.f;
	Data.Power = 10.f;
	Data.Knockback = 1.f;
	Data.MaxKnockBack = 3.f;
	Data.XP = 2;

	Super::BeginPlay();

	Renderer->SetAutoSize(1.5f, true);
	Renderer->CreateAnimation("Idle", "Skeleton", 0.1f, true, 0, 2);
	Renderer->CreateAnimation("Death", "Skeleton", 0.05f, false, 3, 14);
	Renderer->SetOrder(ERenderOrder::Monster);
	Renderer->ChangeAnimation("Idle");

	Collider->SetScale(FVector(20.f, 20.f, 10.f));

}

void ASkeleton::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}

