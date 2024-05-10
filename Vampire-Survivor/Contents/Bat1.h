#pragma once
#include "Enemy.h"

// Ό³Έν :
class ABat1 : public AEnemy
{
	GENERATED_BODY(AEnemy)
public:
	// constructor destructor
	ABat1();
	~ABat1();

	// delete Function
	ABat1(const ABat1& _Other) = delete;
	ABat1(ABat1&& _Other) noexcept = delete;
	ABat1& operator=(const ABat1& _Other) = delete;
	ABat1& operator=(ABat1&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:

};

