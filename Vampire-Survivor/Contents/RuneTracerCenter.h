#pragma once
#include "WeaponCenter.h"
class ARuneTracerCenter : public AWeaponCenter
{
	GENERATED_BODY(AWeaponCenter)
public:
	//constructer destructer
	ARuneTracerCenter();
	~ARuneTracerCenter();

	//delete Function
	ARuneTracerCenter(const ARuneTracerCenter& _Other) = delete;
	ARuneTracerCenter(ARuneTracerCenter&& _Other) noexcept = delete;
	ARuneTracerCenter& operator=(const ARuneTracerCenter& _Other) = delete;
	ARuneTracerCenter& operator=(ARuneTracerCenter&& _Other) noexcept = delete;
protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	float ShootTerm = 0.2f;
	float RemainTime = 0.f;
	void ShootLogic();
	int ShootCount = 0;

	class AEnemy* Target = nullptr;

private:

};