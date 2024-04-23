#pragma once
#include <EngineCore/Actor.h>

struct FWeaponData
{
public:
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
protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	virtual void DataInit() = 0;
	virtual void LevelUp() = 0;
	virtual void SpawnCenter() = 0;

	float RemainTime = 0.f;
private:

};