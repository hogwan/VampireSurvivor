#pragma once
#include "VSObject.h"

// Ό³Έν :
class AMagicWandUnit : public AVSObject
{
	GENERATED_BODY(AVSObject)
public:
	// constructor destructor
	AMagicWandUnit();
	~AMagicWandUnit();

	// delete Function
	AMagicWandUnit(const AMagicWandUnit& _Other) = delete;
	AMagicWandUnit(AMagicWandUnit&& _Other) noexcept = delete;
	AMagicWandUnit& operator=(const AMagicWandUnit& _Other) = delete;
	AMagicWandUnit& operator=(AMagicWandUnit&& _Other) noexcept = delete;

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
	int Penetration = 0;
private:

};

