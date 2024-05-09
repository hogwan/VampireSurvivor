#pragma once
#include "Item.h"

// Ό³Έν :
class AttractItem : public Item
{
	GENERATED_BODY(Item)
public:
	// constructor destructor
	AttractItem();
	~AttractItem();

	// delete Function
	AttractItem(const AttractItem& _Other) = delete;
	AttractItem(AttractItem&& _Other) noexcept = delete;
	AttractItem& operator=(const AttractItem& _Other) = delete;
	AttractItem& operator=(AttractItem&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void ColLogic() override;

	virtual void AttactCheckLogic();
	void ChasePlayerLogic(float _DeltaTime);

	FVector MoveVector = FVector::Zero;
	float Accel = 300.f;
	float Speed = 0.f;

	bool AttractOn = false;

private:

};

