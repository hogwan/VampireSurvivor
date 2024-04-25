#include "PreCompile.h"
#include "Spellbinder.h"

FAccesoryData USpellbinder::Data = { 0, };

USpellbinder::USpellbinder() 
{
}

USpellbinder::~USpellbinder() 
{
}

void USpellbinder::BeginPlay()
{
	Super::BeginPlay();
	DataInit();
}

void USpellbinder::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}

void USpellbinder::DataInit()
{
	Data.Level = 1;

	Data.MaxHealth = 0.f;
	Data.Recovery = 0.f;
	Data.Armor = 0.f;
	Data.MoveSpeed = 0.f;
	Data.Might = 0.0f;
	Data.Speed = 0.f;
	Data.Duration = 0.1f;
	Data.Area = 0.f;
	Data.Cooldown = 0.f;
	Data.Magnet = 0.f;
	Data.Luck = 0.f;
	Data.Growth = 0.f;
	Data.Greed = 0.f;
	Data.Curse = 0.f;

	Data.Amount = 0;
}

void USpellbinder::LevelUp()
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
		Data.Duration = 0.1f;
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
		Data.Duration += 0.1f;
		break;
	case 3:
		Data.Duration += 0.1f;
		break;
	case 4:
		Data.Duration += 0.1f;
		break;
	case 5:
		Data.Duration += 0.1f;
		break;
	default:
		break;
	}
}
