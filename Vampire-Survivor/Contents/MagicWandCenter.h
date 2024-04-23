#pragma once
#include "WeaponCenter.h"

// ���� :
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

	float ShootTerm = 0.1f;
	float RemainTime = 0.f;
	class AEnemy* DetectNearest();
	void ShootLogic();
	int ShootCount = 0;

	class AEnemy* Target = nullptr;
	std::vector<std::shared_ptr<class AMagicWandUnit>> ProjectileStack;
private:

};

