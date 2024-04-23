#include "PreCompile.h"
#include "CrossCenter.h"
#include "Cross.h"
#include "CrossUnit.h"
#include "Player.h"
#include "Enemy.h"

ACrossCenter::ACrossCenter()
{
}

ACrossCenter::~ACrossCenter()
{
}

void ACrossCenter::BeginPlay()
{
	Super::BeginPlay();
	SetData(UCross::Data);
	RemainTime = ThrowTerm;
	RemainCount = Data.Amount;
	ThrowForce = Data.Speed;
}

void ACrossCenter::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	if (RemainCount <= 0)
	{
		Destroy();
	}

	RemainTime -= _DeltaTime;
	if (RemainTime < 0.f)
	{
		RemainTime = ThrowTerm;
		ThrowLogic();
	}
}

void ACrossCenter::ThrowLogic()
{
	AEnemy* Target = UContentsValue::Player->GetNearestEnemy();
	if (Target == nullptr)
	{
		--RemainCount;
		return;
	}

	FVector DirVector = Target->GetActorLocation() - GetActorLocation();
	DirVector.Z = 0.f;
	DirVector.Normalize2D();

	std::shared_ptr<ACrossUnit> CrossUnit = GetWorld()->SpawnActor<ACrossUnit>("CrossUnit");
	CrossUnit->SetMoveVector(DirVector * Data.Speed);
	CrossUnit->SetActorLocation(GetActorLocation());
	--RemainCount;
}
