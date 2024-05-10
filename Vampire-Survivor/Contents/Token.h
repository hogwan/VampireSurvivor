#pragma once
#include "AttractItem.h"

// Ό³Έν :
class Token : public AttractItem
{
	GENERATED_BODY(AttractItem)
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

