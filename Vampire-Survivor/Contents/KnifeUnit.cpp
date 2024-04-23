#include "PreCompile.h"
#include "KnifeUnit.h"

AKnifeUnit::AKnifeUnit() 
{
}

AKnifeUnit::~AKnifeUnit() 
{
}

void AKnifeUnit::BeginPlay()
{
	Super::BeginPlay();

}

void AKnifeUnit::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	AddActorLocation(MoveVector * _DeltaTime);
}

