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
	UnitSpawnLogic();
}

void AWhipCenter::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}

void AWhipCenter::UnitSpawnLogic()
{
	if (Data.Amount <= 1)
	{
		UEngineSound::SoundPlay("Whiplash.wav");
		std::shared_ptr<AWhipUnit> FirstWhip = GetWorld()->SpawnActor<AWhipUnit>("Center");
		Destroy();
	}
	else
	{
		UEngineSound::SoundPlay("Whiplash.wav");
		std::shared_ptr<AWhipUnit> FirstWhip = GetWorld()->SpawnActor<AWhipUnit>("Center");
		DelayCallBack(SecondTerm, [=]
			{
				UEngineSound::SoundPlay("Whiplash.wav");
				std::shared_ptr<AWhipUnit> SecondWhip = GetWorld()->SpawnActor<AWhipUnit>("Center");
				SecondWhip->SetActorRotation(FVector(0.f, 0.f, 180.f));
				Destroy();
			});
	}
	
}

