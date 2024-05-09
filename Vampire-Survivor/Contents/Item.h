#pragma once
#include "VSObject.h"

// Ό³Έν :
class Item : public AVSObject
{
	GENERATED_BODY(AVSObject)
public:
	// constructor destructor
	Item();
	~Item();

	// delete Function
	Item(const Item& _Other) = delete;
	Item(Item&& _Other) noexcept = delete;
	Item& operator=(const Item& _Other) = delete;
	Item& operator=(Item&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	virtual void ColLogic();
private:

};

