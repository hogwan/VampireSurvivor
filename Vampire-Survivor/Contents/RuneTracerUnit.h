#pragma once
#include "VSObject.h"
class ARuneTracerUnit : public AVSObject
{
	GENERATED_BODY(AVSObject)
public:
	//constructer destructer
	ARuneTracerUnit();
	~ARuneTracerUnit();

	//delete Function
	ARuneTracerUnit(const ARuneTracerUnit& _Other) = delete;
	ARuneTracerUnit(ARuneTracerUnit&& _Other) noexcept = delete;
	ARuneTracerUnit& operator=(const ARuneTracerUnit& _Other) = delete;
	ARuneTracerUnit& operator=(ARuneTracerUnit&& _Other) noexcept = delete;

	void SetMoveVector(FVector _MoveVector)
	{
		MoveVector = _MoveVector;
	}
protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
	void ColLogic();

	void ReflectLogic();

	float LiveTime = 0.f;

	FVector MoveVector = FVector::Zero;
private:

};