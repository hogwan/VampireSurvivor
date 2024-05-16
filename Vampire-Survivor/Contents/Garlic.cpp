#include "PreCompile.h"
#include "Garlic.h"
#include "GarlicCenter.h"
#include "Player.h"

FWeaponData UGarlic::Data = { "���� ���� ������ ���ظ� �ݴϴ�. ���� �˹�, ���������� ���ҽ�ŵ�ϴ�.",0,};
UGarlic::UGarlic()
{
}

UGarlic::~UGarlic()
{
}

void UGarlic::BeginPlay()
{
	Super::BeginPlay();
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
}

void UGarlic::DataInit()
{
	Type = EWeapon::Garlic;

	Data.Level = 1;
	OriginalData.Amount = 0;
	OriginalData.Penetration = 0;
	OriginalData.Damage = 5.f;
	OriginalData.Speed = 0.f;
	OriginalData.Duration = 0.f;
	OriginalData.Area = 1.f;
	OriginalData.Cooldown = 2.f;
	OriginalData.KnockbackPower = 100.f;
	OriginalData.ExplainText = "���ݹ��� 40% ����, ���ݷ� 2 ����";

	RemainTime = OriginalData.Cooldown;
}

void UGarlic::LevelUp()
{
	int Level = ++Data.Level;
	switch (Level)
	{
	case 1:
		Data.Level = 1;
		OriginalData.Amount = 0;
		OriginalData.Penetration = 0;
		OriginalData.Damage = 5.f;
		OriginalData.Speed = 0.f;
		OriginalData.Duration = 0.f;
		OriginalData.Area = 1.f;
		OriginalData.Cooldown = 2.f;
		OriginalData.KnockbackPower = 100.f;
		OriginalData.ExplainText = "���ݹ��� 40% ����, ���ݷ� 2 ����";
		break;
	case 2:
		OriginalData.Area *= 1.4f;
		OriginalData.Damage += 2.f;
		OriginalData.ExplainText = "��Ÿ�� 0.1�� ����, ���ݷ� 1 ����";
		break;
	case 3:
		OriginalData.Cooldown -= 0.1f;
		OriginalData.Damage += 1.f;
		OriginalData.ExplainText = "���ݹ��� 20% ����, ���ݷ� 1 ����";
		break;
	case 4:
		OriginalData.Area *= 1.2f;
		OriginalData.Damage += 1.f;
		OriginalData.ExplainText = "��Ÿ�� 0.1�� ����, ���ݷ� 2 ����";
		break;
	case 5:
		OriginalData.Cooldown -= 0.1f;
		OriginalData.Damage += 2.f;
		OriginalData.ExplainText = "���ݹ��� 20% ����, ���ݷ� 1 ����";
		break;
	case 6:
		OriginalData.Area *= 1.2f;
		OriginalData.Damage += 1.f;
		OriginalData.ExplainText = "��Ÿ�� 0.1�� ����, ���ݷ� 1 ����";
		break;
	case 7:
		OriginalData.Cooldown -= 0.1f;
		OriginalData.Damage += 1.f;
		OriginalData.ExplainText = "���ݹ��� 20% ����, ���ݷ� 2 ����";
		break;
	case 8:
		OriginalData.Area *= 1.2f;
		OriginalData.Damage += 2.f;
		OriginalData.ExplainText = "�ִ� ���� ����";
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
