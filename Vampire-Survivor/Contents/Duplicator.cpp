#include "PreCompile.h"
#include "Duplicator.h"

UDuplicator::UDuplicator() 
{
}

UDuplicator::~UDuplicator() 
{
}

void UDuplicator::BeginPlay()
{
	Super::BeginPlay();
	DataInit();
}

void UDuplicator::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}

void UDuplicator::DataInit()
{
	AccessoryType = EAccessory::Duplicator;

	Data.Level = 1;

	Data.MaxHealth = 0.f;
	Data.Recovery = 0.f;
	Data.Armor = 0.f;
	Data.MoveSpeed = 0.f;
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

	Data.Amount = 1;
}

void UDuplicator::LevelUp()
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

		Data.Amount = 1;
		break;
	case 2:
		Data.Amount += 1;
		break;
	case 3:
		Data.Amount += 1;
		break;
	case 4:
		Data.Amount += 1;
		break;
	case 5:
		Data.Amount += 1;
		break;
	default:
		break;
	}
}
