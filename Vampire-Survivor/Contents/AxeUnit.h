#pragma once
#include "VSObject.h"
class AAxeUnit : public AVSObject
{
	GENERATED_BODY(AVSObject)
public:
	//constructer destructer
	AAxeUnit();
	~AAxeUnit();

	//delete Function
	AAxeUnit(const AAxeUnit& _Other) = delete;
	AAxeUnit(AAxeUnit&& _Other) noexcept = delete;
	AAxeUnit& operator=(const AAxeUnit& _Other) = delete;
	AAxeUnit& operator=(AAxeUnit&& _Other) noexcept = delete;

	void SetMoveVector(FVector _MoveVector)
	{
		MoveVector = _MoveVector;
	}

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void ColLogic();
	void Release();
	FVector MoveVector = FVector::Zero;
	FVector Gravity = FVector(0.f, -300.f, 0.f);

	int Penetration = 0;
	float RotationSpeed = 50.f;
private:

};