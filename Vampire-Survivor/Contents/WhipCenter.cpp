#include "PreCompile.h"
#include "WhipCenter.h"
#include "Whip.h"

AWhipCenter::AWhipCenter() 
{
}

AWhipCenter::~AWhipCenter() 
{
}

void AWhipCenter::BeginPlay()
{
	Super::BeginPlay();
	SetData(UWhip::Data);
}

void AWhipCenter::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}

