#include "PreCompile.h"
#include "Pummarola.h"

FAccessoryData UPummarola::Data = { 0, };

UPummarola::UPummarola() 
{
}

UPummarola::~UPummarola() 
{
}

void UPummarola::BeginPlay()
{
	Super::BeginPlay();
	DataInit();
}

void UPummarola::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}

void UPummarola::DataInit()
{
	AccessoryType = EAccessory::Pummarola;

	Data.Level = 1;

	Data.MaxHealth = 0.f;
	Data.Recovery = 0.2f;
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

	Data.Amount = 0;
}

void UPummarola::LevelUp()
{
	int Level = ++Data.Level;
	switch (Level)
	{
	case 1:
		Data.Level = 1;

		Data.MaxHealth = 0.f;
		Data.Recovery = 0.2f;
		Data.Armor = 0.f;
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
		Data.Recovery += 0.2f;
		break;
	case 3:
		Data.Recovery += 0.2f;
		break;
	case 4:
		Data.Recovery += 0.2f;
		break;
	case 5:
		Data.Recovery += 0.2f;
		break;
	default:
		break;
	}
}
