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
	DataInit();
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

	if (UEngineInput::IsDown('l') || UEngineInput::IsDown('L'))
	{
		LevelUp();
	}
}

void UCross::DataInit()
{
	Type = EWeapon::Cross;

	Data.Level = 1;
	Data.Amount = 1;
	Data.Penetration = 0;
	Data.Damage = 5.f;
	Data.Speed = 300.f;
	Data.Duration = 0.f;
	Data.Area = 1.f;
	Data.Cooldown = 2.f;
	Data.KnockbackPower = 100.f;

	RemainTime = Data.Cooldown;
}

void UCross::LevelUp()
{
	int Level = ++Data.Level;
	switch (Level)
	{
	case 1:
		Data.Level = 1;
		Data.Amount = 1;
		Data.Penetration = 0;
		Data.Damage = 5.f;
		Data.Speed = 300.f;
		Data.Duration = 0.f;
		Data.Area = 1.f;
		Data.Cooldown = 2.f;
		Data.KnockbackPower = 100.f;
		break;
	case 2:
		Data.Damage += 10;
		break;
	case 3:
		Data.Speed *= 1.25f;
		Data.Area *= 1.1f;
		break;
	case 4:
		++Data.Amount;
		break;
	case 5:
		Data.Damage += 10.f;
		break;
	case 6:
		Data.Speed *= 1.25f;
		Data.Area *= 1.1f;
		break;
	case 7:
		++Data.Amount;
		break;
	case 8:
		Data.Damage += 10.f;
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

	Data.Amount = TempData.Amount;
	Data.Damage = TempData.Damage;
	Data.Speed = TempData.Speed;
	Data.Duration = TempData.Duration;
	Data.Area = TempData.Area;
	Data.Cooldown = TempData.Cooldown;
}
