#include "PreCompile.h"
#include "KnifeUnit.h"
#include "KnifeCenter.h"
#include "Player.h"

AKnifeCenter::AKnifeCenter() 
{
}

AKnifeCenter::~AKnifeCenter() 
{
}

void AKnifeCenter::BeginPlay()
{
	Super::BeginPlay();
}

void AKnifeCenter::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	SpawnLogic(_DeltaTime);
}

void AKnifeCenter::SpawnLogic(float _DeltaTime)
{
	RemainTime -= _DeltaTime;
	if (RemainTime < 0.f)
	{
		std::shared_ptr<AKnifeUnit> Knife =GetWorld()->SpawnActor<AKnifeUnit>("AKnifeUnit");

		if (UpSpawn)
		{
			
		}

		UpSpawn = !UpSpawn;
	}
}

