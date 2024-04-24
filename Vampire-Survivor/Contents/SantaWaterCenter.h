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

	void SetTargetPos(FVector _TargetPos)
	{
		TargetPos = _TargetPos;
	}

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
	
	FVector TargetPos = FVector::Zero;
	void SpawnLogic();
	
private:

};

