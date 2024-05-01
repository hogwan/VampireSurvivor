#pragma once
#include "Enemy.h"

// Ό³Έν :
class AMudman1 : public AEnemy
{
	GENERATED_BODY(AEnemy)
public:
	// constructor destructor
	AMudman1();
	~AMudman1();

	// delete Function
	AMudman1(const AMudman1& _Other) = delete;
	AMudman1(AMudman1&& _Other) noexcept = delete;
	AMudman1& operator=(const AMudman1& _Other) = delete;
	AMudman1& operator=(AMudman1&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:

};

