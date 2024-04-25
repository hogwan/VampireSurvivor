#pragma once
#include "Weapon.h"

// Ό³Έν :
class UWhip : public UWeapon
{
	GENERATED_BODY(UWeapon)
public:
	// constructor destructor
	UWhip();
	~UWhip();

	// delete Function
	UWhip(const UWhip& _Other) = delete;
	UWhip(UWhip&& _Other) noexcept = delete;
	UWhip& operator=(const UWhip& _Other) = delete;
	UWhip& operator=(UWhip&& _Other) noexcept = delete;

	static FWeaponData Data;
protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void DataInit() override;
	void LevelUp() override;

	void SpawnCenter() override;
	void ApplyStatus(struct FPlayerData _Data) override;

private:
};

