#pragma once
#include "Enemy.h"

// Ό³Έν :
class XLMummy : public AEnemy
{
	GENERATED_BODY(AEnemy)
public:
	// constructor destructor
	XLMummy();
	~XLMummy();

	// delete Function
	XLMummy(const XLMummy& _Other) = delete;
	XLMummy(XLMummy&& _Other) noexcept = delete;
	XLMummy& operator=(const XLMummy& _Other) = delete;
	XLMummy& operator=(XLMummy&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:

};

