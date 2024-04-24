#pragma once
#include "WeaponCenter.h"
class ALightingRingCenter : public AWeaponCenter
{
	GENERATED_BODY(AWeaponCenter)
public:
	//constructer destructer
	ALightingRingCenter();
	~ALightingRingCenter();

	//delete Function
	ALightingRingCenter(const ALightingRingCenter& _Other) = delete;
	ALightingRingCenter(ALightingRingCenter&& _Other) noexcept = delete;
	ALightingRingCenter& operator=(const ALightingRingCenter& _Other) = delete;
	ALightingRingCenter& operator=(ALightingRingCenter&& _Other) noexcept = delete;
protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	int RemainCount = 0;
	float RemainTime = 0.f;
	float Term = 0.01f;

	void SpawnThunderLogic();
private:

};