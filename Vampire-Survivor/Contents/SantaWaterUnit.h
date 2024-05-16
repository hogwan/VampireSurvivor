#pragma once
#include "VSObject.h"
#include <EngineCore/StateManager.h>

// Ό³Έν :
class ASantaWaterUnit : public AVSObject
{
	GENERATED_BODY(AVSObject);
public:
	// constructor destructor
	ASantaWaterUnit();
	~ASantaWaterUnit();

	// delete Function
	ASantaWaterUnit(const ASantaWaterUnit& _Other) = delete;
	ASantaWaterUnit(ASantaWaterUnit&& _Other) noexcept = delete;
	ASantaWaterUnit& operator=(const ASantaWaterUnit& _Other) = delete;
	ASantaWaterUnit& operator=(ASantaWaterUnit&& _Other) noexcept = delete;

	void SetTargetPos(FVector _TargetPos)
	{
		TargetPos = _TargetPos;
	}

	UStateManager State;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void ColLogic();
	FVector Gravity = FVector(0.f, -500.f, 0.f);

	float RotationSpeed = 720.f;
	float DamageTerm = 1.f;
	float RemainTime = 0.f;
	float Duration = 0.f;
	FVector TargetPos = FVector::Zero;
	FVector InitialScale = FVector(60.f, 60.f, 10.f);

	void Fall(float _DeltaTime);
	void Broken(float _DeltaTime);
	void Spread(float _DeltaTime);
	void SpawnFlame(float _DeltaTime);
	float FlameSpawnTime = 0.03f;
	float FlameSpawnRemainTime = 0.f;

	void StateInit();
private:

};

