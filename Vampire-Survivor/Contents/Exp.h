#pragma once
#include "VSObject.h"

// Ό³Έν :
class AExp : public AVSObject
{
	GENERATED_BODY(AVSObject)
public:
	// constructor destructor
	AExp();
	~AExp();

	// delete Function
	AExp(const AExp& _Other) = delete;
	AExp(AExp&& _Other) noexcept = delete;
	AExp& operator=(const AExp& _Other) = delete;
	AExp& operator=(AExp&& _Other) noexcept = delete;

	void SetExp(float _Exp)
	{
		ExpAmount = _Exp;
	}

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void AttactCheckLogic();
	void ChasePlayerLogic(float _DeltaTime);
	void ColLogic();
	void SpriteUpdate();

	FVector MoveVector = FVector::Zero;
	float Accel = 300.f;
	float Speed = 0.f;


	float ExpAmount = 0.f;
	bool AttractOn = false;
private:

};

