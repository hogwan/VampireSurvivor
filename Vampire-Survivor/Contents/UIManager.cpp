#include "PreCompile.h"
#include "UImanager.h"
#include "EquipManager.h"
#include "Weapon.h"
#include "Accessory.h"
#include "Player.h"

UIManager::UIManager() 
{
}

UIManager::~UIManager() 
{
}

void UIManager::BeginPlay()
{
	Super::BeginPlay();
	UISpawn();
}

void UIManager::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	UIUpdate();
}


void UIManager::UISpawn()
{
	HPBar = CreateWidget<UImage>(GetWorld(), "HPBar");
	HPBar->AddToViewPort(1);
	HPBar->SetSprite("HpBar.png");
	HPBar->SetScale({ 54.f,7.f });
	HPBar->SetPosition(FVector(0.f, -30.f));

	HPBarBack = CreateWidget<UImage>(GetWorld(), "HPBarBack");
	HPBarBack->AddToViewPort(0);
	HPBarBack->SetSprite("HpBar2.png");
	HPBarBack->SetScale({ 54.f,7.f });
	HPBarBack->SetPosition(FVector(0.f, -30.f));

	LevelBar = CreateWidget<UImage>(GetWorld(), "LevelBar");
	LevelBar->AddToViewPort(1);
	LevelBar->SetSprite("Level.png");
	LevelBar->SetScale(FVector(1270.f, 22.f));
	LevelBar->SetPosition(FVector(0.f, 344.f));
	LevelBar->SetPlusColor({ 0.2f,0.2f,0.5f,1.0f });

	LevelBarBack = CreateWidget<UImage>(GetWorld(), "LevelBarBack");
	LevelBarBack->AddToViewPort(0);
	LevelBarBack->SetSprite("LevelBar.png");
	LevelBarBack->SetScale(FVector(1280.f, 32.f));
	LevelBarBack->SetPosition(FVector(0.f, 344.f));

	for (int i = 0; i < 6; i++)
	{
		UImage* EquipTileBack = CreateWidget<UImage>(GetWorld(), "EquipTileBack");
		EquipTileBack->AddToViewPort(1);
		EquipTileBack->SetSprite("EquipedTile.png", 0);
		EquipTileBack->SetScale(FVector(28.f, 28.f));
		EquipTileBack->SetPosition(FVector(-620.f + 32.f * i, 310.f));
		EquipTileBack->SetMulColor({ 1.f,1.f,1.f,0.7f });
		WeaponTilesBack.push_back(EquipTileBack);

		UImage* EquipTile = CreateWidget<UImage>(GetWorld(), "EquipTile");
		EquipTile->AddToViewPort(2);
		EquipTile->SetAutoSize(2.f, true);
		EquipTile->SetPosition(FVector(-620.f + 32.f * i, 310.f));
		EquipTile->SetActive(false);
		WeaponTiles.push_back(EquipTile);
	}

	for (int i = 0; i < 6; i++)
	{
		UImage* EquipTileBack = CreateWidget<UImage>(GetWorld(), "EquipTileBack");
		EquipTileBack->AddToViewPort(1);
		EquipTileBack->SetSprite("EquipedTile.png", 1);
		EquipTileBack->SetScale(FVector(28.f, 28.f));
		EquipTileBack->SetPosition(FVector(-620.f + 32.f * i, 278.f));
		EquipTileBack->SetMulColor({ 1.f,1.f,1.f,0.7f });
		AccessoryTilesBack.push_back(EquipTileBack);

		UImage* EquipTile = CreateWidget<UImage>(GetWorld(), "EquipTile");
		EquipTile->AddToViewPort(2);
		EquipTile->SetScale(FVector(28.f, 28.f));
		EquipTile->SetPosition(FVector(-620.f + 32.f * i, 278.f));
		EquipTile->SetActive(false);
		AccessoryTiles.push_back(EquipTile);
	}


	Gold = CreateWidget<UImage>(GetWorld(), "Gold");
	Gold->AddToViewPort(1);
	Gold->SetSprite("Gold.png");
	Gold->SetScale(FVector(18.f, 18.f));
	Gold->SetPosition(FVector(620.f, 315.f));
	Gold->SetPlusColor({ 0.2f,0.2f,0.2f });

	KillCount = CreateWidget<UImage>(GetWorld(), "KillCount");
	KillCount->AddToViewPort(1);
	KillCount->SetSprite("KillCount.png");
	KillCount->SetScale(FVector(12.f, 12.f));
	KillCount->SetPosition(FVector(400.f, 315.f));

	WeaponInfoBackBoard = CreateWidget<UImage>(GetWorld(), "WeaponInfoBackBoard");
	WeaponInfoBackBoard->AddToViewPort(2);
	WeaponInfoBackBoard->SetSprite("BlankBoard.png");
	WeaponInfoBackBoard->SetScale(FVector(240.f, 160.f));
	WeaponInfoBackBoard->SetPosition(FVector(-500.f, 235.f));
	WeaponInfoBackBoard->SetPlusColor({ 0.2f,0.2f,0.2f });
	WeaponInfoBackBoard->SetMulColor({ 1.f,1.f,1.f,0.8f });

	PlayerStatusInfoBackBoard = CreateWidget<UImage>(GetWorld(), "PlayerStatusInfoBackBoard");
	PlayerStatusInfoBackBoard->AddToViewPort(2);
	PlayerStatusInfoBackBoard->SetSprite("BlankBoard.png");
	PlayerStatusInfoBackBoard->SetScale(FVector(240.f, 350.f));
	PlayerStatusInfoBackBoard->SetPosition(FVector(-500.f, -20.f));
	PlayerStatusInfoBackBoard->SetPlusColor({ 0.2f,0.2f,0.2f });
	PlayerStatusInfoBackBoard->SetMulColor({ 1.f,1.f,1.f,0.8f });

	LevelUpBackBoard = CreateWidget<UImage>(GetWorld(), "LevelUpBackBoard");
	LevelUpBackBoard->AddToViewPort(2);
	LevelUpBackBoard->SetSprite("LevelUpMenu.png");
	LevelUpBackBoard->SetScale(FVector(346.f, 460.f));
	LevelUpBackBoard->SetPosition(FVector(0.f, 0.f));

	
	LevelUpList.resize(5);
	for (int i = -1; i < 2; i++)
	{
		UImage* LevelUpUnit = CreateWidget<UImage>(GetWorld(), "LevelUpBackBoard");
		LevelUpUnit->AddToViewPort(3);
		LevelUpUnit->SetSprite("LevelUpMenuButton1.png");
		LevelUpUnit->SetScale(FVector(328.f, 99.f));
		LevelUpUnit->SetPosition(FVector(0.f, 99.f * i));

		LevelUpList[0].push_back(LevelUpUnit);
	}

}

void UIManager::UIUpdate()
{
	UIHPUpdate();
	UILevelUpdate();
	WeaponTilesUpdate();
	AccessoryTilesUpdate();

}

void UIManager::UIHPUpdate()
{
	FPlayerData PlayerData = UContentsValue::Player->GetPlayerDataCopy();
	float Ratio = PlayerData.Hp / PlayerData.MaxHealth;
	float Origin = 54.f;

	float Scale = Origin * Ratio;
	HPBar->SetScale({ Scale, HPBar->GetLocalScale().Y });

	float LeftX = (Origin - Scale) / 2.f;
	HPBar->SetPosition({ -LeftX ,-30.f });
}

void UIManager::UILevelUpdate()
{
	FPlayerData PlayerData = UContentsValue::Player->GetPlayerDataCopy();
	float Ratio = PlayerData.CurExp / PlayerData.TargetExp;
	float Origin = 1270.f;

	float Scale = Origin * Ratio;
	LevelBar->SetScale({ Scale, LevelBar->GetLocalScale().Y });

	float LeftX = (Origin - Scale) / 2.f;
	LevelBar->SetPosition({ -LeftX ,344.f });
}

void UIManager::WeaponTilesUpdate()
{
	int i = 0;
	for (std::pair<EWeapon, std::shared_ptr<UWeapon>> _Weapon : UEquipManager::Weapons)
	{
		WeaponTiles[i]->SetActive(true);

		switch (_Weapon.first)
		{
		case EWeapon::Axe:
			WeaponTiles[i]->SetSprite("AxeSprite.png");
			break;
		case EWeapon::Cross:
			WeaponTiles[i]->SetSprite("CrossSprite.png");
			break;
		case EWeapon::FireWand:
			WeaponTiles[i]->SetSprite("FireWandSprite.png");
			break;
		case EWeapon::Garlic:
			WeaponTiles[i]->SetSprite("GarlicSprite.png");
			break;
		case EWeapon::KingBible:
			WeaponTiles[i]->SetSprite("KingBibleSprite.png");
			break;
		case EWeapon::Knife:
			WeaponTiles[i]->SetSprite("KnifeSprite.png");
			break;
		case EWeapon::LightingRing:
			WeaponTiles[i]->SetSprite("LightingRingSprite.png");
			break;
		case EWeapon::MagicWand:
			WeaponTiles[i]->SetSprite("MagicWandSprite.png");
			break;
		case EWeapon::RuneTracer:
			WeaponTiles[i]->SetSprite("RuneTracerSprite.png");
			break;
		case EWeapon::SantaWater:
			WeaponTiles[i]->SetSprite("SantaWaterSprite.png");
			break;
		case EWeapon::Whip:
			WeaponTiles[i]->SetSprite("WhipSprite.png");
			break;
		default:
			break;
		}
		i++;
	}
}

void UIManager::AccessoryTilesUpdate()
{
	int i = 0;
	for (std::pair<EAccessory, std::shared_ptr<UAccessory>> _Accessory : UEquipManager::Accessories)
	{
		AccessoryTiles[i]->SetActive(true);
		switch (_Accessory.first)
		{
		case EAccessory::Armor:
			AccessoryTiles[i]->SetSprite("ArmorSprite.png");
			break;
		case EAccessory::Attractorb:
			AccessoryTiles[i]->SetSprite("AttractorbSprite.png");
			break;
		case EAccessory::Bracer:
			AccessoryTiles[i]->SetSprite("BracerSprite.png");
			break;
		case EAccessory::Candelabrador:
			AccessoryTiles[i]->SetSprite("CandelabradorSprite.png");
			break;
		case EAccessory::Clover:
			AccessoryTiles[i]->SetSprite("CloverSprite.png");
			break;
		case EAccessory::Duplicator:
			AccessoryTiles[i]->SetSprite("DuplicatorSprite.png");
			break;
		case EAccessory::EmptyTome:
			AccessoryTiles[i]->SetSprite("EmptyTomeSprite.png");
			break;
		case EAccessory::HollowHeart:
			AccessoryTiles[i]->SetSprite("HollowHeartSprite.png");
			break;
		case EAccessory::Pummarola:
			AccessoryTiles[i]->SetSprite("PummarolaSprite.png");
			break;
		case EAccessory::Spellbinder:
			AccessoryTiles[i]->SetSprite("SpellbinderSprite.png");
			break;
		case EAccessory::Spinach:
			AccessoryTiles[i]->SetSprite("SpinachSprite.png");
			break;
		case EAccessory::Wings:
			AccessoryTiles[i]->SetSprite("WingsSprite.png");
			break;
		default:
			break;
		}
		i++;
	}
}

void UIManager::LevelUpEvent()
{
	GEngine->SetGlobalTimeScale(0.f);
}
