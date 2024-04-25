#pragma once
#include "Weapon.h"
class UAxe : public UWeapon
{
	GENERATED_BODY(UWeapon)
public:
	//constructer destructer
	UAxe();
	~UAxe();

	//delete Function
	UAxe(const UAxe& _Other) = delete;
	UAxe(UAxe&& _Other) noexcept = delete;
	UAxe& operator=(const UAxe& _Other) = delete;
	UAxe& operator=(UAxe&& _Other) noexcept = delete;

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