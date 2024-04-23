#pragma once
#include "WeaponCenter.h"
class AGarlicCenter : public AWeaponCenter
{
	GENERATED_BODY(AWeaponCenter)
public:
	//constructer destructer
	AGarlicCenter();
	~AGarlicCenter();

	//delete Function
	AGarlicCenter(const AGarlicCenter& _Other) = delete;
	AGarlicCenter(AGarlicCenter&& _Other) noexcept = delete;
	AGarlicCenter& operator=(const AGarlicCenter& _Other) = delete;
	AGarlicCenter& operator=(AGarlicCenter&& _Other) noexcept = delete;
protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void SpawnLogic();

	float RemainTime = 0.f;
private:
};