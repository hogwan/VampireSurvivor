#include "PreCompile.h"
#include "Axe.h"
#include "AxeCenter.h"

FWeaponData UAxe::Data = { 0, };

UAxe::UAxe()
{
}

UAxe::~UAxe()
{
}

void UAxe::BeginPlay()
{
	Super::BeginPlay();
	DataInit();
	SpawnCenter();
}

void UAxe::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	RemainTime -= _DeltaTime;
	if (RemainTime < 0.f)
	{
		RemainTime = Data.Cooldown;
		SpawnCenter();
	}

	if (UEngineInput::IsDown('l') || UEngineInput::IsDown('L'))
	{
		LevelUp();
	}
}

void UAxe::DataInit()
{
	Data.Level = 1;
	Data.Amount = 1;
	Data.Penetration = 3;
	Data.Damage = 20.f;
	Data.Speed = 200.f;
	Data.Duration = 0.f;
	Data.Area = 50.f;
	Data.Cooldown = 4.f;
	Data.KnockbackPower = 100.f;

	RemainTime = Data.Cooldown;
}

void UAxe::LevelUp()
{
	int Level = ++Data.Level;
	switch (Level)
	{
	case 1:
		Data.Level = 1;
		Data.Amount = 1;
		Data.Penetration = 3;
		Data.Damage = 20.f;
		Data.Speed = 200.f;
		Data.Duration = 0.f;
		Data.Area = 50.f;
		Data.Cooldown = 4.f;
		Data.KnockbackPower = 100.f;
		break;
	case 2:
		++Data.Amount;
		break;
	case 3:
		Data.Damage += 20.f;
		break;
	case 4:
		Data.Penetration += 2;
		break;
	case 5:
		++Data.Amount;
		break;
	case 6:
		Data.Damage += 20.f;
		break;
	case 7:
		Data.Penetration += 2;
		break;
	case 8:
		Data.Damage += 20.f;
		break;
	default:
		break;
	}
}

void UAxe::SpawnCenter()
{
	GetWorld()->SpawnActor<AAxeCenter>("Center");
}
