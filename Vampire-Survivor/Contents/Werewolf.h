#pragma once
#include "Enemy.h"

// Ό³Έν :
class AWerewolf : public AEnemy
{
	GENERATED_BODY(AEnemy)
public:
	// constructor destructor
	AWerewolf();
	~AWerewolf();

	// delete Function
	AWerewolf(const AWerewolf& _Other) = delete;
	AWerewolf(AWerewolf&& _Other) noexcept = delete;
	AWerewolf& operator=(const AWerewolf& _Other) = delete;
	AWerewolf& operator=(AWerewolf&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:

};

