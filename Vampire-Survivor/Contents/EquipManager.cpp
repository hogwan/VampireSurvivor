#include "PreCompile.h"
#include "EquipManager.h"
#include "Player.h"
#include "KingBible.h"
#include "MagicWand.h"
#include "Whip.h"
#include "Knife.h"
#include "Axe.h"
#include "Cross.h"
#include "FireWand.h"
#include "Garlic.h"
#include "SantaWater.h"
#include "RuneTracer.h"
#include "LightingRing.h"
#include "Armor.h"
#include "Attractorb.h"
#include "Bracer.h"
#include "Candelabrador.h"
#include "Clover.h"
#include "Duplicator.h"
#include "EmptyTome.h"
#include "HollowHeart.h"
#include "Pummarola.h"
#include "Spellbinder.h"
#include "Spinach.h"
#include "Wings.h"

std::vector<std::pair<EWeapon, std::shared_ptr<UWeapon>>> UEquipManager::Weapons;
std::vector<std::pair<EAccessory, std::shared_ptr<UAccessory>>> UEquipManager::Accessories;

UEquipManager::UEquipManager() 
{
}

UEquipManager::~UEquipManager() 
{
}


void UEquipManager::BeginPlay()
{
	Super::BeginPlay();
}

void UEquipManager::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}
void UEquipManager::EquipWeapon(EWeapon _Weapon)
{
	int Equipsize = static_cast<int>(Weapons.size());

	for (std::pair<EWeapon, std::shared_ptr<UWeapon>> _WeaponPair : Weapons)
	{
		if (_WeaponPair.first == _Weapon)
		{
			_WeaponPair.second->LevelUp();
			_WeaponPair.second->ApplyStatus(UContentsValue::Player->GetPlayerDataCopy());
			return;
		}
	}

	if (Equipsize < EquipCapacity)
	{
		std::shared_ptr<UWeapon> Weapon = SpawnWeapon(_Weapon);
		Weapon->DataInit();
		Weapon->ApplyStatus(UContentsValue::Player->GetPlayerDataCopy());
		Weapons.push_back(std::make_pair(_Weapon, Weapon));
		return;
	}

#ifdef _DEBUG
	MsgBoxAssert("무기 인벤토리가 꽉 찼는데 추가하려고 했습니다.");
#endif
}

void UEquipManager::EquipAccessory(EAccessory _Accessory)
{
	int Equipsize = static_cast<int>(Accessories.size());

	for (std::pair<EAccessory, std::shared_ptr<UAccessory>> _AccessoryPair : Accessories)
	{
		if (_AccessoryPair.first == _Accessory)
		{
			_AccessoryPair.second->LevelUp();
			AccessoryApply();
			return;
		}
	}

	if (Equipsize < EquipCapacity)
	{
		std::shared_ptr<UAccessory> Accessory= SpawnAccessory(_Accessory);
		Accessories.push_back(std::make_pair(_Accessory, Accessory));
		AccessoryApply();
		return;
	}

#ifdef _DEBUG
	MsgBoxAssert("악세서리 인벤토리가 꽉 찼는데 추가하려고 했습니다.");
#endif
}

void UEquipManager::StatusApplyToWeapon()
{
	std::shared_ptr<APlayer> Player = UContentsValue::Player;
	FPlayerData Data = Player->GetPlayerDataCopy();

	for (std::pair<EWeapon, std::shared_ptr<UWeapon>> _WeaponPair : Weapons)
	{
		_WeaponPair.second->ApplyStatus(Data);
	}

}
void UEquipManager::AccessoryApply()
{
	std::shared_ptr<APlayer> Player = UContentsValue::Player;
	FPlayerData* Data = Player->GetPlayerDataReference();
	FAccessoryData AccessoryData = GetAccessoryResult();

	Data->MaxHealth += AccessoryData.MaxHealth;
	Data->Recovery += AccessoryData.Recovery;
	Data->Armor += AccessoryData.Armor;
	Data->MoveSpeed *= AccessoryData.MoveSpeed;
	Data->Might += AccessoryData.Might;
	Data->Speed += AccessoryData.Speed;
	Data->Duration += AccessoryData.Duration;
	Data->Area += AccessoryData.Area;
	Data->Cooldown += AccessoryData.Cooldown;
	Data->Magnet *= AccessoryData.Magnet;
	Data->Luck += AccessoryData.Luck;
	Data->Growth += AccessoryData.Growth;
	Data->Greed += AccessoryData.Greed;
	Data->Curse += AccessoryData.Curse;
	Data->Amount += AccessoryData.Amount;
}

FAccessoryData UEquipManager::GetAccessoryResult()
{
	FAccessoryData Result;

	for (std::pair<EAccessory, std::shared_ptr<UAccessory>> _AccessoryPair : Accessories)
	{
		Result += _AccessoryPair.second->GetData();
	}

	return Result;
}

std::shared_ptr<UWeapon> UEquipManager::SpawnWeapon(EWeapon _WeaponType)
{
	std::shared_ptr<UWeapon> Weapon = nullptr;
	switch (_WeaponType)
	{
	case EWeapon::Axe:
		Weapon = GetWorld()->SpawnActor<UAxe>("Axe");
		break;
	case EWeapon::Cross:
		Weapon = GetWorld()->SpawnActor<UCross>("Cross");
		break;
	case EWeapon::FireWand:
		Weapon = GetWorld()->SpawnActor<UFireWand>("FireWand");
		break;
	case EWeapon::Garlic:
		Weapon = GetWorld()->SpawnActor<UGarlic>("Garlic");
		break;
	case EWeapon::KingBible:
		Weapon = GetWorld()->SpawnActor<UKingBible>("KingBible");
		break;
	case EWeapon::Knife:
		Weapon = GetWorld()->SpawnActor<UKnife>("Knife");
		break;
	case EWeapon::LightingRing:
		Weapon = GetWorld()->SpawnActor<ULightingRing>("LightingRing");
		break;
	case EWeapon::MagicWand:
		Weapon = GetWorld()->SpawnActor<UMagicWand>("MagicWand");
		break;
	case EWeapon::RuneTracer:
		Weapon = GetWorld()->SpawnActor<URuneTracer>("RuneTracer");
		break;
	case EWeapon::SantaWater:
		Weapon = GetWorld()->SpawnActor<USantaWater>("SantaWater");
		break;
	case EWeapon::Whip:
		Weapon = GetWorld()->SpawnActor<UWhip>("Whip");
		break;
	default:
		break;
	}

#ifdef _DEBUG
	if (Weapon == nullptr)
	{
		MsgBoxAssert("없는 무기를 생성하려고 했습니다.");
	}
#endif


	return Weapon;

}

std::shared_ptr<UAccessory> UEquipManager::SpawnAccessory(EAccessory _AccessoryType)
{
	std::shared_ptr<UAccessory> Accessory = nullptr;

	switch (_AccessoryType)
	{
	case EAccessory::Armor:
		Accessory = GetWorld()->SpawnActor<UArmor>("Armor");
		break;
	case EAccessory::Attractorb:
		Accessory = GetWorld()->SpawnActor<UAttractorb>("Attractorb");
		break;
	case EAccessory::Bracer:
		Accessory = GetWorld()->SpawnActor<UBracer>("Bracer");
		break;
	case EAccessory::Candelabrador:
		Accessory = GetWorld()->SpawnActor<UCandelabrador>("Candelabrador");
		break;
	case EAccessory::Clover:
		Accessory = GetWorld()->SpawnActor<UClover>("Clover");
		break;
	case EAccessory::Duplicator:
		Accessory = GetWorld()->SpawnActor<UDuplicator>("Duplicator");
		break;
	case EAccessory::EmptyTome:
		Accessory = GetWorld()->SpawnActor<UEmptyTome>("EnptyTome");
		break;
	case EAccessory::HollowHeart:
		Accessory = GetWorld()->SpawnActor<UHollowHeart>("HollowHeart");
		break;
	case EAccessory::Pummarola:
		Accessory = GetWorld()->SpawnActor<UPummarola>("Pummarola");
		break;
	case EAccessory::Spellbinder:
		Accessory = GetWorld()->SpawnActor<USpellbinder>("Spellbinder");
		break;
	case EAccessory::Spinach:
		Accessory = GetWorld()->SpawnActor<USpinach>("Spinach");
		break;
	case EAccessory::Wings:
		Accessory = GetWorld()->SpawnActor<UWings>("Wings");
		break;
	default:
		break;
	}

#ifdef _DEBUG
	if (Accessory == nullptr)
	{
		MsgBoxAssert("없는 악세서리를 생성하려고 했습니다.");
	}
#endif
	return Accessory;
}


