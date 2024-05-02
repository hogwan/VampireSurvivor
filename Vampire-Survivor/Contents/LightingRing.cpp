#include "PreCompile.h"
#include "LightingRing.h"
#include "LightingRingCenter.h"
#include "Player.h"

FWeaponData ULightingRing::Data = { "������ ������ ������ ����Ĩ�ϴ�.",0,};

ULightingRing::ULightingRing()
{
}

ULightingRing::~ULightingRing()
{
}

void ULightingRing::BeginPlay()
{
	Super::BeginPlay();
	SpawnCenter();
}

void ULightingRing::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	RemainTime -= _DeltaTime;
	if (RemainTime < 0.f)
	{
		RemainTime = Data.Cooldown;
		SpawnCenter();
	}

}

void ULightingRing::DataInit()
{
	Type = EWeapon::LightingRing;

	Data.Level = 1;
	OriginalData.Amount = 2;
	OriginalData.Penetration = 0;
	OriginalData.Damage = 15.f;
	OriginalData.Speed = 300.f;
	OriginalData.Duration = 0.f;
	OriginalData.Area = 1.f;
	OriginalData.Cooldown = 4.5f;
	OriginalData.KnockbackPower = 100.f;
	OriginalData.ExplainText = "����ü �� 1 ����";

	RemainTime = OriginalData.Cooldown;
}

void ULightingRing::LevelUp()
{
	int Level = ++Data.Level;
	switch (Level)
	{
	case 1:
		Data.Level = 1;
		OriginalData.Amount = 2;
		OriginalData.Penetration = 0;
		OriginalData.Damage = 15.f;
		OriginalData.Speed = 300.f;
		OriginalData.Duration = 0.f;
		OriginalData.Area = 1.f;
		OriginalData.Cooldown = 4.5f;
		OriginalData.KnockbackPower = 100.f;
		OriginalData.ExplainText = "����ü �� 1 ����";
		break;
	case 2:
		++OriginalData.Amount;
		OriginalData.ExplainText = "���ݹ��� 100% ����, ���ݷ� 10 ����";
		break;
	case 3:
		OriginalData.Damage += 10.f;
		OriginalData.Area *= 2.f;
		OriginalData.ExplainText = "����ü �� 1 ����";
		break;
	case 4:
		++OriginalData.Amount;
		OriginalData.ExplainText = "���ݹ��� 100% ����, ���ݷ� 20 ����";
		break;
	case 5:
		OriginalData.Damage += 20.f;
		OriginalData.Area *= 2.f;
		OriginalData.ExplainText = "���ݹ��� 10% ����";
		break;
	case 6:
		OriginalData.Area *= 1.1f;
		OriginalData.ExplainText = "���ݹ��� 100% ����, ���ݷ� 10 ����";
		break;
	case 7:
		OriginalData.Area *= 2.f;
		OriginalData.Damage += 10.f;
		OriginalData.ExplainText = "����ü �� 1 ����";
		break;
	case 8:
		++OriginalData.Amount;
		OriginalData.ExplainText = "�ִ� ���� ����";
		break;
	default:
		break;
	}
}

void ULightingRing::SpawnCenter()
{
	GetWorld()->SpawnActor<ALightingRingCenter>("Center");
}

void ULightingRing::ApplyStatus(FPlayerData _Data)
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
	Data.ExplainText = OriginalData.ExplainText;
	RemainTime = Data.Cooldown;
}
