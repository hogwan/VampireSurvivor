#include "PreCompile.h"
#include "Wings.h"

FAccessoryData UWings::Data = { "레벨당 이동속도가 10% 상승한다.",0,};

UWings::UWings() 
{
}

UWings::~UWings() 
{
}

void UWings::BeginPlay()
{
	Super::BeginPlay();
	DataInit();
}

void UWings::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}

void UWings::DataInit()
{
	AccessoryType = EAccessory::Wings;

	Data.Level = 1;

	Data.MaxHealth = 0.f;
	Data.Recovery = 0.f;
	Data.Armor = 0.f;
	Data.MoveSpeed = 0.1f;
	Data.Might = 0.0f;
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

void UWings::LevelUp()
{
	int Level = ++Data.Level;
	switch (Level)
	{
	case 1:
		Data.Level = 1;

		Data.MaxHealth = 0.f;
		Data.Recovery = 0.f;
		Data.Armor = 0.f;
		Data.MoveSpeed = 0.1f;
		Data.Might = 0.f;
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
		Data.MoveSpeed += 0.1f;
		break;
	case 3:
		Data.MoveSpeed += 0.1f;
		break;
	case 4:
		Data.MoveSpeed += 0.1f;
		break;
	case 5:
		Data.MoveSpeed += 0.1f;
		break;
	default:
		break;
	}
}
