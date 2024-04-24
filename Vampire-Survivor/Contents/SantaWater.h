#pragma once
#include "Weapon.h"

// Ό³Έν :
class USantaWater : public UWeapon
{
	GENERATED_BODY(UWeapon)
public:
	// constructor destructor
	USantaWater();
	~USantaWater();

	// delete Function
	USantaWater(const USantaWater& _Other) = delete;
	USantaWater(USantaWater&& _Other) noexcept = delete;
	USantaWater& operator=(const USantaWater& _Other) = delete;
	USantaWater& operator=(USantaWater&& _Other) noexcept = delete;

	static FWeaponData Data;
protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void DataInit() override;
	void LevelUp() override;

	void SpawnCenter() override;
private:
};

