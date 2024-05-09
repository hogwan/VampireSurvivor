#pragma once
#include "Coin.h"

// Ό³Έν :
class ASilverCoin : public ACoin
{
	GENERATED_BODY(ACoin)
public:
	// constructor destructor
	ASilverCoin();
	~ASilverCoin();

	// delete Function
	ASilverCoin(const ASilverCoin& _Other) = delete;
	ASilverCoin(ASilverCoin&& _Other) noexcept = delete;
	ASilverCoin& operator=(const ASilverCoin& _Other) = delete;
	ASilverCoin& operator=(ASilverCoin&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;


private:

};

