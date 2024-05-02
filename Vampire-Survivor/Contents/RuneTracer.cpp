#include "PreCompile.h"
#include "RuneTracer.h"
#include "RuneTracerCenter.h"
#include "player.h"

FWeaponData URuneTracer::Data = { "적을 관통하며 튕겨져 나옵니다.",};

URuneTracer::URuneTracer()
{
}

URuneTracer::~URuneTracer()
{
}

void URuneTracer::BeginPlay()
{
	Super::BeginPlay();
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
	OriginalData.Amount = 1;
	OriginalData.Penetration = 1;
	OriginalData.Damage = 10.f;
	OriginalData.Speed = 300.f;
	OriginalData.Duration = 2.25f;
	OriginalData.Area = 1.f;
	OriginalData.Cooldown = 3.f;
	OriginalData.KnockbackPower = 100.f;
	OriginalData.ExplainText = "공격력 5 증가, 투사체 속도 20% 증가";

	RemainTime = OriginalData.Cooldown;
}

void URuneTracer::LevelUp()
{
	int Level = ++Data.Level;
	switch (Level)
	{
	case 1:
		Data.Level = 1;
		OriginalData.Amount = 1;
		OriginalData.Penetration = 1;
		OriginalData.Damage = 10.f;
		OriginalData.Speed = 300.f;
		OriginalData.Duration = 2.25f;
		OriginalData.Area = 1.f;
		OriginalData.Cooldown = 3.f;
		OriginalData.KnockbackPower = 100.f;
		OriginalData.ExplainText = "공격력 5 증가, 투사체 속도 20% 증가";
		break;
	case 2:
		OriginalData.Damage += 5.f;
		OriginalData.Speed *= 1.2f;
		OriginalData.ExplainText = "공격력 5 증가, 지속시간 0.3초 증가";
		break;
	case 3:
		OriginalData.Damage += 5.f;
		OriginalData.Duration += 0.3f;
		OriginalData.ExplainText = "투사체 수 1 증가";
		break;
	case 4:
		++OriginalData.Amount;
		OriginalData.ExplainText = "공격력 5 증가, 투사체 속도 20% 증가";
		break;
	case 5:
		OriginalData.Damage += 5.f;
		OriginalData.Speed *= 1.2f;
		OriginalData.ExplainText = "공격력 5 증가, 지속시간 0.3초 증가";
		break;
	case 6:
		OriginalData.Damage += 5.f;
		OriginalData.Duration += 0.3f;
		OriginalData.ExplainText = "투사체 수 1 증가";
		break;
	case 7:
		++OriginalData.Amount;
		OriginalData.ExplainText = "지속시간 0.5초 증가";
		break;
	case 8:
		OriginalData.Duration += 0.5f;
		OriginalData.ExplainText = "최대레벨 도달";
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
