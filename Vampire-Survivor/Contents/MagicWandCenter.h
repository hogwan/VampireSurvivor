#pragma once
#include "WeaponCenter.h"

// Ό³Έν :
class AMagicWandCenter : public AWeaponCenter
{
	GENERATED_BODY(AWeaponCenter)
public:
	// constructor destructor
	AMagicWandCenter();
	~AMagicWandCenter();

	// delete Function
	AMagicWandCenter(const AMagicWandCenter& _Other) = delete;
	AMagicWandCenter(AMagicWandCenter&& _Other) noexcept = delete;
	AMagicWandCenter& operator=(const AMagicWandCenter& _Other) = delete;
	AMagicWandCenter& operator=(AMagicWandCenter&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	float ShootTerm = 0.05f;
	float RemainTime = 0.f;
	void ShootLogic();
	int ShootCount = 0;

	class AEnemy* Target = nullptr;

private:

};

