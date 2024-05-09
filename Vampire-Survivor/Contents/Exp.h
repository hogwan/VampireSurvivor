#pragma once
#include "AttractItem.h"

// Ό³Έν :
class AExp : public AttractItem
{
	GENERATED_BODY(AttractItem)
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

	void ColLogic();
	void SpriteUpdate();

	void AttactCheckLogic() override;

	float ExpAmount = 0.f;
private:

};

