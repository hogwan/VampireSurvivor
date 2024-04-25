#include "PreCompile.h"
#include "Bracer.h"

UBracer::UBracer() 
{
}

UBracer::~UBracer() 
{
}

void UBracer::BeginPlay()
{
	Super::BeginPlay();
	DataInit();
}

void UBracer::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}

void UBracer::DataInit()
{
	AccessoryType = EAccessory::Bracer;

	Data.Level = 1;

	Data.MaxHealth = 0.f;
	Data.Recovery = 0.f;
	Data.Armor = 0.f;
	Data.MoveSpeed = 0.f;
	Data.Might = 0.0f;
	Data.Speed = 0.1f;
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

void UBracer::LevelUp()
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
		Data.Speed = 0.1f;
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
		Data.Speed += 0.1f;
		break;
	case 3:
		Data.Speed += 0.1f;
		break;
	case 4:
		Data.Speed += 0.1f;
		break;
	case 5:
		Data.Speed += 0.1f;
		break;
	default:
		break;
	}
}
