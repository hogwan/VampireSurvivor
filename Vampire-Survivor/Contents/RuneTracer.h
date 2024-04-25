#pragma once
#include "Weapon.h"
class URuneTracer : public UWeapon
{
	GENERATED_BODY(UWeapon)
public:
	//constructer destructer
	URuneTracer();
	~URuneTracer();

	//delete Function
	URuneTracer(const URuneTracer& _Other) = delete;
	URuneTracer(URuneTracer&& _Other) noexcept = delete;
	URuneTracer& operator=(const URuneTracer& _Other) = delete;
	URuneTracer& operator=(URuneTracer&& _Other) noexcept = delete;

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