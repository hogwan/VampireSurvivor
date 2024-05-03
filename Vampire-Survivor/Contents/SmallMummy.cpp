#include "PreCompile.h"
#include "SmallMummy.h"

ASmallMummy::ASmallMummy() 
{
}

ASmallMummy::~ASmallMummy() 
{
}

void ASmallMummy::BeginPlay()
{
	Data.MaxHp = 10.f;
	Data.Speed = 80.f;
	Data.Power = 5.f;
	Data.Knockback = 0.f;
	Data.MaxKnockBack = 3.f;
	Data.XP = 3.f;
	Super::BeginPlay();

	Renderer->SetAutoSize(1.0f, true);
	Renderer->CreateAnimation("Idle", "XLMummy", 0.1f, true, 0, 2);
	Renderer->CreateAnimation("Death", "XLMummy", 0.05f, false, 3, 14);
	Renderer->SetOrder(ERenderOrder::Monster);
	Renderer->ChangeAnimation("Idle");

	Collider->SetScale(FVector(20.f, 20.f, 10.f));

}

void ASmallMummy::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}

