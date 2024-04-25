#include "PreCompile.h"
#include "Axe.h"
#include "AxeCenter.h"
#include "Player.h"

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
}

void UAxe::DataInit()
{
	Type = EWeapon::Axe;

	Data.Level = 1;
	OriginalData.Amount = 1;
	OriginalData.Penetration = 3;
	OriginalData.Damage = 20.f;
	OriginalData.Speed = 200.f;
	OriginalData.Duration = 0.f;
	OriginalData.Area = 50.f;
	OriginalData.Cooldown = 4.f;
	OriginalData.KnockbackPower = 100.f;

	RemainTime = OriginalData.Cooldown;
}

void UAxe::LevelUp()
{
	int Level = ++Data.Level;
	switch (Level)
	{
	case 1:
		Data.Level = 1;
		OriginalData.Amount = 1;
		OriginalData.Penetration = 3;
		OriginalData.Damage = 20.f;
		OriginalData.Speed = 200.f;
		OriginalData.Duration = 0.f;
		OriginalData.Area = 50.f;
		OriginalData.Cooldown = 4.f;
		OriginalData.KnockbackPower = 100.f;
		break;
	case 2:
		++OriginalData.Amount;
		break;
	case 3:
		OriginalData.Damage += 20.f;
		break;
	case 4:
		OriginalData.Penetration += 2;
		break;
	case 5:
		++OriginalData.Amount;
		break;
	case 6:
		OriginalData.Damage += 20.f;
		break;
	case 7:
		OriginalData.Penetration += 2;
		break;
	case 8:
		OriginalData.Damage += 20.f;
		break;
	default:
		break;
	}
}

void UAxe::SpawnCenter()
{
	GetWorld()->SpawnActor<AAxeCenter>("Center");
}

void UAxe::ApplyStatus(FPlayerData _Data)
{
	FWeaponData TempData = { 0, };

	TempData.Amount = OriginalData.Amount + _Data.Amount;
	TempData.Damage = OriginalData.Damage * _Data.Might;
	TempData.Speed = OriginalData.Speed * _Data.Speed;
	TempData.Duration = OriginalData.Duration * _Data.Duration;
	TempData.Area = OriginalData.Area * _Data.Area;
	TempData.Cooldown = OriginalData.Cooldown * _Data.Cooldown;
	TempData.Penetration = OriginalData.Penetration;

	Data.Amount = TempData.Amount;
	Data.Damage = TempData.Damage;
	Data.Speed = TempData.Speed;
	Data.Duration = TempData.Duration;
	Data.Area = TempData.Area;
	Data.Cooldown = TempData.Cooldown;
	Data.Penetration = TempData.Penetration;
	RemainTime = Data.Cooldown;
}
