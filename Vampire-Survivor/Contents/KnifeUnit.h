#pragma once
#include "VSObject.h"

// Ό³Έν :
class AKnifeUnit : public AVSObject
{
	GENERATED_BODY(AVSObject)
public:
	// constructor destructor
	AKnifeUnit();
	~AKnifeUnit();

	// delete Function
	AKnifeUnit(const AKnifeUnit& _Other) = delete;
	AKnifeUnit(AKnifeUnit&& _Other) noexcept = delete;
	AKnifeUnit& operator=(const AKnifeUnit& _Other) = delete;
	AKnifeUnit& operator=(AKnifeUnit&& _Other) noexcept = delete;

	void SetMoveVector(FVector _MoveVector)
	{
		MoveVector = _MoveVector;
	}

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	FVector MoveVector = FVector::Zero;

private:

};

