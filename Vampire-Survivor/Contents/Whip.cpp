#include "PreCompile.h"
#include "Whip.h"
#include "WhipCenter.h"
#include "Player.h"

FWeaponData UWhip::Data = { "좌우로 적을 관통해 공격합니다.",0,};

UWhip::UWhip() 
{
}

UWhip::~UWhip() 
{
}

void UWhip::BeginPlay()
{
	Super::BeginPlay();
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
}

void UWhip::DataInit()
{
	Type = EWeapon::Whip;

	Data.Level = 1;
	OriginalData.Amount = 1;
	OriginalData.Penetration = 1;
	OriginalData.Damage = 10.f;
	OriginalData.Speed = 500.f;
	OriginalData.Duration = 0.f;
	OriginalData.Area = 1.f;
	OriginalData.Cooldown = 1.35f;
	OriginalData.KnockbackPower = 1000.f;
	OriginalData.ExplainText = "투사체 1 증가";

	RemainTime = OriginalData.Cooldown;
}

void UWhip::LevelUp()
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
		OriginalData.Area = 100.f;
		OriginalData.Cooldown = 1.35f;
		OriginalData.KnockbackPower = 1000.f;
		OriginalData.ExplainText = "투사체 1 증가";
		break;
	case 2:
		++OriginalData.Amount;
		OriginalData.ExplainText = "공격력 5 증가";
		break;
	case 3:
		OriginalData.Damage += 5.f;
		OriginalData.ExplainText = "공격력 5 증가, 공격범위 10% 증가";
		break;
	case 4:
		OriginalData.Damage += 5.f;
		OriginalData.Area *= 1.1f;
		OriginalData.ExplainText = "공격력 5 증가";
		break;
	case 5:
		OriginalData.Damage += 5.f;
		OriginalData.ExplainText = "공격력 5 증가, 공격범위 10% 증가";
		break;
	case 6:
		OriginalData.Damage += 5.f;
		OriginalData.Area *= 1.1f;
		OriginalData.ExplainText = "공격력 5 증가";
		break;
	case 7:
		OriginalData.Damage += 5.f;
		OriginalData.ExplainText = "공격력 5 증가";
		break;
	case 8:
		OriginalData.Damage += 5.f;
		OriginalData.ExplainText = "최대레벨 증가";
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

void UWhip::ApplyStatus(FPlayerData _Data)
{
	FWeaponData TempData;

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
	Data.KnockbackPower = OriginalData.KnockbackPower;
	Data.ExplainText = OriginalData.ExplainText;
	RemainTime = Data.Cooldown;
}

