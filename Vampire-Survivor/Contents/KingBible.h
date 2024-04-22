#pragma once
#include "Weapon.h"
class UKingBible : public UWeapon
{
	GENERATED_BODY(UWeapon)
	friend class AKingBibleCenter;
public:
	//constructer destructer
	UKingBible();
	~UKingBible();

	//delete Function
	UKingBible(const UKingBible& _Other) = delete;
	UKingBible(UKingBible&& _Other) noexcept = delete;
	UKingBible& operator=(const UKingBible& _Other) = delete;
	UKingBible& operator=(UKingBible&& _Other) noexcept = delete;

protected:
	static FWeaponData Data;
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void DataInit() override;
	void LevelUp() override;

	void SpawnCenter() override;
private:

};