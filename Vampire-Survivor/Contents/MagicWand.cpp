#include "PreCompile.h"
#include "MagicWand.h"
#include "MagicWandCenter.h"
#include "Player.h"

FWeaponData UMagicWand::Data = { 0, };

UMagicWand::UMagicWand() 
{
}

UMagicWand::~UMagicWand() 
{
}

void UMagicWand::BeginPlay()
{
	Super::BeginPlay();
	SpawnCenter();
}

void UMagicWand::Tick(float _DeltaTime)
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

void UMagicWand::DataInit()
{
	Type = EWeapon::MagicWand;

	Data.Level = 1;
	OriginalData.Amount = 1;
	OriginalData.Penetration = 1;
	OriginalData.Damage = 10.f;
	OriginalData.Speed = 300.f;
	OriginalData.Duration = 0.f;
	OriginalData.Area = 0.f;
	OriginalData.Cooldown = 1.2f;
	OriginalData.KnockbackPower = 100.f;

	RemainTime = Data.Cooldown;
}

void UMagicWand::LevelUp()
{
	int Level = ++Data.Level;
	switch (Level)
	{
	case 1:
		Data.Level = 1;
		OriginalData.Amount = 1;
		OriginalData.Penetration = 1;
		OriginalData.Damage = 10.f;
		OriginalData.Speed = 500.f;
		OriginalData.Duration = 0.f;
		OriginalData.Area = 0.f;
		OriginalData.Cooldown = 1.2f;
		OriginalData.KnockbackPower = 100.f;
		break;
	case 2:
		++OriginalData.Amount;
		break;
	case 3:
		OriginalData.Cooldown -= 0.2f;
		break;
	case 4:
		++OriginalData.Amount;
		break;
	case 5:
		OriginalData.Damage += 10.f;
		break;
	case 6:
		++OriginalData.Amount;
		break;
	case 7:
		++OriginalData.Penetration;
		break;
	case 8:
		OriginalData.Damage += 10.f;
		break;
	default:
		break;
	}
}

void UMagicWand::SpawnCenter()
{
	GetWorld()->SpawnActor<AMagicWandCenter>("Center");
}

void UMagicWand::ApplyStatus(FPlayerData _Data)
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
