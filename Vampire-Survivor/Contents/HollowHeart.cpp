#include "PreCompile.h"
#include "HollowHeart.h"

UHollowHeart::UHollowHeart() 
{
}

UHollowHeart::~UHollowHeart() 
{
}

void UHollowHeart::BeginPlay()
{
	Super::BeginPlay();
	DataInit();
}

void UHollowHeart::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}

void UHollowHeart::DataInit()
{
	AccessoryType = EAccessory::HollowHeart;

	Data.Level = 1;

	Data.MaxHealth = 20.f;
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

	Data.Amount = 0;
}

void UHollowHeart::LevelUp()
{
	int Level = ++Data.Level;
	switch (Level)
	{
	case 1:
		Data.Level = 1;

		Data.MaxHealth = 20.f;
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

		Data.Amount = 0;
		break;
	case 2:
		Data.MaxHealth += 20.f;
		break;
	case 3:
		Data.MaxHealth += 20.f;
		break;
	case 4:
		Data.MaxHealth += 20.f;
		break;
	case 5:
		Data.MaxHealth += 20.f;
		break;
	default:
		break;
	}
}
