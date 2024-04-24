#pragma once
#include "VSObject.h"

// Ό³Έν :
class ASantaWaterFlame : public AVSObject
{
	GENERATED_BODY(AVSObject)
public:
	// constructor destructor
	ASantaWaterFlame();
	~ASantaWaterFlame();

	// delete Function
	ASantaWaterFlame(const ASantaWaterFlame& _Other) = delete;
	ASantaWaterFlame(ASantaWaterFlame&& _Other) noexcept = delete;
	ASantaWaterFlame& operator=(const ASantaWaterFlame& _Other) = delete;
	ASantaWaterFlame& operator=(ASantaWaterFlame&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime);

	FVector IncreaseTerm = FVector(20.f,20.f,1.f);
	float LiveTime = 1.0f;
	float AlphaDecrease = 1.f;
	float Alpha = 1.f;
private:

};

