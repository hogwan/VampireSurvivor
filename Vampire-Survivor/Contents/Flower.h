#pragma once
#include "Enemy.h"

// Ό³Έν :
class AFlower : public AEnemy
{
	GENERATED_BODY(AEnemy)
public:
	// constructor destructor
	AFlower();
	~AFlower();

	// delete Function
	AFlower(const AFlower& _Other) = delete;
	AFlower(AFlower&& _Other) noexcept = delete;
	AFlower& operator=(const AFlower& _Other) = delete;
	AFlower& operator=(AFlower&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
private:

};

