#pragma once
#include "Enemy.h"

// Ό³Έν :
class ABat3 : public AEnemy
{
	GENERATED_BODY(AEnemy)
public:
	// constructor destructor
	ABat3();
	~ABat3();

	// delete Function
	ABat3(const ABat3& _Other) = delete;
	ABat3(ABat3&& _Other) noexcept = delete;
	ABat3& operator=(const ABat3& _Other) = delete;
	ABat3& operator=(ABat3&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
private:

};

