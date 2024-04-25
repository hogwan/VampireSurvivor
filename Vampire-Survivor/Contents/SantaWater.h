#pragma once
#include "Weapon.h"

// ���� :
class USantaWater : public UWeapon
{
	GENERATED_BODY(UWeapon)
public:
	// constructor destructor
	USantaWater();
	~USantaWater();

	// delete Function
	USantaWater(const USantaWater& _Other) = delete;
	USantaWater(USantaWater&& _Other) noexcept = delete;
	USantaWater& operator=(const USantaWater& _Other) = delete;
	USantaWater& operator=(USantaWater&& _Other) noexcept = delete;

	static FWeaponData Data;
protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void RotAround(float _DeltaTime);

	void DataInit() override;
	void LevelUp() override;

	void SpawnCenter() override;
	void ApplyStatus(struct FPlayerData _Data) override;

	void SpawnLoop(float _DeltaTime);
	int RemainCount = 0;;

	float LoopTime = 0.2f;
	float LoopRemainTime = 0.f;

	bool IsLoop = false;

	UDefaultSceneComponent* TargetPoint = nullptr;
	float RotSpeed = 240.f;
private:
};

