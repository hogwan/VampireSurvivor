#pragma once
#include "Weapon.h"
class UFireWand : public UWeapon
{
	GENERATED_BODY(UWeapon)
public:
	//constructer destructer
	UFireWand();
	~UFireWand();

	//delete Function
	UFireWand(const UFireWand& _Other) = delete;
	UFireWand(UFireWand&& _Other) noexcept = delete;
	UFireWand& operator=(const UFireWand& _Other) = delete;
	UFireWand& operator=(UFireWand&& _Other) noexcept = delete;
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