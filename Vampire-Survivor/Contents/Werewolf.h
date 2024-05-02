#pragma once
#include "Enemy.h"

// Ό³Έν :
class Werewolf : public AEnemy
{
	GENERATED_BODY(AEnemy)
public:
	// constructor destructor
	Werewolf();
	~Werewolf();

	// delete Function
	Werewolf(const Werewolf& _Other) = delete;
	Werewolf(Werewolf&& _Other) noexcept = delete;
	Werewolf& operator=(const Werewolf& _Other) = delete;
	Werewolf& operator=(Werewolf&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:

};

