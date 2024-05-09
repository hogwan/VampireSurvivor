#pragma once
#include <EngineCore/Image.h>

// Ό³Έν :
class Coin : public UImage
{
	GENERATED_BODY(UImage)
public:
	// constructor destructor
	Coin();
	~Coin();

	// delete Function
	Coin(const Coin& _Other) = delete;
	Coin(Coin&& _Other) noexcept = delete;
	Coin& operator=(const Coin& _Other) = delete;
	Coin& operator=(Coin&& _Other) noexcept = delete;

	inline void SetInitialVector(FVector _InitVec, float _ThrowPower)
	{
		MoveVector = _InitVec * _ThrowPower;
	}

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void GravityCheck(float _DeltaTime);
	void ReflectCheck();

	float Gravity = 500.f;

	FVector MoveVector = FVector::Zero;

private:

};

