#include "PreCompile.h"
#include "KingBible.h"
#include "KingBibleCenter.h"
#include "Bat1.h"
#include "Player.h"

FWeaponData UKingBible::Data = { 0, };

UKingBible::UKingBible()
{
}

UKingBible::~UKingBible()
{
}

void UKingBible::BeginPlay()
{
	Super::BeginPlay();
	DataInit();
	SpawnCenter();
}

void UKingBible::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}

void UKingBible::DataInit()
{
	Data.Level = 1;
	Data.Amount = 5;
	Data.Penetration = -1;
	Data.Damage = 10.f;
	Data.Speed = 100.f;
	Data.Duration = 3.f;
	Data.Area = 100.f;
	Data.Cooldown = 3.f;
	Data.KnockbackPower = 100.f;
}

void UKingBible::LevelUp()
{
	int Level = ++Data.Level;

	switch (Level)
	{
	case 1:
		Data.Level = 1;
		Data.Amount = 1;
		Data.Penetration = -1;
		Data.Damage = 10.f;
		Data.Speed = 100.f;
		Data.Duration = 3.f;
		Data.Area = 100.f;
		Data.Cooldown = 3.f;
		Data.KnockbackPower = 100.f;
		break;
	case 2:
		++Data.Amount;
		break;
	case 3:
		Data.Speed = Data.Speed * 1.3f;
		Data.Area = Data.Area * 1.25f;
		break;
	case 4:
		Data.Duration += 0.5f;
		Data.Damage += 10.f;
		break;
	case 5:
		++Data.Amount;
		break;
	case 6:
		Data.Speed = Data.Speed * 1.3f;
		Data.Area = Data.Area * 1.25f;
		break;
	case 7:
		Data.Duration += 0.5f;
		Data.Damage += 10.f;
		break;
	case 8:
		++Data.Amount;
		break;
	}

	SpawnCenter();
}

void UKingBible::SpawnCenter()
{
	GetWorld()->SpawnActor<AKingBibleCenter>("Center");
	DelayCallBack(Data.Duration + Data.Cooldown, [=]
		{
			SpawnCenter();
		});
}
