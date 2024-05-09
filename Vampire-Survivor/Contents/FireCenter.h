#pragma once
#include <EngineCore/Actor.h>

class FireCenter : public AActor
{
	GENERATED_BODY(AActor)
public:
	FireCenter();
	~FireCenter();

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void ShootFire();

	UDefaultSceneComponent* Root = nullptr;

	FVector DirVector = FVector::Zero;
	float ShootCooldown = 0.05f;
	float ShootAcc = 0.f;
};

