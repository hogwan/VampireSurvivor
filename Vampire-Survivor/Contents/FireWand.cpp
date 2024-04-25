#include "PreCompile.h"
#include "FireWand.h"
#include "FireWandCenter.h"
#include "Player.h"

FWeaponData UFireWand::Data = { 0, };

UFireWand::UFireWand()
{
}

UFireWand::~UFireWand()
{
}

void UFireWand::BeginPlay()
{
	Super::BeginPlay();
	SpawnCenter();
}

void UFireWand::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	RemainTime -= _DeltaTime;
	if (RemainTime < 0.f)
	{
		RemainTime = Data.Cooldown;
		SpawnCenter();
	}
}

void UFireWand::DataInit()
{
	Type = EWeapon::FireWand;

	Data.Level = 1;
	OriginalData.Amount = 3;
	OriginalData.Penetration = 1;
	OriginalData.Damage = 20.f;
	OriginalData.Speed = 100.f;
	OriginalData.Duration = 2.f;
	OriginalData.Area = 1.f;
	OriginalData.Cooldown = 3.f;
	OriginalData.KnockbackPower = 100.f;

	RemainTime = OriginalData.Cooldown;
}

void UFireWand::LevelUp()
{
	int Level = ++Data.Level;
	switch (Level)
	{
	case 1:
		Data.Level = 1;
		OriginalData.Amount = 3;
		OriginalData.Penetration = 1;
		OriginalData.Damage = 20.f;
		OriginalData.Speed = 100.f;
		OriginalData.Duration = 2.f;
		OriginalData.Area = 1.f;
		OriginalData.Cooldown = 3.f;
		OriginalData.KnockbackPower = 100.f;
		break;
	case 2:
		OriginalData.Damage += 10.f;
		break;
	case 3:
		OriginalData.Damage += 10.f;
		OriginalData.Speed *= 1.2f;
		break;
	case 4:
		OriginalData.Damage += 10.f;
		break;
	case 5:
		OriginalData.Damage += 10.f;
		OriginalData.Speed *= 1.2f;
		break;
	case 6:
		OriginalData.Damage += 10.f;
		break;
	case 7:
		OriginalData.Damage += 10.f;
		OriginalData.Speed *= 1.2f;
		break;
	case 8:
		OriginalData.Damage += 10.f;
		break;
	default:
		break;
	}
}

void UFireWand::SpawnCenter()
{
	GetWorld()->SpawnActor<AFireWandCenter>("Center");
}

void UFireWand::ApplyStatus(FPlayerData _Data)
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
