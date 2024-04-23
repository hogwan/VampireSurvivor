#pragma once
#include "VSObject.h"
class ACrossUnit : public AVSObject
{
	GENERATED_BODY(AVSObject)
public:
	//constructer destructer
	ACrossUnit();
	~ACrossUnit();

	//delete Function
	ACrossUnit(const ACrossUnit& _Other) = delete;
	ACrossUnit(ACrossUnit&& _Other) noexcept = delete;
	ACrossUnit& operator=(const ACrossUnit& _Other) = delete;
	ACrossUnit& operator=(ACrossUnit&& _Other) noexcept = delete;

	void SetMoveVector(FVector _MoveVector)
	{
		MoveVector = _MoveVector;

		ReverseVector = -MoveVector.Normalize3DReturn();
	}
protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void ColLogic();
	void Release();
	FVector MoveVector = FVector::Zero;
	FVector ReverseVector = FVector::Zero;
	float ReverseVectorForce = 300.f;

	float RotationSpeed = 200.f;
private:


};