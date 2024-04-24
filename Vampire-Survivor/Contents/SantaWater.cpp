#include "PreCompile.h"
#include "SantaWater.h"
#include "SantaWaterCenter.h"
#include "Player.h"

FWeaponData USantaWater::Data = { 0, };

USantaWater::USantaWater() 
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("Root");
	TargetPoint = CreateDefaultSubObject<UDefaultSceneComponent>("TargetPoint");
	TargetPoint->SetupAttachment(Root);

	SetRoot(Root);
}

USantaWater::~USantaWater() 
{
}

void USantaWater::BeginPlay()
{
	Super::BeginPlay();
	DataInit();
	RemainCount = Data.Amount;
	
}

void USantaWater::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	SetActorLocation(UContentsValue::Player->GetActorLocation());
	TargetPoint->SetPosition(FVector::Right * 300.f);

	RotAround(_DeltaTime);

	if (IsLoop == false)
	{
		RemainTime -= _DeltaTime;
		if (RemainTime < 0.f)
		{
			RemainTime = Data.Cooldown;
			IsLoop = true;
		}
	}

	SpawnLoop(_DeltaTime);

	if (UEngineInput::IsDown('l') || UEngineInput::IsDown('L'))
	{
		LevelUp();
	}
}

void USantaWater::DataInit()
{
	Data.Level = 1;
	Data.Amount = 1;
	Data.Penetration = 0;
	Data.Damage = 10.f;
	Data.Speed = 0.f;
	Data.Duration = 2.f;
	Data.Area = 1.f;
	Data.Cooldown = 2.f;
	Data.KnockbackPower = 100.f;

	RemainTime = Data.Cooldown;
}

void USantaWater::LevelUp()
{
	int Level = ++Data.Level;
	switch (Level)
	{
	case 1:
		Data.Level = 1;
		Data.Amount = 1;
		Data.Penetration = 0;
		Data.Damage = 10.f;
		Data.Speed = 0.f;
		Data.Duration = 2.f;
		Data.Area = 1.f;
		Data.Cooldown = 2.f;
		Data.KnockbackPower = 100.f;
		break;
	case 2:
		++Data.Amount;
		Data.Area *= 1.2f;
		break;
	case 3:
		Data.Damage += 10.f;
		Data.Duration += 0.5f;
		break;
	case 4:
		++Data.Amount;
		Data.Area *= 1.2f;
		break;
	case 5:
		Data.Damage += 10.f;
		Data.Duration += 0.3f;
		break;
	case 6:
		++Data.Amount;
		Data.Area *= 1.2f;
		break;
	case 7:
		Data.Damage += 10.f;
		Data.Duration += 0.3f;
		break;
	case 8:
		Data.Damage += 5.f;
		Data.Duration += 0.3f;
		break;
	default:
		break;
	}
}

void USantaWater::RotAround(float _DeltaTime)
{
	AddActorRotation(FVector(0.f,0.f,RotSpeed * _DeltaTime));
} 

void USantaWater::SpawnCenter()
{
	std::shared_ptr<ASantaWaterCenter> SantaWaterCenter = GetWorld()->SpawnActor<ASantaWaterCenter>("Center");
	FVector TargetPos = TargetPoint->GetWorldPosition();
	SantaWaterCenter->SetTargetPos(TargetPoint->GetWorldPosition());
	--RemainCount;
}

void USantaWater::SpawnLoop(float _DeltaTime)
{
	if (IsLoop)
	{
		LoopRemainTime -= _DeltaTime;
		if (LoopRemainTime < 0.f)
		{
			LoopRemainTime = LoopTime;
			SpawnCenter();
		}

		if (RemainCount <= 0)
		{
			RemainCount = Data.Amount;
			IsLoop = false;
		}
	}

}
