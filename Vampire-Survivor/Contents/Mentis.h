#pragma once
#include "Enemy.h"

// Ό³Έν :
class AMentis : public AEnemy
{
	GENERATED_BODY(AEnemy);
public:
	// constructor destructor
	AMentis();
	~AMentis();

	// delete Function
	AMentis(const AMentis& _Other) = delete;
	AMentis(AMentis&& _Other) noexcept = delete;
	AMentis& operator=(const AMentis& _Other) = delete;
	AMentis& operator=(AMentis&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:

};

