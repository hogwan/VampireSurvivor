#pragma once
#include "VSObject.h"
class ALightingRingUnit : public AVSObject
{
	GENERATED_BODY(AVSObject)
public:
	//constructer destructer
	ALightingRingUnit();
	~ALightingRingUnit();

	//delete Function
	ALightingRingUnit(const ALightingRingUnit& _Other) = delete;
	ALightingRingUnit(ALightingRingUnit&& _Other) noexcept = delete;
	ALightingRingUnit& operator=(const ALightingRingUnit& _Other) = delete;
	ALightingRingUnit& operator=(ALightingRingUnit&& _Other) noexcept = delete;
protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	float LiveTime = 0.05f;
	bool IsSpawn = false;


	void SpawnThunderShock();
private:

};