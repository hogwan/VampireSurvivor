#include "PreCompile.h"
#include "Garlic.h"
#include "GarlicCenter.h"
#include "Player.h"

FWeaponData UGarlic::Data = { 0, };
UGarlic::UGarlic()
{
}

UGarlic::~UGarlic()
{
}

void UGarlic::BeginPlay()
{
	Super::BeginPlay();
	DataInit();
	SpawnCenter();
}

void UGarlic::Tick(float _DeltaTime)
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

void UGarlic::DataInit()
{
	Type = EWeapon::Garlic;

	Data.Level = 1;
	Data.Amount = 0;
	Data.Penetration = 0;
	Data.Damage = 5.f;
	Data.Speed = 0.f;
	Data.Duration = 0.f;
	Data.Area = 1.f;
	Data.Cooldown = 0.5f;
	Data.KnockbackPower = 100.f;

	RemainTime = Data.Cooldown;
}

void UGarlic::LevelUp()
{
	int Level = ++Data.Level;
	switch (Level)
	{
	case 1:
		Data.Level = 1;
		Data.Amount = 0;
		Data.Penetration = 0;
		Data.Damage = 5.f;
		Data.Speed = 0.f;
		Data.Duration = 0.f;
		Data.Area = 1.f;
		Data.Cooldown = 0.5f;
		Data.KnockbackPower = 100.f;
		break;
	case 2:
		Data.Area *= 1.4f;
		Data.Damage += 2.f;
		break;
	case 3:
		Data.Cooldown -= 0.1f;
		Data.Damage += 1.f;
		break;
	case 4:
		Data.Area *= 1.2f;
		Data.Damage += 1.f;
		break;
	case 5:
		Data.Cooldown -= 0.1f;
		Data.Damage += 2.f;
		break;
	case 6:
		Data.Area *= 1.2f;
		Data.Damage += 1.f;
		break;
	case 7:
		Data.Cooldown -= 0.1f;
		Data.Damage += 1.f;
		break;
	case 8:
		Data.Area *= 1.2f;
		Data.Damage += 2.f;
		break;
	default:
		break;
	}
}

void UGarlic::SpawnCenter()
{
	GetWorld()->SpawnActor<AGarlicCenter>("Center");
}

void UGarlic::ApplyStatus(FPlayerData _Data)
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
