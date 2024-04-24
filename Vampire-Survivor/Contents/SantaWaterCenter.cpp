#include "PreCompile.h"
#include "SantaWaterCenter.h"
#include "SantaWater.h"
#include "SantaWaterUnit.h"

ASantaWaterCenter::ASantaWaterCenter() 
{

}

ASantaWaterCenter::~ASantaWaterCenter() 
{
}

void ASantaWaterCenter::BeginPlay()
{
	Super::BeginPlay();
	SetData(USantaWater::Data);
	
}

void ASantaWaterCenter::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	SpawnLogic();
}



void ASantaWaterCenter::SpawnLogic()
{
	FVector CurPos = GetActorLocation();
	std::shared_ptr<ASantaWaterUnit> SantaWaterUnit = GetWorld()->SpawnActor<ASantaWaterUnit>("SantaWaterUnit");

	SantaWaterUnit->SetActorLocation(TargetPos + FVector::Up * 1000.f);
	SantaWaterUnit->SetTargetPos(TargetPos);

	Destroy();
}

