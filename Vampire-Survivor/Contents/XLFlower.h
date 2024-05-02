#pragma once
#include "Enemy.h"

// Ό³Έν :
class XLFlower : public AEnemy
{
	GENERATED_BODY(AEnemy)
public:
	// constructor destructor
	XLFlower();
	~XLFlower();

	// delete Function
	XLFlower(const XLFlower& _Other) = delete;
	XLFlower(XLFlower&& _Other) noexcept = delete;
	XLFlower& operator=(const XLFlower& _Other) = delete;
	XLFlower& operator=(XLFlower&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:

};

