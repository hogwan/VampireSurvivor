#pragma once
#include "VSObject.h"
#include <EngineBase/EngineRandom.h>
class FireUnit : public AVSObject
{
	GENERATED_BODY(AVSObject)
public:
	FireUnit();
	~FireUnit();

	void SetDir(FVector _Dir)
	{
		float RandomRot = UEngineRandom::MainRandom.RandomFloat(-5.f, 5.f);
		_Dir.RotationZToDeg(RandomRot);
		MoveVector = _Dir * Speed;
	}

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
	
	void ColLogic();

	float DamageAmount = 30.f;
	float Speed = 800.f;
	FVector MoveVector = FVector::Zero;
private:
};

