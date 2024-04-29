#pragma once
#include <EngineCore/Actor.h>

struct FAccessoryData
{
	std::string ExplainText;

	int Level = 1;

	float MaxHealth = 0.f;
	float Recovery = 0.f;
	float Armor = 0.f;
	float MoveSpeed = 1.f;
	float Might = 0.f;
	float Speed = 0.f;
	float Duration = 0.f;
	float Area = 0.f;
	float Cooldown = 0.f;
	float Magnet = 1.f;
	float Luck = 0.f;
	float Growth = 0.f;
	float Greed = 0.f;
	float Curse = 0.f;

	int Amount = 0;

	void operator+=(FAccessoryData _Data)
	{
		this->Amount += _Data.Amount;
		this->Area += _Data.Area;
		this->Armor += _Data.Armor;
		this->Cooldown += _Data.Cooldown;
		this->Curse += _Data.Curse;
		this->Duration += _Data.Duration;
		this->Greed += _Data.Greed;
		this->Growth += _Data.Growth;
		this->Luck += _Data.Luck;
		this->Magnet += _Data.Magnet;
		this->MaxHealth += _Data.MaxHealth;
		this->Might += _Data.Might;
		this->MoveSpeed += _Data.MoveSpeed;
		this->Speed += _Data.Speed;
		this->Recovery += _Data.Recovery;
	}
};

// Ό³Έν :
class UAccessory : public AActor
{
	GENERATED_BODY(AActor)
public:
	// constructor destructor
	UAccessory();
	~UAccessory();

	// delete Function
	UAccessory(const UAccessory& _Other) = delete;
	UAccessory(UAccessory&& _Other) noexcept = delete;
	UAccessory& operator=(const UAccessory& _Other) = delete;
	UAccessory& operator=(UAccessory&& _Other) noexcept = delete;

	virtual FAccessoryData GetData() = 0;
	virtual void LevelUp() = 0;

	EAccessory GetAccessoryType()
	{
		return AccessoryType;
	}

	FAccessoryData Data = { "",};

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	virtual void DataInit() = 0;

	EAccessory AccessoryType = EAccessory::None;
private:

};

