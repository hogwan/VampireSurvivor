#pragma once
#include <EngineCore/Actor.h>

struct FWeaponData
{
public:
	float Damage;
	float Speed;
	float Duration;
	float Area;
	float Cooldown;
	int Amount;
	int Level;
	int Penetration;
};

class UWeaponCenter : public AActor
{
	GENERATED_BODY(AActor)
public:
	//constructer destructer
	UWeaponCenter();
	~UWeaponCenter();

	//delete Function
	UWeaponCenter(const UWeaponCenter& _Other) = delete;
	UWeaponCenter(UWeaponCenter&& _Other) noexcept = delete;
	UWeaponCenter& operator=(const UWeaponCenter& _Other) = delete;
	UWeaponCenter& operator=(UWeaponCenter&& _Other) noexcept = delete;
protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	UDefaultSceneComponent* Root = nullptr;

	FWeaponData Data = { 0, };

private:

};