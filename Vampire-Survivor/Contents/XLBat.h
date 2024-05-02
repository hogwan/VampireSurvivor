#pragma once
#include "Enemy.h"

// Ό³Έν :
class XLBat : public AEnemy
{
	GENERATED_BODY(AEnemy)
public:
	// constructor destructor
	XLBat();
	~XLBat();

	// delete Function
	XLBat(const XLBat& _Other) = delete;
	XLBat(XLBat&& _Other) noexcept = delete;
	XLBat& operator=(const XLBat& _Other) = delete;
	XLBat& operator=(XLBat&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:

};

