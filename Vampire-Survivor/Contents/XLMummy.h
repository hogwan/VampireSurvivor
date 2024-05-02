#pragma once
#include "Enemy.h"

// Ό³Έν :
class AXLMummy : public AEnemy
{
	GENERATED_BODY(AEnemy)
public:
	// constructor destructor
	AXLMummy();
	~AXLMummy();

	// delete Function
	AXLMummy(const AXLMummy& _Other) = delete;
	AXLMummy(AXLMummy&& _Other) noexcept = delete;
	AXLMummy& operator=(const AXLMummy& _Other) = delete;
	AXLMummy& operator=(AXLMummy&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:

};

