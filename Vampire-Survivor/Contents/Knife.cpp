#include "PreCompile.h"
#include "Knife.h"
#include "KnifeCenter.h"
#include "player.h"

FWeaponData UKnife::Data = { 0, };

UKnife::UKnife() 
{
}

UKnife::~UKnife() 
{
}

void UKnife::BeginPlay()
{
	Super::BeginPlay();
	DataInit();
	SpawnCenter();
}

void UKnife::Tick(float _DeltaTime)
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

void UKnife::DataInit()
{
	Type = EWeapon::Knife;

	Data.Level = 1;
	Data.Amount = 1;
	Data.Penetration = 1;
	Data.Damage = 6.5f;
	Data.Speed = 500.f;
	Data.Duration = 1.f;
	Data.Area = 0.f;
	Data.Cooldown = 1.0f;
	Data.KnockbackPower = 100.f;

	RemainTime = Data.Cooldown;
}

void UKnife::LevelUp()
{
	int Level = ++Data.Level;
	switch (Level)
	{
	case 1:
		Data.Level = 1;
		Data.Amount = 1;
		Data.Penetration = 1;
		Data.Damage = 6.5f;
		Data.Speed = 500.f;
		Data.Duration = 1.f;
		Data.Area = 0.f;
		Data.Cooldown = 1.0f;
		Data.KnockbackPower = 100.f;
		break;
	case 2:
		++Data.Amount;
		break;
	case 3:
		++Data.Amount;
		Data.Damage += 5.f;
		break;
	case 4:
		++Data.Amount;
		break;
	case 5:
		++Data.Penetration;
		break;
	case 6:
		++Data.Amount;
		break;
	case 7:
		++Data.Penetration;
		Data.Damage += 5.f;
		break;
	case 8:
		++Data.Penetration;
		break;
	default:
		break;
	}
}

void UKnife::SpawnCenter()
{
	GetWorld()->SpawnActor<AKnifeCenter>("Center");
}

void UKnife::ApplyStatus(FPlayerData _Data)
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
