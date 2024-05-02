#pragma once
#include "Enemy.h"
// Ό³Έν :
class AMummy : public AEnemy
{
	GENERATED_BODY(AEnemy)
public:
	// constructor destructor
	AMummy();
	~AMummy();

	// delete Function
	AMummy(const AMummy& _Other) = delete;
	AMummy(AMummy&& _Other) noexcept = delete;
	AMummy& operator=(const AMummy& _Other) = delete;
	AMummy& operator=(AMummy&& _Other) noexcept = delete;


protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:

};

