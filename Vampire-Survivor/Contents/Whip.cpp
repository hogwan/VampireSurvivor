#include "PreCompile.h"
#include "Whip.h"
#include "WhipCenter.h";

FWeaponData UWhip::Data = { 0, };

UWhip::UWhip() 
{
}

UWhip::~UWhip() 
{
}

void UWhip::BeginPlay()
{
	Super::BeginPlay();
	DataInit();
	SpawnCenter();
}

void UWhip::Tick(float _DeltaTime)
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

void UWhip::DataInit()
{
	Data.Level = 1;
	Data.Amount = 1;
	Data.Penetration = 1;
	Data.Damage = 10.f;
	Data.Speed = 500.f;
	Data.Duration = 0.f;
	Data.Area = 1.f;
	Data.Cooldown = 1.35f;
	Data.KnockbackPower = 100.f;

	RemainTime = Data.Cooldown;
}

void UWhip::LevelUp()
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
		Data.Area = 100.f;
		Data.Cooldown = 1.35f;
		Data.KnockbackPower = 100.f;
		break;
	case 2:
		++Data.Amount;
		break;
	case 3:
		Data.Damage += 5.f;
		break;
	case 4:
		Data.Damage += 5.f;
		Data.Area *= 1.1f;
		break;
	case 5:
		Data.Damage += 5.f;
		break;
	case 6:
		Data.Damage += 5.f;
		Data.Area *= 1.1f;
		break;
	case 7:
		Data.Damage += 5.f;
		break;
	case 8:
		Data.Damage += 5.f;
		break;
	default:
		break;
	}

	SpawnCenter();
}

void UWhip::SpawnCenter()
{
	GetWorld()->SpawnActor<AWhipCenter>("Center");
}

