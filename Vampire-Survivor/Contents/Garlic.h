#pragma once
#include "Weapon.h"
class UGarlic : public UWeapon
{
	GENERATED_BODY(UWeapon)
public:
	//constructer destructer
	UGarlic();
	~UGarlic();

	//delete Function
	UGarlic(const UGarlic& _Other) = delete;
	UGarlic(UGarlic&& _Other) noexcept = delete;
	UGarlic& operator=(const UGarlic& _Other) = delete;
	UGarlic& operator=(UGarlic&& _Other) noexcept = delete;

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