#pragma once
#include "VSObject.h"

// Ό³Έν :
class AWhipUnit : public AVSObject
{
	GENERATED_BODY(AVSObject)
public:
	// constructor destructor
	AWhipUnit();
	~AWhipUnit();

	// delete Function
	AWhipUnit(const AWhipUnit& _Other) = delete;
	AWhipUnit(AWhipUnit&& _Other) noexcept = delete;
	AWhipUnit& operator=(const AWhipUnit& _Other) = delete;
	AWhipUnit& operator=(AWhipUnit&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void ColLogic();
	void IncreaseLogic(float _DeltaTime);

	FVector InitialScale = FVector(73.f,11.f,10.f);
	FVector MaxScale = FVector(147.f, 22.f, 10.f);
	
	float IncreaseTerm = 0.1f;
	float DestroyTime = 0.15f;

	EEngineDir Dir = EEngineDir::MAX;
	EEngineDir PlayerDir = EEngineDir::MAX;
private:

};

