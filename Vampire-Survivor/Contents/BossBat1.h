#pragma once
#include "Enemy.h"

// Ό³Έν :
class ABossBat1 : public AEnemy
{
	GENERATED_BODY(AEnemy)
public:
	// constructor destructor
	ABossBat1();
	~ABossBat1();

	// delete Function
	ABossBat1(const ABossBat1& _Other) = delete;
	ABossBat1(ABossBat1&& _Other) noexcept = delete;
	ABossBat1& operator=(const ABossBat1& _Other) = delete;
	ABossBat1& operator=(ABossBat1&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:

};

