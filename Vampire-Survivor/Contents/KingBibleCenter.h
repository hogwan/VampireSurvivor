#pragma once
#include "WeaponCenter.h"
#include "KingBibleUnit.h"
class AKingBibleCenter : public AWeaponCenter
{
	GENERATED_BODY(AWeaponCenter)
public:
	//constructer destructer
	AKingBibleCenter();
	~AKingBibleCenter();

	//delete Function
	AKingBibleCenter(const AKingBibleCenter& _Other) = delete;
	AKingBibleCenter(AKingBibleCenter&& _Other) noexcept = delete;
	AKingBibleCenter& operator=(const AKingBibleCenter& _Other) = delete;
	AKingBibleCenter& operator=(AKingBibleCenter&& _Other) noexcept = delete;
protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void PushInfo();
	void PushBible();
	void PosInit();
	void SpawnBible();
	void DestroyBible();
	void BiblePosUpdate();
	void RotateBible(float _DeltaTime);

	std::vector<UDefaultSceneComponent*> PositionInfo;
	std::vector<std::shared_ptr<AKingBibleUnit>> Bibles;

	float AccTime = 0.f;

private:

};