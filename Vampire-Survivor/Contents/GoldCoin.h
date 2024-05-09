#pragma once
#include "Coin.h"

// Ό³Έν :
class AGoldCoin : public ACoin
{
	GENERATED_BODY(ACoin)
public:
	// constructor destructor
	AGoldCoin();
	~AGoldCoin();

	// delete Function
	AGoldCoin(const AGoldCoin& _Other) = delete;
	AGoldCoin(AGoldCoin&& _Other) noexcept = delete;
	AGoldCoin& operator=(const AGoldCoin& _Other) = delete;
	AGoldCoin& operator=(AGoldCoin&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;



private:

};

