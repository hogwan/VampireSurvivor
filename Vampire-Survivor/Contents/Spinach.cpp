#include "PreCompile.h"
#include "Spinach.h"

FAccessoryData USpinach::Data = { "레벨당 공격력이 10% 증가한다.",0,};

USpinach::USpinach() 
{
}

USpinach::~USpinach() 
{
}

void USpinach::BeginPlay()
{
	Super::BeginPlay();
	DataInit();
}

void USpinach::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}

void USpinach::DataInit()
{
	AccessoryType = EAccessory::Spinach;

	Data.Level = 1;

	Data.MaxHealth = 0.f;
	Data.Recovery = 0.f;
	Data.Armor = 0.f;
	Data.MoveSpeed = 0.f;
	Data.Might = 0.1f;
	Data.Speed = 0.f;
	Data.Duration = 0.f;
	Data.Area = 0.f;
	Data.Cooldown = 0.f;
	Data.Magnet = 0.f;
	Data.Luck = 0.f;
	Data.Growth = 0.f;
	Data.Greed = 0.f;
	Data.Curse = 0.f;

	Data.Amount = 0;
}

void USpinach::LevelUp()
{
	int Level = ++Data.Level;
	switch (Level)
	{
	case 1:
		Data.Level = 1;

		Data.MaxHealth = 0.f;
		Data.Recovery = 0.f;
		Data.Armor = 0.f;
		Data.MoveSpeed = 0.f;
		Data.Might = 0.1f;
		Data.Speed = 0.f;
		Data.Duration = 0.f;
		Data.Area = 0.f;
		Data.Cooldown = 0.f;
		Data.Magnet = 0.f;
		Data.Luck = 0.f;
		Data.Growth = 0.f;
		Data.Greed = 0.f;
		Data.Curse = 0.f;

		Data.Amount = 0;
		break;
	case 2:
		Data.Might += 0.1f;
		break;
	case 3:
		Data.Might += 0.1f;
		break;
	case 4:
		Data.Might += 0.1f;
		break;
	case 5:
		Data.Might += 0.1f;
		break;
	default:
		break;
	}
}
