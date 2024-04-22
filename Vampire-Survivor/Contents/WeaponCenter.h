#pragma once
#include <EngineCore/Actor.h>

struct FWeaponData
{
public:
	int Level;
	int Amount;
	int Penetration;
	float Damage;
	float Speed;
	float Duration;
	float Area;
	float Cooldown;
	float KnockbackPower;
};

class AWeaponCenter : public AActor
{
	GENERATED_BODY(AActor)
public:
	//constructer destructer
	AWeaponCenter();
	~AWeaponCenter();

	//delete Function
	AWeaponCenter(const AWeaponCenter& _Other) = delete;
	AWeaponCenter(AWeaponCenter&& _Other) noexcept = delete;
	AWeaponCenter& operator=(const AWeaponCenter& _Other) = delete;
	AWeaponCenter& operator=(AWeaponCenter&& _Other) noexcept = delete;


	FWeaponData GetData()
	{
		return Data;
	}

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	virtual void DataInit() = 0;
	virtual void LevelUp() = 0;

	UDefaultSceneComponent* Root = nullptr;

	FWeaponData Data = { 0, };

private:

};