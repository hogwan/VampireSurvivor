#pragma once
#include "Enemy.h"
// Ό³Έν :
class Mummy : public AEnemy
{
	GENERATED_BODY(AEnemy)
public:
	// constructor destructor
	Mummy();
	~Mummy();

	// delete Function
	Mummy(const Mummy& _Other) = delete;
	Mummy(Mummy&& _Other) noexcept = delete;
	Mummy& operator=(const Mummy& _Other) = delete;
	Mummy& operator=(Mummy&& _Other) noexcept = delete;


protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:

};

