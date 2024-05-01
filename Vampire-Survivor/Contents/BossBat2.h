#pragma once
#include "Enemy.h"

// Ό³Έν :
class ABossBat2 : public AEnemy
{
	GENERATED_BODY(AEnemy)
public:
	// constructor destructor
	ABossBat2();
	~ABossBat2();

	// delete Function
	ABossBat2(const ABossBat2& _Other) = delete;
	ABossBat2(ABossBat2&& _Other) noexcept = delete;
	ABossBat2& operator=(const ABossBat2& _Other) = delete;
	ABossBat2& operator=(ABossBat2&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:

};

