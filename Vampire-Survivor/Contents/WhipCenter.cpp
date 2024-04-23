#include "PreCompile.h"
#include "WhipCenter.h"
#include "Whip.h"
#include "WhipUnit.h"

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
	WhipSpawnLogic();
}

void AWhipCenter::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}

void AWhipCenter::WhipSpawnLogic()
{
	if (Data.Amount <= 1)
	{
		std::shared_ptr<AWhipUnit> FirstWhip = GetWorld()->SpawnActor<AWhipUnit>("Center");
		Destroy();
	}
	else
	{
		std::shared_ptr<AWhipUnit> FirstWhip = GetWorld()->SpawnActor<AWhipUnit>("Center");
		DelayCallBack(SecondTerm, [=]
			{
				std::shared_ptr<AWhipUnit> SecondWhip = GetWorld()->SpawnActor<AWhipUnit>("Center");
				SecondWhip->SetActorRotation(FVector(0.f, 0.f, 180.f));
				Destroy();
			});
	}
	
}

