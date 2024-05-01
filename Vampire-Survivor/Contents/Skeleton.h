#pragma once
#include "Enemy.h"

// Ό³Έν :
class ASkeleton : public AEnemy
{
	GENERATED_BODY(AEnemy)
public:
	// constructor destructor
	ASkeleton();
	~ASkeleton();

	// delete Function
	ASkeleton(const ASkeleton& _Other) = delete;
	ASkeleton(ASkeleton&& _Other) noexcept = delete;
	ASkeleton& operator=(const ASkeleton& _Other) = delete;
	ASkeleton& operator=(ASkeleton&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:

};

