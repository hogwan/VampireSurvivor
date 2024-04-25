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
	DataInit();
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
	Data.Amount = 1;
	Data.Penetration = 1;
	Data.Damage = 10.f;
	Data.Speed = 300.f;
	Data.Duration = 0.f;
	Data.Area = 0.f;
	Data.Cooldown = 1.2f;
	Data.KnockbackPower = 100.f;

	RemainTime = Data.Cooldown;
}

void UMagicWand::LevelUp()
{
	int Level = ++Data.Level;
	switch (Level)
	{
	case 1:
		Data.Level = 1;
		Data.Amount = 1;
		Data.Penetration = 1;
		Data.Damage = 10.f;
		Data.Speed = 500.f;
		Data.Duration = 0.f;
		Data.Area = 0.f;
		Data.Cooldown = 1.2f;
		Data.KnockbackPower = 100.f;
		break;
	case 2:
		++Data.Amount;
		break;
	case 3:
		Data.Cooldown -= 0.2f;
		break;
	case 4:
		++Data.Amount;
		break;
	case 5:
		Data.Damage += 10.f;
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

	Data.Amount = TempData.Amount;
	Data.Damage = TempData.Damage;
	Data.Speed = TempData.Speed;
	Data.Duration = TempData.Duration;
	Data.Area = TempData.Area;
	Data.Cooldown = TempData.Cooldown;
}
