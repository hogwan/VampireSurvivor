#pragma once
#include "Enemy.h"

// Ό³Έν :
class AGhoul3 : public AEnemy
{
	GENERATED_BODY(AEnemy)
public:
	// constructor destructor
	AGhoul3();
	~AGhoul3();

	// delete Function
	AGhoul3(const AGhoul3& _Other) = delete;
	AGhoul3(AGhoul3&& _Other) noexcept = delete;
	AGhoul3& operator=(const AGhoul3& _Other) = delete;
	AGhoul3& operator=(AGhoul3&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
private:

};

