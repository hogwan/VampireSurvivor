#include "PreCompile.h"
#include "Knife.h"
#include "KnifeCenter.h"
#include "player.h"

FWeaponData UKnife::Data = { "�ٶ󺸴� �������� �ܰ��� ��ô�մϴ�.",0,};

UKnife::UKnife() 
{
}

UKnife::~UKnife() 
{
}

void UKnife::BeginPlay()
{
	Super::BeginPlay();
}

void UKnife::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	RemainTime -= _DeltaTime;
	if (RemainTime < 0.f)
	{
		RemainTime = Data.Cooldown;
		SpawnCenter();
	}

}

void UKnife::DataInit()
{
	Type = EWeapon::Knife;

	Data.Level = 1;
	OriginalData.Amount = 1;
	OriginalData.Penetration = 1;
	OriginalData.Damage = 6.5f;
	OriginalData.Speed = 500.f;
	OriginalData.Duration = 1.f;
	OriginalData.Area = 0.f;
	OriginalData.Cooldown = 1.0f;
	OriginalData.KnockbackPower = 100.f;
	OriginalData.ExplainText = "����ü �� 1 ����";

	RemainTime = OriginalData.Cooldown;
}

void UKnife::LevelUp()
{
	int Level = ++Data.Level;
	switch (Level)
	{
	case 1:
		Data.Level = 1;
		OriginalData.Amount = 1;
		OriginalData.Penetration = 1;
		OriginalData.Damage = 6.5f;
		OriginalData.Speed = 500.f;
		OriginalData.Duration = 1.f;
		OriginalData.Area = 0.f;
		OriginalData.Cooldown = 1.0f;
		OriginalData.KnockbackPower = 100.f;
		OriginalData.ExplainText = "����ü �� 1 ����";
		break;
	case 2:
		++OriginalData.Amount;
		OriginalData.ExplainText = "����ü �� 1 ����, ���ݷ� 5 ����";
		break;
	case 3:
		++OriginalData.Amount;
		OriginalData.Damage += 5.f;
		OriginalData.ExplainText = "����ü �� 1 ����";
		break;
	case 4:
		++OriginalData.Amount;
		OriginalData.ExplainText = "���� 1ȸ ����";
		break;
	case 5:
		++OriginalData.Penetration;
		OriginalData.ExplainText = "����ü �� 1 ����";
		break;
	case 6:
		++OriginalData.Amount;
		OriginalData.ExplainText = "����ü �� 1 ����, ���ݷ� 5 ����";
		break;
	case 7:
		++OriginalData.Penetration;
		OriginalData.Damage += 5.f;
		OriginalData.ExplainText = "���� 1ȸ ����";
		break;
	case 8:
		++OriginalData.Penetration;
		OriginalData.ExplainText = "�ִ� ���� ����";
		break;
	default:
		break;
	}
}

void UKnife::SpawnCenter()
{
	GetWorld()->SpawnActor<AKnifeCenter>("Center");
}

void UKnife::ApplyStatus(FPlayerData _Data)
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
	RemainTime = Data.Cooldown;
}
