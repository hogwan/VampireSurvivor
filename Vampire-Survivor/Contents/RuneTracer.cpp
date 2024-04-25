#include "PreCompile.h"
#include "RuneTracer.h"
#include "RuneTracerCenter.h"
#include "player.h"

FWeaponData URuneTracer::Data = { 0, };

URuneTracer::URuneTracer()
{
}

URuneTracer::~URuneTracer()
{
}

void URuneTracer::BeginPlay()
{
	Super::BeginPlay();
	DataInit();
	SpawnCenter();
}

void URuneTracer::Tick(float _DeltaTime)
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

void URuneTracer::DataInit()
{
	Type = EWeapon::RuneTracer;

	Data.Level = 1;
	Data.Amount = 1;
	Data.Penetration = 1;
	Data.Damage = 10.f;
	Data.Speed = 300.f;
	Data.Duration = 2.25f;
	Data.Area = 1.f;
	Data.Cooldown = 3.f;
	Data.KnockbackPower = 100.f;

	RemainTime = Data.Cooldown;
}

void URuneTracer::LevelUp()
{
	int Level = ++Data.Level;
	switch (Level)
	{
	case 1:
		Data.Level = 1;
		Data.Amount = 1;
		Data.Penetration = 1;
		Data.Damage = 10.f;
		Data.Speed = 300.f;
		Data.Duration = 2.25f;
		Data.Area = 1.f;
		Data.Cooldown = 3.f;
		Data.KnockbackPower = 100.f;
		break;
	case 2:
		Data.Damage += 5.f;
		Data.Speed *= 1.2f;
		break;
	case 3:
		Data.Damage += 5.f;
		Data.Duration += 0.3f;
		break;
	case 4:
		++Data.Amount;
		break;
	case 5:
		Data.Damage += 5.f;
		Data.Speed *= 1.2f;
		break;
	case 6:
		Data.Damage += 5.f;
		Data.Duration += 0.3f;
		break;
	case 7:
		++Data.Amount;
		break;
	case 8:
		Data.Duration += 0.5f;
		break;
	default:
		break;
	}
}

void URuneTracer::SpawnCenter()
{
	GetWorld()->SpawnActor<ARuneTracerCenter>("Center");
}

void URuneTracer::ApplyStatus(FPlayerData _Data)
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
