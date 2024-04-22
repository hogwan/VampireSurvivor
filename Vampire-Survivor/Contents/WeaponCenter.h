#pragma once
#include <EngineCore/Actor.h>
#include "Weapon.h"

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

	void SetData(FWeaponData _Data)
	{
		Data = _Data;
	}

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	UDefaultSceneComponent* Root = nullptr;
	FWeaponData Data = { 0, };
	

private:

};