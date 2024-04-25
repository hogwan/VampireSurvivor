#pragma once
#include "Weapon.h"

// Ό³Έν :
class UMagicWand : public UWeapon
{
	GENERATED_BODY(UWeapon)
public:
	// constructor destructor
	UMagicWand();
	~UMagicWand();

	// delete Function
	UMagicWand(const UMagicWand& _Other) = delete;
	UMagicWand(UMagicWand&& _Other) noexcept = delete;
	UMagicWand& operator=(const UMagicWand& _Other) = delete;
	UMagicWand& operator=(UMagicWand&& _Other) noexcept = delete;

	static FWeaponData Data;
protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void DataInit() override;
	void LevelUp() override;

	void SpawnCenter() override;
	void ApplyStatus(struct FPlayerData _Data) override;
private:

};

