#pragma once
#include "Item.h"

// Ό³Έν :
class Torch : public Item
{
	GENERATED_BODY(Item)
public:
	// constructor destructor
	Torch();
	~Torch();

	// delete Function
	Torch(const Torch& _Other) = delete;
	Torch(Torch&& _Other) noexcept = delete;
	Torch& operator=(const Torch& _Other) = delete;
	Torch& operator=(Torch&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void ColLogic() override;

	EDropItemOrder Random = EDropItemOrder::None;
private:

};

