#pragma once
#include <EngineCore/Actor.h>

struct FWeaponData
{
public:
	std::string ExplainText;

	int Level;
	int Amount;
	int Penetration;
	float Damage;
	float Speed;
	float Duration;
	float Area;
	float Cooldown;
	float KnockbackPower;

};

class UWeapon : public AActor
{
	GENERATED_BODY(AActor)
public:
	//constructer destructer
	UWeapon();
	~UWeapon();

	//delete Function
	UWeapon(const UWeapon& _Other) = delete;
	UWeapon(UWeapon&& _Other) noexcept = delete;
	UWeapon& operator=(const UWeapon& _Other) = delete;
	UWeapon& operator=(UWeapon&& _Other) noexcept = delete;

	EWeapon GetWeaponType()
	{
		return Type;
	}

	virtual void ApplyStatus(struct FPlayerData _Data) = 0;

	virtual void LevelUp() = 0;
	virtual void DataInit() = 0;
protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	virtual void SpawnCenter() = 0;

	EWeapon Type = EWeapon::None;
	float RemainTime = 0.f;

	FWeaponData OriginalData = { "",};
private:

};