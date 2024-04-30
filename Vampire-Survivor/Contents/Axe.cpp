#include "PreCompile.h"
#include "Axe.h"
#include "AxeCenter.h"
#include "Player.h"

FWeaponData UAxe::Data = { "피해량이 높고 공격 범위가 넓습니다.",0,};

UAxe::UAxe()
{
}

UAxe::~UAxe()
{
}

void UAxe::BeginPlay()
{
	Super::BeginPlay();
	SpawnCenter();
}

void UAxe::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	RemainTime -= _DeltaTime;
	if (RemainTime < 0.f)
	{
		RemainTime = Data.Cooldown;
		SpawnCenter();
	}
}

void UAxe::DataInit()
{
	Type = EWeapon::Axe;

	Data.Level = 1;
	OriginalData.Amount = 1;
	OriginalData.Penetration = 3;
	OriginalData.Damage = 20.f;
	OriginalData.Speed = 200.f;
	OriginalData.Duration = 0.f;
	OriginalData.Area = 50.f;
	OriginalData.Cooldown = 4.f;
	OriginalData.KnockbackPower = 300.f;
	OriginalData.ExplainText = "투사체 수 1 증가";

	RemainTime = OriginalData.Cooldown;
}

void UAxe::LevelUp()
{
	int Level = ++Data.Level;
	switch (Level)
	{
	case 1:
		Data.Level = 1;
		OriginalData.Amount = 1;
		OriginalData.Penetration = 3;
		OriginalData.Damage = 20.f;
		OriginalData.Speed = 200.f;
		OriginalData.Duration = 0.f;
		OriginalData.Area = 50.f;
		OriginalData.Cooldown = 4.f;
		OriginalData.KnockbackPower = 300.f;
		OriginalData.ExplainText = "투사체 수 1 증가";
		break;
	case 2:
		++OriginalData.Amount;
		OriginalData.ExplainText = "공격력 20 증가";
		break;
	case 3:
		OriginalData.Damage += 20.f;
		OriginalData.ExplainText = "적 2체 추가 관통";
		break;
	case 4:
		OriginalData.Penetration += 2;
		OriginalData.ExplainText = "투사체 수 1 증가";
		break;
	case 5:
		++OriginalData.Amount;
		OriginalData.ExplainText = "공격력 20 증가";
		break;
	case 6:
		OriginalData.Damage += 20.f;
		OriginalData.ExplainText = "적 2체 추가 관통";
		break;
	case 7:
		OriginalData.Penetration += 2;
		OriginalData.ExplainText = "공격력 20 증가";
		break;
	case 8:
		OriginalData.Damage += 20.f;
		OriginalData.ExplainText = "최대 레벨 도달";
		break;
	default:
		break;
	}
}

void UAxe::SpawnCenter()
{
	GetWorld()->SpawnActor<AAxeCenter>("Center");
}

void UAxe::ApplyStatus(FPlayerData _Data)
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
	RemainTime = Data.Cooldown;
}
