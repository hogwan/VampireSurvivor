#pragma once
#include "VSObject.h"
class AFireWandUnit : public AVSObject
{
	GENERATED_BODY(AVSObject)
public:
	//constructer destructer
	AFireWandUnit();
	~AFireWandUnit();

	//delete Function
	AFireWandUnit(const AFireWandUnit& _Other) = delete;
	AFireWandUnit(AFireWandUnit&& _Other) noexcept = delete;
	AFireWandUnit& operator=(const AFireWandUnit& _Other) = delete;
	AFireWandUnit& operator=(AFireWandUnit&& _Other) noexcept = delete;
	void SetMoveVector(FVector _MoveVector)
	{
		MoveVector = _MoveVector;
	}

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void ColLogic();
	void DirCheck();

	FVector MoveVector = FVector::Zero;


	float RemainTime = 0.f;
private:
};