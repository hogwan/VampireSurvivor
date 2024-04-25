#include "PreCompile.h"
#include "KnifeUnit.h"
#include "KnifeCenter.h"
#include "Player.h"
#include "Knife.h"

AKnifeCenter::AKnifeCenter() 
{
}

AKnifeCenter::~AKnifeCenter() 
{
}

void AKnifeCenter::BeginPlay()
{
	Super::BeginPlay();
	SetData(UKnife::Data);
	RemainKnifeCount = Data.Amount;
}

void AKnifeCenter::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	if (RemainKnifeCount <= 0)
	{
		Destroy();
	}

	SpawnLogic(_DeltaTime);
}

void AKnifeCenter::SpawnLogic(float _DeltaTime)
{

	RemainTime -= _DeltaTime;
	if (RemainTime < 0.f)
	{
		RemainTime = SpawnInterval;
		FVector PlayerDir = UContentsValue::Player->GetPlayerDir();
		if (PlayerDir.X > 0)
		{
			SetActorRotation(FVector(0.f, 0.f, PlayerDir.Y * 90.f));	
		}
		else
		{
			SetActorRotation(FVector(0.f, 0.f, 180.f -(PlayerDir.Y * 90.f)));
		}
		FVector UpVector = GetActorUpVector();

		std::shared_ptr<AKnifeUnit> Knife =GetWorld()->SpawnActor<AKnifeUnit>("AKnifeUnit");
		--RemainKnifeCount;

		if (UpSpawn)
		{
			Knife->SetActorLocation(GetActorLocation() + UpVector * Offset);
		}
		else
		{
			Knife->SetActorLocation(GetActorLocation() - UpVector * Offset);
		}
		if (PlayerDir.Size3D() < 0.001f)
		{
			PlayerDir = FVector::Right;
		}
		Knife->SetMoveVector(PlayerDir * Data.Speed);

		if (PlayerDir.X >= 0)
		{
			Knife->SetActorRotation(FVector(0.f, 0.f, PlayerDir.Y * 90.f));
		}
		else
		{
			Knife->SetActorRotation(FVector(0.f, 0.f, 180 - (PlayerDir.Y * 90.f)));
		}

		UpSpawn = !UpSpawn;
	}
}

