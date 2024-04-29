#pragma once
#include "WeaponCenter.h"

// Ό³Έν :
class AWhipCenter
	: public AWeaponCenter
{
	GENERATED_BODY(AWeaponCenter)
public:
	// constructor destructor
	AWhipCenter();
	~AWhipCenter();

	// delete Function
	AWhipCenter(const AWhipCenter& _Other) = delete;
	AWhipCenter(AWhipCenter&& _Other) noexcept = delete;
	AWhipCenter& operator=(const AWhipCenter& _Other) = delete;
	AWhipCenter& operator=(AWhipCenter&& _Other) noexcept = delete;

protected:
	void SetData(FWeaponData _Data)
	{
		Data = _Data;
	}

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void WhipSpawnLogic();

	float SecondTerm = 0.1f;

	UDefaultSceneComponent* Root = nullptr;
	FWeaponData Data = { "",};


private:

};

