#pragma once
#include "Coin.h"

// Ό³Έν :
class SilverCoin : public Coin
{
	GENERATED_BODY(Coin)
public:
	// constructor destructor
	SilverCoin();
	~SilverCoin();

	// delete Function
	SilverCoin(const SilverCoin& _Other) = delete;
	SilverCoin(SilverCoin&& _Other) noexcept = delete;
	SilverCoin& operator=(const SilverCoin& _Other) = delete;
	SilverCoin& operator=(SilverCoin&& _Other) noexcept = delete;

protected:

private:

};

