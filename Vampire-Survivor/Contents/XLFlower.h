#pragma once
#include "Enemy.h"

// Ό³Έν :
class AXLFlower : public AEnemy
{
	GENERATED_BODY(AEnemy)
public:
	// constructor destructor
	AXLFlower();
	~AXLFlower();

	// delete Function
	AXLFlower(const AXLFlower& _Other) = delete;
	AXLFlower(AXLFlower&& _Other) noexcept = delete;
	AXLFlower& operator=(const AXLFlower& _Other) = delete;
	AXLFlower& operator=(AXLFlower&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:

};

