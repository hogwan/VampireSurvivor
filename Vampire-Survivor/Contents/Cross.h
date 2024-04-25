#pragma once
#include "Weapon.h"
class UCross : public UWeapon
{
	GENERATED_BODY(UWeapon)
public:
	//constructer destructer
	UCross();
	~UCross();

	//delete Function
	UCross(const UCross& _Other) = delete;
	UCross(UCross&& _Other) noexcept = delete;
	UCross& operator=(const UCross& _Other) = delete;
	UCross& operator=(UCross&& _Other) noexcept = delete;
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