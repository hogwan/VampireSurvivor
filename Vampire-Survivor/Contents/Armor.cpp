#include "PreCompile.h"
#include "Armor.h"

FAccessoryData UArmor::Data = { 0, };

UArmor::UArmor() 
{
}

UArmor::~UArmor() 
{
}

void UArmor::BeginPlay()
{
	Super::BeginPlay();
	DataInit();
}

void UArmor::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}

void UArmor::DataInit()
{
	AccessoryType = EAccessory::Armor;

	Data.Level = 1;

	Data.MaxHealth = 0.f;
	Data.Recovery = 0.f;
	Data.Armor = 1.f;
	Data.MoveSpeed = 0.f;
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
}

void UArmor::LevelUp()
{
	int Level = ++Data.Level;
	switch (Level)
	{
	case 1:
		Data.Level = 1;

		Data.MaxHealth = 0.f;
		Data.Recovery = 0.f;
		Data.Armor = 1.f;
		Data.MoveSpeed = 0.f;
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
		Data.Armor += 1.f;
		break;
	case 3:
		Data.Armor += 1.f;
		break;
	case 4:
		Data.Armor += 1.f;
		break;
	case 5:
		Data.Armor += 1.f;
		break;
	default:
		break;
	}
}
