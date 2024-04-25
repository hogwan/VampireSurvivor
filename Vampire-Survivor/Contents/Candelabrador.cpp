#include "PreCompile.h"
#include "Candelabrador.h"

FAccessoryData UCandelabrador::Data = { 0, };

UCandelabrador::UCandelabrador() 
{
}

UCandelabrador::~UCandelabrador() 
{
}

void UCandelabrador::BeginPlay()
{
	Super::BeginPlay();
	DataInit();
}

void UCandelabrador::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}

void UCandelabrador::DataInit()
{
	AccessoryType = EAccessory::Candelabrador;

	Data.Level = 1;

	Data.MaxHealth = 0.f;
	Data.Recovery = 0.f;
	Data.Armor = 0.f;
	Data.MoveSpeed = 0.f;
	Data.Might = 0.0f;
	Data.Speed = 0.f;
	Data.Duration = 0.f;
	Data.Area = 0.1f;
	Data.Cooldown = 0.f;
	Data.Magnet = 0.f;
	Data.Luck = 0.f;
	Data.Growth = 0.f;
	Data.Greed = 0.f;
	Data.Curse = 0.f;

	Data.Amount = 0;
}

void UCandelabrador::LevelUp()
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
		Data.Might = 0.f;
		Data.Speed = 0.f;
		Data.Duration = 0.f;
		Data.Area = 0.1f;
		Data.Cooldown = 0.f;
		Data.Magnet = 0.f;
		Data.Luck = 0.f;
		Data.Growth = 0.f;
		Data.Greed = 0.f;
		Data.Curse = 0.f;

		Data.Amount = 0;
		break;
	case 2:
		Data.Area += 0.1f;
		break;
	case 3:
		Data.Area += 0.1f;
		break;
	case 4:
		Data.Area += 0.1f;
		break;
	case 5:
		Data.Area += 0.1f;
		break;
	default:
		break;
	}
}
