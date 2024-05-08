#pragma once
#include <EngineCore/Actor.h>
#include "Circuit.h"

// Ό³Έν :
class CircuitWeapon : public AActor
{
	GENERATED_BODY(AActor)
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

	std::shared_ptr<ACircuit> CircuitEffect = nullptr;


	FVector vec = FVector::Zero;
	USpriteRenderer* Renderer = nullptr;

private:

};

