#include "PreCompile.h"
#include "Attractorb.h"

FAccesoryData UAttractorb::Data = { 0, };

UAttractorb::UAttractorb() 
{
}

UAttractorb::~UAttractorb() 
{
}

void UAttractorb::BeginPlay()
{
	Super::BeginPlay();
	DataInit();
}

void UAttractorb::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}

void UAttractorb::DataInit()
{
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
	Data.Magnet = 0.5f;
	Data.Luck = 0.f;
	Data.Growth = 0.f;
	Data.Greed = 0.f;
	Data.Curse = 0.f;

	Data.Amount = 0;
}

void UAttractorb::LevelUp()
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
		Data.Area = 0.f;
		Data.Cooldown = 0.f;
		Data.Magnet = 0.5f;
		Data.Luck = 0.f;
		Data.Growth = 0.f;
		Data.Greed = 0.f;
		Data.Curse = 0.f;

		Data.Amount = 0;
		break;
	case 2:
		Data.Magnet += 0.33f;
		break;
	case 3:
		Data.Magnet += 0.25f;
		break;
	case 4:
		Data.Magnet += 0.20f;
		break;
	case 5:
		Data.Magnet += 0.33f;
		break;
	default:
		break;
	}
}
