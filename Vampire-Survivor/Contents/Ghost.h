#pragma once
#include "Enemy.h"

// Ό³Έν :
class AGhost : public AEnemy
{
	GENERATED_BODY(AEnemy)
public:
	// constructor destructor
	AGhost();
	~AGhost();

	// delete Function
	AGhost(const AGhost& _Other) = delete;
	AGhost(AGhost&& _Other) noexcept = delete;
	AGhost& operator=(const AGhost& _Other) = delete;
	AGhost& operator=(AGhost&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:

};

