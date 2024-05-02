#pragma once
#include "Enemy.h"

// Ό³Έν :
class AXLBat : public AEnemy
{
	GENERATED_BODY(AEnemy)
public:
	// constructor destructor
	AXLBat();
	~AXLBat();

	// delete Function
	AXLBat(const AXLBat& _Other) = delete;
	AXLBat(AXLBat&& _Other) noexcept = delete;
	AXLBat& operator=(const AXLBat& _Other) = delete;
	AXLBat& operator=(AXLBat&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:

};

