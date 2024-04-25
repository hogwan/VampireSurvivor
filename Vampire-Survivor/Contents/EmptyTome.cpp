#include "PreCompile.h"
#include "EmptyTome.h"

FAccesoryData UEmptyTome::Data = { 0, };

UEmptyTome::UEmptyTome() 
{
}

UEmptyTome::~UEmptyTome() 
{
}

void UEmptyTome::BeginPlay()
{
	Super::BeginPlay();
	DataInit();
}

void UEmptyTome::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}

void UEmptyTome::DataInit()
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
	Data.Cooldown = 0.08f;
	Data.Magnet = 0.f;
	Data.Luck = 0.f;
	Data.Growth = 0.f;
	Data.Greed = 0.f;
	Data.Curse = 0.f;

	Data.Amount = 0;
}

void UEmptyTome::LevelUp()
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
		Data.Cooldown = 0.08f;
		Data.Magnet = 0.f;
		Data.Luck = 0.f;
		Data.Growth = 0.f;
		Data.Greed = 0.f;
		Data.Curse = 0.f;

		Data.Amount = 0;
		break;
	case 2:
		Data.Cooldown += 0.08f;
		break;
	case 3:
		Data.Cooldown += 0.08f;
		break;
	case 4:
		Data.Cooldown += 0.08f;
		break;
	case 5:
		Data.Cooldown += 0.08f;
		break;
	default:
		break;
	}
}
