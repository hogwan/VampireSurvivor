#pragma once
#include <EngineCore/Image.h>

// Ό³Έν :
class CircuitWeapon : public UImage
{
	GENERATED_BODY(UImage)
public:
	// constructor destructor
	CircuitWeapon();
	~CircuitWeapon();

	// delete Function
	CircuitWeapon(const CircuitWeapon& _Other) = delete;
	CircuitWeapon(CircuitWeapon&& _Other) noexcept = delete;
	CircuitWeapon& operator=(const CircuitWeapon& _Other) = delete;
	CircuitWeapon& operator=(CircuitWeapon&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	FVector UVVector = FVector::Zero;

private:

};

