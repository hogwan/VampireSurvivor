#include "PreCompile.h"
#include "SmallFlower.h"

ASmallFlower::ASmallFlower() 
{
}

ASmallFlower::~ASmallFlower() 
{
}

void ASmallFlower::BeginPlay()
{
	Data.MaxHp = 10.f;
	Data.Speed = 80.f;
	Data.Power = 10.f;
	Data.Knockback = 0.f;
	Data.MaxKnockBack = 3.f;
	Data.XP = 3;

	Super::BeginPlay();

	Renderer->SetAutoSize(1.f, true);
	Renderer->CreateAnimation("Idle", "XLFlower", 0.1f, true, 0, 2);
	Renderer->CreateAnimation("Death", "XLFlower", 0.05f, false, 3, 14);
	Renderer->SetOrder(ERenderOrder::SmallFlower);
	Renderer->ChangeAnimation("Idle");

	Collider->SetScale(FVector(50.f, 50.f, 10.f));

}

void ASmallFlower::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}

