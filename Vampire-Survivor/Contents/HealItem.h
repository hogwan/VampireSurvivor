#pragma once
#include "AttractItem.h"

// Ό³Έν :
class HealItem : public AttractItem
{
	GENERATED_BODY(AttractItem)
public:
	// constructor destructor
	HealItem();
	~HealItem();

	// delete Function
	HealItem(const HealItem& _Other) = delete;
	HealItem(HealItem&& _Other) noexcept = delete;
	HealItem& operator=(const HealItem& _Other) = delete;
	HealItem& operator=(HealItem&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void ColLogic() override;
private:

};

