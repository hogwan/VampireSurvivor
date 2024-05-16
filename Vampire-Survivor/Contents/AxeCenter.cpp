#include "PreCompile.h"
#include "AxeCenter.h"
#include "Axe.h"
#include "AxeUnit.h"
#include <EngineBase/EngineRandom.h>

AAxeCenter::AAxeCenter()
{
}

AAxeCenter::~AAxeCenter()
{
}

void AAxeCenter::BeginPlay()
{
	Super::BeginPlay();
	SetData(UAxe::Data);
	RemainTime = ThrowTerm;
	RemainCount = Data.Amount;
	ThrowForce = Data.Speed;
}

void AAxeCenter::Tick(float _DeltaTime)
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

void AAxeCenter::ThrowLogic()
{
	UEngineSound::SoundPlay("ax_01.wav");
	FVector DirVector = FVector::Up;

	float RandomAngle = UEngineRandom::MainRandom.RandomFloat(-Data.Area / 2.f, Data.Area / 2.f);
	DirVector.RotationZToDeg(RandomAngle);

	std::shared_ptr<AAxeUnit> AxeUnit = GetWorld()->SpawnActor<AAxeUnit>("AxeUnit");
	AxeUnit->SetMoveVector(DirVector * ThrowForce);
	AxeUnit->SetActorLocation(GetActorLocation());

	--RemainCount;
}
