#pragma once
#include "WeaponCenter.h"
class AAxeCenter : public AWeaponCenter
{
	GENERATED_BODY(AWeaponCenter)
public:
	//constructer destructer
	AAxeCenter();
	~AAxeCenter();

	//delete Function
	AAxeCenter(const AAxeCenter& _Other) = delete;
	AAxeCenter(AAxeCenter&& _Other) noexcept = delete;
	AAxeCenter& operator=(const AAxeCenter& _Other) = delete;
	AAxeCenter& operator=(AAxeCenter&& _Other) noexcept = delete;
protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	float RemainTime = 0.f;
	float ThrowTerm = 0.2f;
	int RemainCount = 0;
	
	float ThrowForce = 0.f;

	void ThrowLogic();
private:

};