#pragma once
#include <EngineCore/Image.h>

// Ό³Έν :
class ACoin : public UImage
{
	GENERATED_BODY(UImage)
public:
	// constructor destructor
	ACoin();
	~ACoin();

	// delete Function
	ACoin(const ACoin& _Other) = delete;
	ACoin(ACoin&& _Other) noexcept = delete;
	ACoin& operator=(const ACoin& _Other) = delete;
	ACoin& operator=(ACoin&& _Other) noexcept = delete;

	inline void SetInitialVector(FVector _InitVec, float _ThrowPower)
	{
		MoveVector = _InitVec * _ThrowPower;
		SetActive(true);
		ChangeAnimation("Spin");
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

