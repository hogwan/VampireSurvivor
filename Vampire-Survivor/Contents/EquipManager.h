#pragma once
#include <EngineCore/Actor.h>
#include "Weapon.h"
#include "Accessory.h"

// Ό³Έν :
class UEquipManager
	: public AActor
{
	GENERATED_BODY(AActor)
public:
	// constructor destructor
	UEquipManager();
	~UEquipManager();

	// delete Function
	UEquipManager(const UEquipManager& _Other) = delete;
	UEquipManager(UEquipManager&& _Other) noexcept = delete;
	UEquipManager& operator=(const UEquipManager& _Other) = delete;
	UEquipManager& operator=(UEquipManager&& _Other) noexcept = delete;

	static std::vector<std::pair<EWeapon, std::shared_ptr<UWeapon>>> Weapons;
	static std::vector<std::pair<EAccessory, std::shared_ptr<UAccessory>>> Accessories;

	void EquipWeapon(EWeapon _WeaponType);
	void EquipAccessory(EAccessory _AccessoryType);

	void AccessoryApply();
	void StatusApplyToWeapon();

	std::shared_ptr<UWeapon> SpawnWeapon(EWeapon _WeaponType);
	std::shared_ptr<UAccessory> SpawnAccessory(EAccessory _AccessoryType);
	
	FAccessoryData GetAccessoryResult();
protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	int EquipCapacity = 6;
};

