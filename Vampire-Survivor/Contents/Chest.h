#pragma once
#include "Item.h"

// Ό³Έν :
class Chest : public Item
{
	GENERATED_BODY(Item)
public:
	// constructor destructor
	Chest();
	~Chest();

	// delete Function
	Chest(const Chest& _Other) = delete;
	Chest(Chest&& _Other) noexcept = delete;
	Chest& operator=(const Chest& _Other) = delete;
	Chest& operator=(Chest&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void ColLogic() override;
private:

};

