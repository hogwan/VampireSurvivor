#pragma once
#include "WeaponCenter.h"

// Ό³Έν :
class AKnifeCenter : public AWeaponCenter
{
	GENERATED_BODY(AWeaponCenter)
public:
	// constructor destructor
	AKnifeCenter();
	~AKnifeCenter();

	// delete Function
	AKnifeCenter(const AKnifeCenter& _Other) = delete;
	AKnifeCenter(AKnifeCenter&& _Other) noexcept = delete;
	AKnifeCenter& operator=(const AKnifeCenter& _Other) = delete;
	AKnifeCenter& operator=(AKnifeCenter&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	float OffSet = 5.f;
	float SpawnInterval = 0.1f;
	float RemainTime = 0.f;
	int RemainKnifeCount = Data.Amount;

	bool UpSpawn = true;
	void SpawnLogic(float _DeltaTime);

private:

};

