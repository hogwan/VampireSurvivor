#include "PreCompile.h"
#include "GarlicCenter.h"
#include "Garlic.h"
#include "GarlicUnit.h"

AGarlicCenter::AGarlicCenter()
{
}

AGarlicCenter::~AGarlicCenter()
{
}

void AGarlicCenter::BeginPlay()
{
	Super::BeginPlay();
	SetData(UGarlic::Data);
}

void AGarlicCenter::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	SpawnLogic();
}

void AGarlicCenter::SpawnLogic()
{
	std::shared_ptr<AGarlicUnit> GarlicUnit = GetWorld()->SpawnActor<AGarlicUnit>("GarlicUnit");
	GarlicUnit->SetActorLocation(GetActorLocation());
	Destroy();
}
