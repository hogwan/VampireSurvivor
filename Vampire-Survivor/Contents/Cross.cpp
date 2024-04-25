#include "PreCompile.h"
#include "Cross.h"
#include "CrossCenter.h"
#include "Player.h"
FWeaponData UCross::Data = { 0, };
UCross::UCross()
{
}

UCross::~UCross()
{
}

void UCross::BeginPlay()
{
	Super::BeginPlay();
	SpawnCenter();
}

void UCross::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	RemainTime -= _DeltaTime;
	if (RemainTime < 0.f)
	{
		RemainTime = Data.Cooldown;
		SpawnCenter();
	}
}

void UCross::DataInit()
{
	Type = EWeapon::Cross;

	Data.Level = 1;
	OriginalData.Amount = 1;
	OriginalData.Penetration = 0;
	OriginalData.Damage = 5.f;
	OriginalData.Speed = 300.f;
	OriginalData.Duration = 0.f;
	OriginalData.Area = 1.f;
	OriginalData.Cooldown = 2.f;
	OriginalData.KnockbackPower = 100.f;

	RemainTime = OriginalData.Cooldown;
}

void UCross::LevelUp()
{
	int Level = ++Data.Level;
	switch (Level)
	{
	case 1:
		Data.Level = 1;
		OriginalData.Amount = 1;
		OriginalData.Penetration = 0;
		OriginalData.Damage = 5.f;
		OriginalData.Speed = 300.f;
		OriginalData.Duration = 0.f;
		OriginalData.Area = 1.f;
		OriginalData.Cooldown = 2.f;
		OriginalData.KnockbackPower = 100.f;
		break;
	case 2:
		OriginalData.Damage += 10;
		break;
	case 3:
		OriginalData.Speed *= 1.25f;
		OriginalData.Area *= 1.1f;
		break;
	case 4:
		++OriginalData.Amount;
		break;
	case 5:
		OriginalData.Damage += 10.f;
		break;
	case 6:
		OriginalData.Speed *= 1.25f;
		OriginalData.Area *= 1.1f;
		break;
	case 7:
		++OriginalData.Amount;
		break;
	case 8:
		OriginalData.Damage += 10.f;
		break;
	default:
		break;
	}
}

void UCross::SpawnCenter()
{
	GetWorld()->SpawnActor<ACrossCenter>("Center");
}

void UCross::ApplyStatus(FPlayerData _Data)
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
