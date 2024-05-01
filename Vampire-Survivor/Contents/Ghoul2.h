#pragma once
#include "Enemy.h"

// Ό³Έν :
class AGhoul2 : public AEnemy
{
	GENERATED_BODY(AEnemy)
public:
	// constructor destructor
	AGhoul2();
	~AGhoul2();

	// delete Function
	AGhoul2(const AGhoul2& _Other) = delete;
	AGhoul2(AGhoul2&& _Other) noexcept = delete;
	AGhoul2& operator=(const AGhoul2& _Other) = delete;
	AGhoul2& operator=(AGhoul2&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:

};

