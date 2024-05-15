#pragma once
#include "Item.h"

// Ό³Έν :
class Token : public Item
{
	GENERATED_BODY(Item)
public:
	// constructor destructor
	Token();
	~Token();

	// delete Function
	Token(const Token& _Other) = delete;
	Token(Token&& _Other) noexcept = delete;
	Token& operator=(const Token& _Other) = delete;
	Token& operator=(Token&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;

	void Tick(float _DeltaTime) override;

	void ColLogic() override;

private:

};

