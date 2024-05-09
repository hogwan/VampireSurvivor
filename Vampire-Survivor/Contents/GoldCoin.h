#pragma once
#include "Coin.h"

// Ό³Έν :
class GoldCoin : public Coin
{
	GENERATED_BODY(Coin)
public:
	// constructor destructor
	GoldCoin();
	~GoldCoin();

	// delete Function
	GoldCoin(const GoldCoin& _Other) = delete;
	GoldCoin(GoldCoin&& _Other) noexcept = delete;
	GoldCoin& operator=(const GoldCoin& _Other) = delete;
	GoldCoin& operator=(GoldCoin&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:

};

