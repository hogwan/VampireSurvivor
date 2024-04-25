#pragma once
#include "Weapon.h"
class ULightingRing : public UWeapon
{
	GENERATED_BODY(UWeapon)
public:
	//constructer destructer
	ULightingRing();
	~ULightingRing();

	//delete Function
	ULightingRing(const ULightingRing& _Other) = delete;
	ULightingRing(ULightingRing&& _Other) noexcept = delete;
	ULightingRing& operator=(const ULightingRing& _Other) = delete;
	ULightingRing& operator=(ULightingRing&& _Other) noexcept = delete;
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