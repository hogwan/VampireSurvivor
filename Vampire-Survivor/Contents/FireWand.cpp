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
	DataInit();
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

	if (UEngineInput::IsDown('l') || UEngineInput::IsDown('L'))
	{
		LevelUp();
	}
}

void UFireWand::DataInit()
{
	Type = EWeapon::FireWand;

	Data.Level = 1;
	Data.Amount = 3;
	Data.Penetration = 1;
	Data.Damage = 20.f;
	Data.Speed = 100.f;
	Data.Duration = 2.f;
	Data.Area = 1.f;
	Data.Cooldown = 3.f;
	Data.KnockbackPower = 100.f;

	RemainTime = Data.Cooldown;
}

void UFireWand::LevelUp()
{
	int Level = ++Data.Level;
	switch (Level)
	{
	case 1:
		Data.Level = 1;
		Data.Amount = 3;
		Data.Penetration = 1;
		Data.Damage = 20.f;
		Data.Speed = 100.f;
		Data.Duration = 2.f;
		Data.Area = 1.f;
		Data.Cooldown = 3.f;
		Data.KnockbackPower = 100.f;
		break;
	case 2:
		Data.Damage += 10.f;
		break;
	case 3:
		Data.Damage += 10.f;
		Data.Speed *= 1.2f;
		break;
	case 4:
		Data.Damage += 10.f;
		break;
	case 5:
		Data.Damage += 10.f;
		Data.Speed *= 1.2f;
		break;
	case 6:
		Data.Damage += 10.f;
		break;
	case 7:
		Data.Damage += 10.f;
		Data.Speed *= 1.2f;
		break;
	case 8:
		Data.Damage += 10.f;
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

	Data.Amount = TempData.Amount;
	Data.Damage = TempData.Damage;
	Data.Speed = TempData.Speed;
	Data.Duration = TempData.Duration;
	Data.Area = TempData.Area;
	Data.Cooldown = TempData.Cooldown;
}
