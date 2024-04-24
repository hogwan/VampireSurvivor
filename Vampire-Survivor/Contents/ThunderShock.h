#pragma once
#include "VSObject.h"
class AThunderShock : public AVSObject
{
	GENERATED_BODY(AVSObject)
public:
	//constructer destructer
	AThunderShock();
	~AThunderShock();

	//delete Function
	AThunderShock(const AThunderShock& _Other) = delete;
	AThunderShock(AThunderShock&& _Other) noexcept = delete;
	AThunderShock& operator=(const AThunderShock& _Other) = delete;
	AThunderShock& operator=(AThunderShock&& _Other) noexcept = delete;
protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void ColLogic();

	FVector IncreaseTerm = FVector(200.f, 200.f, 1.f);
	float LiveTime = 0.2f;
	float AlphaDecrease = 4.f;
	float Alpha = 1.f;

private:

};