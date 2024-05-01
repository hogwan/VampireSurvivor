#pragma once
#include "Enemy.h"
// Ό³Έν :
class AGhoul1 : public AEnemy
{
	GENERATED_BODY(AEnemy)
public:
	// constructor destructor
	AGhoul1();
	~AGhoul1();

	// delete Function
	AGhoul1(const AGhoul1& _Other) = delete;
	AGhoul1(AGhoul1&& _Other) noexcept = delete;
	AGhoul1& operator=(const AGhoul1& _Other) = delete;
	AGhoul1& operator=(AGhoul1&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:

};

