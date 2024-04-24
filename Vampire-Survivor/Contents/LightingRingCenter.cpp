#include "PreCompile.h"
#include "LightingRingCenter.h"
#include "LightingRing.h"
#include "LightingRingUnit.h"
#include "Player.h"
#include "Enemy.h"

ALightingRingCenter::ALightingRingCenter()
{
}

ALightingRingCenter::~ALightingRingCenter()
{
}

void ALightingRingCenter::BeginPlay()
{
	Super::BeginPlay();
	SetData(ULightingRing::Data);
	RemainCount = Data.Amount;
}

void ALightingRingCenter::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	if (RemainCount <= 0)
	{
		Destroy();
	}

	RemainTime -= _DeltaTime;
	if (RemainTime < 0.f)
	{
		RemainTime = Term;
		SpawnThunderLogic();
	}
}

void ALightingRingCenter::SpawnThunderLogic()
{
	AEnemy* RandomTarget = UContentsValue::Player->GetRandomEnemy();
	if (RandomTarget == nullptr)
	{
		--RemainCount;
		return;
	}

	std::shared_ptr<ALightingRingUnit> LightingUnit = GetWorld()->SpawnActor<ALightingRingUnit>("LightingRingUnit");
	LightingUnit->SetActorLocation(RandomTarget->GetActorLocation());

	--RemainCount;
}
