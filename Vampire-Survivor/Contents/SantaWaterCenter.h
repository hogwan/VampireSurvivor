#pragma once
#include "WeaponCenter.h"

// Ό³Έν :
class ASantaWaterCenter : public AWeaponCenter
{
	GENERATED_BODY(AWeaponCenter);
public:
	// constructor destructor
	ASantaWaterCenter();
	~ASantaWaterCenter();

	// delete Function
	ASantaWaterCenter(const ASantaWaterCenter& _Other) = delete;
	ASantaWaterCenter(ASantaWaterCenter&& _Other) noexcept = delete;
	ASantaWaterCenter& operator=(const ASantaWaterCenter& _Other) = delete;
	ASantaWaterCenter& operator=(ASantaWaterCenter&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	float RemainTime = 0.f;
	float SpawnTerm = 0.5f;
	int RemainCount = 0;

	UDefaultSceneComponent* TargetPoint = nullptr;
	float RotSpeed = 360.f;
	void RotAround(float _DeltaTime);
	void SpawnLogic();
	
private:

};

