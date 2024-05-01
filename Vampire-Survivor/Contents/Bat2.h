#pragma once
#include "Enemy.h"

// Ό³Έν :
class ABat2 : public AEnemy
{
	GENERATED_BODY(AEnemy)
public:
	// constructor destructor
	ABat2();
	~ABat2();

	// delete Function
	ABat2(const ABat2& _Other) = delete;
	ABat2(ABat2&& _Other) noexcept = delete;
	ABat2& operator=(const ABat2& _Other) = delete;
	ABat2& operator=(ABat2&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:

};

