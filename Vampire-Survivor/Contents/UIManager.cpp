#include "PreCompile.h"
#include "UImanager.h"
#include "EquipManager.h"
#include "Weapon.h"
#include "Accessory.h"
#include "Player.h"
#include "PlayGameMode.h"
#include <EngineBase/EngineRandom.h>

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
	LevelUpUIOff();
}

void UIManager::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	UIUpdate();

	if (IsSelecting)
	{
		LevelUpEventTick();
	}
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

	for (int i = 0; i < 3; i++)
	{
		InfoVec.push_back(ESelectList::None);
	}


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
		LevelUpList[i+1].resize(5);

		UImage* LevelUpUnit = CreateWidget<UImage>(GetWorld(), "LevelUpBackBoard");
		LevelUpUnit->AddToViewPort(3);
		LevelUpUnit->SetSprite("LevelUpMenuButton1.png");
		LevelUpUnit->SetScale(FVector(328.f, 99.f));
		LevelUpUnit->SetPosition(FVector(0.f, -99.f * i));

		LevelUpList[i+1][0] = LevelUpUnit;

		UImage* LevelUpSprite = CreateWidget<UImage>(GetWorld(), "LevelUpSprite");
		LevelUpSprite->AddToViewPort(4);
		LevelUpSprite->SetAutoSize(2.f, true);
		LevelUpSprite->SetPosition(FVector(-140.f, 23.f-99.f * i));

		LevelUpList[i + 1][1] = LevelUpSprite;
	}

	SelectArrows.first = CreateWidget<UImage>(GetWorld(), "ArrowLeft");
	SelectArrows.first->AddToViewPort(4);
	SelectArrows.first->CreateAnimation("Rotate", "Arrow", 0.1f, true);
	SelectArrows.first->SetAutoSize(2.f, true);
	SelectArrows.first->ChangeAnimation("Rotate");


	SelectArrows.second = CreateWidget<UImage>(GetWorld(), "ArrowLeft");
	SelectArrows.second->AddToViewPort(4);
	SelectArrows.second->CreateAnimation("Rotate", "Arrow", 0.1f, true);
	SelectArrows.second->SetAutoSize(2.f, true);
	
	/*FVector Scale = SelectArrows.second->GetLocalScale();
	Scale.X = -Scale.X;
	SelectArrows.second->SetScale(Scale);*/
	SelectArrows.second->SetRotationDeg(FVector(0.f, 0.f, 180.f));
	SelectArrows.second->ChangeAnimation("Rotate");
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

void UIManager::LevelUpEventStart()
{
	GEngine->SetGlobalTimeScale(0.f);
	LevelUpUIOn();
	IsSelecting = true;
	SelectIndex = 0;


	int Min = static_cast<int>(ESelectList::Axe);
	int Max = static_cast<int>(ESelectList::Wings);

	for (int i = 0; i < 3; i++)
	{
		int Random = UEngineRandom::MainRandom.RandomInt(Min, Max);

		ESelectList List = static_cast<ESelectList>(Random);

		switch (List)
		{
		case ESelectList::Axe:
			LevelUpList[i][1]->SetSprite("AxeSprite.png");
			InfoVec[i] = ESelectList::Axe;
			break;
		case ESelectList::Cross:
			LevelUpList[i][1]->SetSprite("CrossSprite.png");
			InfoVec[i] = ESelectList::Cross;
			break;
		case ESelectList::FireWand:
			LevelUpList[i][1]->SetSprite("FireWandSprite.png");
			InfoVec[i] = ESelectList::FireWand;
			break;
		case ESelectList::Garlic:
			LevelUpList[i][1]->SetSprite("GarlicSprite.png");
			InfoVec[i] = ESelectList::Garlic;
			break;
		case ESelectList::KingBible:
			LevelUpList[i][1]->SetSprite("KingBibleSprite.png");
			InfoVec[i] = ESelectList::KingBible;
			break;
		case ESelectList::Knife:
			LevelUpList[i][1]->SetSprite("KnifeSprite.png");
			InfoVec[i] = ESelectList::Knife;
			break;
		case ESelectList::LightingRing:
			LevelUpList[i][1]->SetSprite("LightingRingSprite.png");
			InfoVec[i] = ESelectList::LightingRing;
			break;
		case ESelectList::MagicWand:
			LevelUpList[i][1]->SetSprite("MagicWandSprite.png");
			InfoVec[i] = ESelectList::MagicWand;
			break;
		case ESelectList::RuneTracer:
			LevelUpList[i][1]->SetSprite("RuneTracerSprite.png");
			InfoVec[i] = ESelectList::RuneTracer;
			break;
		case ESelectList::SantaWater:
			LevelUpList[i][1]->SetSprite("SantaWaterSprite.png");
			InfoVec[i] = ESelectList::SantaWater;
			break;
		case ESelectList::Whip:
			LevelUpList[i][1]->SetSprite("WhipSprite.png");
			InfoVec[i] = ESelectList::Whip;
			break;
		case ESelectList::Armor:
			LevelUpList[i][1]->SetSprite("ArmorSprite.png");
			InfoVec[i] = ESelectList::Armor;
			break;
		case ESelectList::Attractorb:
			LevelUpList[i][1]->SetSprite("AttractorbSprite.png");
			InfoVec[i] = ESelectList::Attractorb;
			break;
		case ESelectList::Bracer:
			LevelUpList[i][1]->SetSprite("BracerSprite.png");
			InfoVec[i] = ESelectList::Bracer;
			break;
		case ESelectList::Candelabrador:
			LevelUpList[i][1]->SetSprite("CandelabradorSprite.png");
			InfoVec[i] = ESelectList::Candelabrador;
			break;
		case ESelectList::Clover:
			LevelUpList[i][1]->SetSprite("CloverSprite.png");
			InfoVec[i] = ESelectList::Clover;
			break;
		case ESelectList::Duplicator:
			LevelUpList[i][1]->SetSprite("DuplicatorSprite.png");
			InfoVec[i] = ESelectList::Duplicator;
			break;
		case ESelectList::EmptyTome:
			LevelUpList[i][1]->SetSprite("EmptyTomeSprite.png");
			InfoVec[i] = ESelectList::EmptyTome;
			break;
		case ESelectList::HollowHeart:
			LevelUpList[i][1]->SetSprite("HollowHeartSprite.png");
			InfoVec[i] = ESelectList::HollowHeart;
			break;
		case ESelectList::Pummarola:
			LevelUpList[i][1]->SetSprite("PummarolaSprite.png");
			InfoVec[i] = ESelectList::Pummarola;
			break;
		case ESelectList::Spellbinder:
			LevelUpList[i][1]->SetSprite("SpellbinderSprite.png");
			InfoVec[i] = ESelectList::Spellbinder;
			break;
		case ESelectList::Spinach:
			LevelUpList[i][1]->SetSprite("SpinachSprite.png");
			InfoVec[i] = ESelectList::Spinach;
			break;
		case ESelectList::Wings:
			LevelUpList[i][1]->SetSprite("WingsSprite.png");
			InfoVec[i] = ESelectList::Wings;
			break;
		default:
			break;
		}
	}
}

void UIManager::LevelUpEventEnd()
{
	//레벨업관련 UI 모두 activeoff
	GEngine->SetGlobalTimeScale(1.f);
	IsSelecting = false;
	LevelUpUIOff();
}

void UIManager::LevelUpEventTick()
{
	if (UEngineInput::IsDown(VK_SPACE))
	{
		ESelectList EquipItem = InfoVec[SelectIndex];

		switch (EquipItem)
		{
		case ESelectList::Axe:
			APlayGameMode::EquipManager->EquipWeapon(EWeapon::Axe);
			break;
		case ESelectList::Cross:
			APlayGameMode::EquipManager->EquipWeapon(EWeapon::Cross);
			break;
		case ESelectList::FireWand:
			APlayGameMode::EquipManager->EquipWeapon(EWeapon::FireWand);
			break;
		case ESelectList::Garlic:
			APlayGameMode::EquipManager->EquipWeapon(EWeapon::Garlic);
			break;
		case ESelectList::KingBible:
			APlayGameMode::EquipManager->EquipWeapon(EWeapon::KingBible);
			break;
		case ESelectList::Knife:
			APlayGameMode::EquipManager->EquipWeapon(EWeapon::Knife);
			break;
		case ESelectList::LightingRing:
			APlayGameMode::EquipManager->EquipWeapon(EWeapon::LightingRing);
			break;
		case ESelectList::MagicWand:
			APlayGameMode::EquipManager->EquipWeapon(EWeapon::MagicWand);
			break;
		case ESelectList::RuneTracer:
			APlayGameMode::EquipManager->EquipWeapon(EWeapon::RuneTracer);
			break;
		case ESelectList::SantaWater:
			APlayGameMode::EquipManager->EquipWeapon(EWeapon::SantaWater);
			break;
		case ESelectList::Whip:
			APlayGameMode::EquipManager->EquipWeapon(EWeapon::Whip);
			break;
		case ESelectList::Armor:
			APlayGameMode::EquipManager->EquipAccessory(EAccessory::Armor);
			break;
		case ESelectList::Attractorb:
			APlayGameMode::EquipManager->EquipAccessory(EAccessory::Attractorb);
			break;
		case ESelectList::Bracer:
			APlayGameMode::EquipManager->EquipAccessory(EAccessory::Bracer);
			break;
		case ESelectList::Candelabrador:
			APlayGameMode::EquipManager->EquipAccessory(EAccessory::Candelabrador);
			break;
		case ESelectList::Clover:
			APlayGameMode::EquipManager->EquipAccessory(EAccessory::Clover);
			break;
		case ESelectList::Duplicator:
			APlayGameMode::EquipManager->EquipAccessory(EAccessory::Duplicator);
			break;
		case ESelectList::EmptyTome:
			APlayGameMode::EquipManager->EquipAccessory(EAccessory::EmptyTome);
			break;
		case ESelectList::HollowHeart:
			APlayGameMode::EquipManager->EquipAccessory(EAccessory::HollowHeart);
			break;
		case ESelectList::Pummarola:
			APlayGameMode::EquipManager->EquipAccessory(EAccessory::Pummarola);
			break;
		case ESelectList::Spellbinder:
			APlayGameMode::EquipManager->EquipAccessory(EAccessory::Spellbinder);
			break;
		case ESelectList::Spinach:
			APlayGameMode::EquipManager->EquipAccessory(EAccessory::Spinach);
			break;
		case ESelectList::Wings:
			APlayGameMode::EquipManager->EquipAccessory(EAccessory::Wings);
			break;
		default:
			break;
		}
		LevelUpEventEnd();
	}

	if (UEngineInput::IsDown(VK_UP))
	{
		SelectIndex--;
		if (SelectIndex < 0)
		{
			SelectIndex = 0;
		}
	}

	if (UEngineInput::IsDown(VK_DOWN))
	{
		SelectIndex++;
		if (SelectIndex > 2)
		{
			SelectIndex = 2;
		}
	}

	
	FVector LeftArrowPos = FVector(-200.f, LevelUpList[SelectIndex][0]->GetLocalPosition().Y, 10.f);
	FVector RightArrowPos = FVector(200.f, LevelUpList[SelectIndex][0]->GetLocalPosition().Y, 10.f);
	SelectArrows.first->SetPosition(LeftArrowPos);
	SelectArrows.second->SetPosition(RightArrowPos);
}

void UIManager::LevelUpUIOn()
{
	WeaponInfoBackBoard->SetActive(true);
	PlayerStatusInfoBackBoard->SetActive(true);
	LevelUpBackBoard->SetActive(true);

	for (std::vector<UImage*> ImageVec : WeaponInfo)
	{
		for (UImage* Image : ImageVec)
		{
			if (Image != nullptr)
			{
				Image->SetActive(true);
			}
		}
	}

	for (std::vector<UImage*> ImageVec : AccessoryInfo)
	{
		for (UImage* Image : ImageVec)
		{
			if (Image != nullptr)
			{
				Image->SetActive(true);
			}
		}
	}

	for (std::vector<UImage*> ImageVec : PlayerStatusInfo)
	{
		for (UImage* Image : ImageVec)
		{
			if (Image != nullptr)
			{
				Image->SetActive(true);
			}
		}
	}

	for (std::vector<UImage*> ImageVec : LevelUpList)
	{
		for (UImage* Image : ImageVec)
		{
			if (Image != nullptr)
			{
				Image->SetActive(true);
			}
		}
	}

	SelectArrows.first->SetActive(true);
	SelectArrows.second->SetActive(true);
}

void UIManager::LevelUpUIOff()
{
	WeaponInfoBackBoard->SetActive(false);
	PlayerStatusInfoBackBoard->SetActive(false);
	LevelUpBackBoard->SetActive(false);

	for (std::vector<UImage*> ImageVec : WeaponInfo)
	{
		for (UImage* Image : ImageVec)
		{
			if (Image != nullptr)
			{
				Image->SetActive(false);
			}
		}
	}

	for (std::vector<UImage*> ImageVec : AccessoryInfo)
	{
		for (UImage* Image : ImageVec)
		{
			if (Image != nullptr)
			{
				Image->SetActive(false);
			}
		}
	}

	for (std::vector<UImage*> ImageVec : PlayerStatusInfo)
	{
		for (UImage* Image : ImageVec)
		{
			if (Image != nullptr)
			{
				Image->SetActive(false);
			}
		}
	}

	for (std::vector<UImage*> ImageVec : LevelUpList)
	{
		for (UImage* Image : ImageVec)
		{
			if (Image != nullptr)
			{
				Image->SetActive(false);
			}
		}
	}

	SelectArrows.first->SetActive(false);
	SelectArrows.second->SetActive(false);
}