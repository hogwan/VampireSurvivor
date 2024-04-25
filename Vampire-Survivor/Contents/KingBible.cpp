#include "PreCompile.h"
#include "KingBible.h"
#include "KingBibleCenter.h"
#include "Bat1.h"
#include "Player.h"

FWeaponData UKingBible::Data = { 0, };

UKingBible::UKingBible()
{
}

UKingBible::~UKingBible()
{
}

void UKingBible::BeginPlay()
{
	Super::BeginPlay();
	SpawnCenter();
}

void UKingBible::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	if (UEngineInput::IsDown('l') || UEngineInput::IsDown('L'))
	{
		LevelUp();
	}

	RemainTime -= _DeltaTime;
	if (RemainTime < 0.f)
	{
		RemainTime = Data.Cooldown + Data.Duration;
		SpawnCenter();
	}

}

void UKingBible::DataInit()
{
	Type = EWeapon::KingBible;

	Data.Level = 1;
	OriginalData.Amount = 1;
	OriginalData.Penetration = -1;
	OriginalData.Damage = 10.f;
	OriginalData.Speed = 100.f;
	OriginalData.Duration = 3.f;
	OriginalData.Area = 100.f;
	OriginalData.Cooldown = 3.f;
	OriginalData.KnockbackPower = 100.f;

	RemainTime = Data.Cooldown + OriginalData.Duration;
}

void UKingBible::LevelUp()
{
	int Level = ++Data.Level;

	switch (Level)
	{
	case 1:
		Data.Level = 1;
		OriginalData.Amount = 1;
		OriginalData.Penetration = -1;
		OriginalData.Damage = 10.f;
		OriginalData.Speed = 100.f;
		OriginalData.Duration = 3.f;
		OriginalData.Area = 100.f;
		OriginalData.Cooldown = 3.f;
		OriginalData.KnockbackPower = 100.f;
		break;
	case 2:
		++OriginalData.Amount;
		break;
	case 3:
		OriginalData.Speed = Data.Speed * 1.3f;
		OriginalData.Area = Data.Area * 1.25f;
		break;
	case 4:
		OriginalData.Duration += 0.5f;
		OriginalData.Damage += 10.f;
		break;
	case 5:
		++OriginalData.Amount;
		break;
	case 6:
		OriginalData.Speed = Data.Speed * 1.3f;
		OriginalData.Area = Data.Area * 1.25f;
		break;
	case 7:
		OriginalData.Duration += 0.5f;
		OriginalData.Damage += 10.f;
		break;
	case 8:
		++OriginalData.Amount;
		break;
	default:
		break;
	}

	SpawnCenter();
}

void UKingBible::SpawnCenter()
{
	GetWorld()->SpawnActor<AKingBibleCenter>("Center");
}

void UKingBible::ApplyStatus(FPlayerData _Data)
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
