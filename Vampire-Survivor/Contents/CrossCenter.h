#pragma once
#include "WeaponCenter.h"
class ACrossCenter : public AWeaponCenter
{
	GENERATED_BODY(AWeaponCenter)
public:
	//constructer destructer
	ACrossCenter();
	~ACrossCenter();

	//delete Function
	ACrossCenter(const ACrossCenter& _Other) = delete;
	ACrossCenter(ACrossCenter&& _Other) noexcept = delete;
	ACrossCenter& operator=(const ACrossCenter& _Other) = delete;
	ACrossCenter& operator=(ACrossCenter&& _Other) noexcept = delete;
protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	float RemainTime = 0.f;
	float ThrowTerm = 0.2f;
	int RemainCount = 0;

	float ThrowForce = 0.f;

	void UnitSpawnLogic() override;
private:

};