#include "PreCompile.h"
#include "LightingRing.h"
#include "LightingRingCenter.h"
#include "Player.h"

FWeaponData ULightingRing::Data = { 0, };

ULightingRing::ULightingRing()
{
}

ULightingRing::~ULightingRing()
{
}

void ULightingRing::BeginPlay()
{
	Super::BeginPlay();
	DataInit();
	SpawnCenter();
}

void ULightingRing::Tick(float _DeltaTime)
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

void ULightingRing::DataInit()
{
	Type = EWeapon::LightingRing;

	Data.Level = 1;
	Data.Amount = 2;
	Data.Penetration = 0;
	Data.Damage = 15.f;
	Data.Speed = 300.f;
	Data.Duration = 0.f;
	Data.Area = 1.f;
	Data.Cooldown = 4.5f;
	Data.KnockbackPower = 100.f;

	RemainTime = Data.Cooldown;
}

void ULightingRing::LevelUp()
{
	int Level = ++Data.Level;
	switch (Level)
	{
	case 1:
		Data.Level = 1;
		Data.Amount = 2;
		Data.Penetration = 0;
		Data.Damage = 15.f;
		Data.Speed = 300.f;
		Data.Duration = 0.f;
		Data.Area = 1.f;
		Data.Cooldown = 4.5f;
		Data.KnockbackPower = 100.f;
		break;
	case 2:
		++Data.Amount;
		break;
	case 3:
		Data.Damage += 10.f;
		Data.Area *= 2.f;
		break;
	case 4:
		++Data.Amount;
		break;
	case 5:
		Data.Damage += 20.f;
		Data.Area *= 2.f;
		break;
	case 6:
		++Data.Amount;
		break;
	case 7:
		++Data.Penetration;
		break;
	case 8:
		Data.Damage += 10.f;
		break;
	default:
		break;
	}
}

void ULightingRing::SpawnCenter()
{
	GetWorld()->SpawnActor<ALightingRingCenter>("Center");
}

void ULightingRing::ApplyStatus(FPlayerData _Data)
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
