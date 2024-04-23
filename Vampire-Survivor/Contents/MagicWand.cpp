#include "PreCompile.h"
#include "MagicWand.h"
#include "MagicWandCenter.h"

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
}

void UMagicWand::DataInit()
{
	Data.Level = 1;
	Data.Amount = 1;
	Data.Penetration = 0;
	Data.Damage = 10.f;
	Data.Speed = 100.f;
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
		Data.Speed = 100.f;
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
	}
}

void UMagicWand::SpawnCenter()
{
	GetWorld()->SpawnActor<AMagicWandCenter>("Center");
}
