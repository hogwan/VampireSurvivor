#pragma once
#include "WeaponCenter.h"

// Ό³Έν :
class AKnifeCenter : public AWeaponCenter
{
	GENERATED_BODY(AWeaponCenter)
public:
	// constructor destructor
	AKnifeCenter();
	~AKnifeCenter();

	// delete Function
	AKnifeCenter(const AKnifeCenter& _Other) = delete;
	AKnifeCenter(AKnifeCenter&& _Other) noexcept = delete;
	AKnifeCenter& operator=(const AKnifeCenter& _Other) = delete;
	AKnifeCenter& operator=(AKnifeCenter&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	float Offset = 5.f;
	float SpawnInterval = 0.2f;
	float RemainTime = 0.f;
	int RemainKnifeCount = 0;

	bool UpSpawn = true;
	void UnitSpawnLogic() override;

private:

};

