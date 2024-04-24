#include "PreCompile.h"
#include "SantaWaterCenter.h"
#include "SantaWater.h"
#include "SantaWaterUnit.h"

ASantaWaterCenter::ASantaWaterCenter() 
{
	TargetPoint = CreateDefaultSubObject<UDefaultSceneComponent>("Target");

	TargetPoint->SetupAttachment(Root);
}

ASantaWaterCenter::~ASantaWaterCenter() 
{
}

void ASantaWaterCenter::BeginPlay()
{
	Super::BeginPlay();
	SetData(USantaWater::Data);
	RemainCount = Data.Amount;
	RemainTime = SpawnTerm;
	TargetPoint->SetPosition(FVector::Right * Data.Area);
}

void ASantaWaterCenter::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	if (RemainCount <= 0)
	{
		Destroy();
	}

	RotAround(_DeltaTime);

	RemainTime -= _DeltaTime;
	if (RemainTime < 0.f)
	{
		RemainTime = SpawnTerm;
		SpawnLogic();
	}
}

void ASantaWaterCenter::RotAround(float _DeltaTime)
{
	SetActorRotation(FVector(0.f, 0.f, RotSpeed * _DeltaTime));
}

void ASantaWaterCenter::SpawnLogic()
{
	std::shared_ptr<ASantaWaterUnit> SantaWaterUnit = GetWorld()->SpawnActor<ASantaWaterUnit>("SantaWaterUnit");

	SantaWaterUnit->SetActorLocation(TargetPoint->GetWorldPosition() + FVector::Up * 1300.f);
	SantaWaterUnit->SetTargetPos(TargetPoint->GetWorldPosition());
}

