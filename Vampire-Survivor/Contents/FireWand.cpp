#include "PreCompile.h"
#include "FireWand.h"
#include "FireWandCenter.h"
#include "Player.h"

FWeaponData UFireWand::Data = { "무작위 방향을 향해 발사되며 큰 피해를 줍니다.",0, };

UFireWand::UFireWand()
{
}

UFireWand::~UFireWand()
{
}

void UFireWand::BeginPlay()
{
	Super::BeginPlay();
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
}

void UFireWand::DataInit()
{
	Type = EWeapon::FireWand;

	Data.Level = 1;
	OriginalData.Amount = 3;
	OriginalData.Penetration = 1;
	OriginalData.Damage = 20.f;
	OriginalData.Speed = 100.f;
	OriginalData.Duration = 2.f;
	OriginalData.Area = 1.f;
	OriginalData.Cooldown = 3.f;
	OriginalData.KnockbackPower = 200.f;
	OriginalData.ExplainText = "공격력 10 증가";

	RemainTime = OriginalData.Cooldown;
}

void UFireWand::LevelUp()
{
	int Level = ++Data.Level;
	switch (Level)
	{
	case 1:
		Data.Level = 1;
		OriginalData.Amount = 3;
		OriginalData.Penetration = 1;
		OriginalData.Damage = 20.f;
		OriginalData.Speed = 100.f;
		OriginalData.Duration = 2.f;
		OriginalData.Area = 1.f;
		OriginalData.Cooldown = 3.f;
		OriginalData.KnockbackPower = 200.f;
		OriginalData.ExplainText = "공격력 10 증가";
		break;
	case 2:
		OriginalData.Damage += 10.f;
		OriginalData.ExplainText = "공격력 10 증가, 투사체 속도 20% 증가";
		break;
	case 3:
		OriginalData.Damage += 10.f;
		OriginalData.Speed *= 1.2f;
		OriginalData.ExplainText = "공격력 10 증가";
		break;
	case 4:
		OriginalData.Damage += 10.f;
		OriginalData.ExplainText = "공격력 10 증가, 투사체 속도 20% 증가";
		break;
	case 5:
		OriginalData.Damage += 10.f;
		OriginalData.Speed *= 1.2f;
		OriginalData.ExplainText = "공격력 10 증가";
		break;
	case 6:
		OriginalData.Damage += 10.f;
		OriginalData.ExplainText = "공격력 10 증가, 투사체 속도 20% 증가";
		break;
	case 7:
		OriginalData.Damage += 10.f;
		OriginalData.Speed *= 1.2f;
		OriginalData.ExplainText = "공격력 10 증가";
		break;
	case 8:
		OriginalData.Damage += 10.f;
		OriginalData.ExplainText = "최대 레벨 도달";
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
