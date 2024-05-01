#pragma once
#include "Enemy.h"

// Ό³Έν :
class AMudman2 : public AEnemy
{
	GENERATED_BODY(AEnemy)
public:
	// constructor destructor
	AMudman2();
	~AMudman2();

	// delete Function
	AMudman2(const AMudman2& _Other) = delete;
	AMudman2(AMudman2&& _Other) noexcept = delete;
	AMudman2& operator=(const AMudman2& _Other) = delete;
	AMudman2& operator=(AMudman2&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:

};

