#pragma once
#include "Weapon.h"
class UKingBible : public UWeapon
{
	GENERATED_BODY(UWeapon)
public:
	//constructer destructer
	UKingBible();
	~UKingBible();

	//delete Function
	UKingBible(const UKingBible& _Other) = delete;
	UKingBible(UKingBible&& _Other) noexcept = delete;
	UKingBible& operator=(const UKingBible& _Other) = delete;
	UKingBible& operator=(UKingBible&& _Other) noexcept = delete;

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