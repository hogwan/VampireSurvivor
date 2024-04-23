#pragma once
#include "Weapon.h"

// Ό³Έν :
class UKnife : public UWeapon
{
	GENERATED_BODY(UWeapon)
public:
	// constructor destructor
	UKnife();
	~UKnife();

	// delete Function
	UKnife(const UKnife& _Other) = delete;
	UKnife(UKnife&& _Other) noexcept = delete;
	UKnife& operator=(const UKnife& _Other) = delete;
	UKnife& operator=(UKnife&& _Other) noexcept = delete;

	static FWeaponData Data;
protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void DataInit() override;
	void LevelUp() override;

	void SpawnCenter() override;

	float RemainTime = 0.f;
private:

};

