#pragma once
#include "WeaponCenter.h"
#include "KingBible.h"
class AKingBibleCenter : public AWeaponCenter
{
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

	void DataInit() override;
	void LevelUp() override;

	void PushBible();
	void PosInit();
	void SpawnBible();
	void DestroyBible();
	void BiblePosUpdate();
	void RotateBible(float _DeltaTime);

	

	std::vector<std::shared_ptr<UDefaultSceneComponent>> PositionInfo;
	std::vector<std::shared_ptr<AKingBible>> Bibles;

private:

};