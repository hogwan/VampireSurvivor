#include "PreCompile.h"
#include "UImanager.h"
#include "EquipManager.h"
#include "Weapon.h"
#include "Accessory.h"
#include "Player.h"
#include "PlayGameMode.h"
#include <EngineBase/EngineRandom.h>
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
#include "ChestUI.h"
#include "DeathUI.h"

UChestUI* UIManager::ChestUI = nullptr;
UDeathUI* UIManager::DeathUI = nullptr;

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
	TimeUpdate(_DeltaTime);
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

	WeaponInfo.resize(6);
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

		UImage* WeaponInfoTileBack = CreateWidget<UImage>(GetWorld(), "EquipTileBack");
		WeaponInfoTileBack->AddToViewPort(4);
		WeaponInfoTileBack->SetSprite("EquipedTile.png", 0);
		WeaponInfoTileBack->SetScale(FVector(33.f, 33.f, 10.f));
		WeaponInfoTileBack->SetPosition(FVector(-590.f + 36.f * i, 295.f));
		WeaponInfoTileBack->SetMulColor({ 1.f,1.f,1.f,0.7f });
		WeaponInfoTileBack->SetActive(false);
		WeaponInfoBack.push_back(WeaponInfoTileBack);

		WeaponInfo[i].resize(9);
		UImage* WeaponInfoTile = CreateWidget<UImage>(GetWorld(), "EquipTileBack");
		WeaponInfoTile->AddToViewPort(5);
		WeaponInfoTile->SetAutoSize(2.f, true);
		WeaponInfoTile->SetPosition(FVector(-590.f + 36.f * i, 295.f));
		WeaponInfoTile->SetActive(false);
		WeaponInfo[i][0] = WeaponInfoTile;

		for (int j = 0; j < 8; j++)
		{
			UImage* WeaponLevelInfoTile = CreateWidget<UImage>(GetWorld(), "EquipTileBack");
			WeaponLevelInfoTile->AddToViewPort(5);
			WeaponLevelInfoTile->SetScale(FVector(11.f, 11.f, 10.f));
			WeaponLevelInfoTile->SetPosition(FVector(-601.f + 36*i + 11.f * static_cast<float>(j%3), 273.f - 11.f*static_cast<float>(j/3)));
			WeaponLevelInfoTile->SetActive(false);
			WeaponLevelInfoTile->SetSprite("LevelVal.png", 0);
			WeaponInfo[i][j+1] = WeaponLevelInfoTile;
		}
	}

	AccessoryInfo.resize(6);
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

		UImage* AccessoryInfoTileBack = CreateWidget<UImage>(GetWorld(), "InfoTileBack");
		AccessoryInfoTileBack->AddToViewPort(4);
		AccessoryInfoTileBack->SetSprite("EquipedTile.png", 1);
		AccessoryInfoTileBack->SetScale(FVector(28.f, 28.f));
		AccessoryInfoTileBack->SetPosition(FVector(-590.f + 36.f * i, 225.f));
		AccessoryInfoTileBack->SetMulColor({ 1.f,1.f,1.f,0.7f });
		AccessoryInfoTileBack->SetActive(false);
		AccessoryInfoBack.push_back(AccessoryInfoTileBack);

		AccessoryInfo[i].resize(9);
		UImage* AccessoryInfoTile = CreateWidget<UImage>(GetWorld(), "InfoTile");
		AccessoryInfoTile->AddToViewPort(5);
		AccessoryInfoTile->SetAutoSize(2.f, true);
		AccessoryInfoTile->SetPosition(FVector(-590.f + 36.f * i, 225.f));
		AccessoryInfoTile->SetActive(false);
		AccessoryInfo[i][0] = AccessoryInfoTile;

		for (int j = 0; j < 8; j++)
		{
			UImage* AccessoryLevelInfoTile = CreateWidget<UImage>(GetWorld(), "LevelInfoTile");
			AccessoryLevelInfoTile->AddToViewPort(5);
			AccessoryLevelInfoTile->SetScale(FVector(11.f, 11.f, 10.f));
			AccessoryLevelInfoTile->SetPosition(FVector(-601.f + 36 * i + 11.f * static_cast<float>(j % 3), 203.f - 11.f * static_cast<float>(j / 3)));
			AccessoryLevelInfoTile->SetActive(false);
			AccessoryLevelInfoTile->SetSprite("LevelVal.png", 0);
			AccessoryInfo[i][j + 1] = AccessoryLevelInfoTile;
		}
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
	WeaponInfoBackBoard->AddToViewPort(3);
	WeaponInfoBackBoard->SetSprite("BlankBoard.png");
	WeaponInfoBackBoard->SetScale(FVector(240.f, 160.f));
	WeaponInfoBackBoard->SetPosition(FVector(-500.f, 235.f));
	WeaponInfoBackBoard->SetPlusColor({ 0.2f,0.2f,0.2f });
	WeaponInfoBackBoard->SetMulColor({ 1.f,1.f,1.f,0.8f });

	PlayerStatusInfoBackBoard = CreateWidget<UImage>(GetWorld(), "PlayerStatusInfoBackBoard");
	PlayerStatusInfoBackBoard->AddToViewPort(3);
	PlayerStatusInfoBackBoard->SetSprite("BlankBoard.png");
	PlayerStatusInfoBackBoard->SetScale(FVector(240.f, 350.f));
	PlayerStatusInfoBackBoard->SetPosition(FVector(-500.f, -20.f));
	PlayerStatusInfoBackBoard->SetPlusColor({ 0.2f,0.2f,0.2f });
	PlayerStatusInfoBackBoard->SetMulColor({ 1.f,1.f,1.f,0.8f });

	for (int i = 0; i < 15; i++)
	{
		if (i == 4 || i == 11)
		{
			PlayerStatusInfoSprite.push_back(nullptr);
			continue;
		}

		PlayerStatusInfoSprite.push_back(CreateWidget<UImage>(GetWorld(), "StatusInfoSprite"));
		PlayerStatusInfoSprite[i]->AddToViewPort(3);
		PlayerStatusInfoSprite[i]->SetAutoSize(1.2f, true);
		PlayerStatusInfoSprite[i]->SetPosition(FVector(-595.f, 130.f - 20.f * i, 10.f));
	}

	PlayerStatusInfoSprite[0]->SetSprite("HollowHeartSprite.png");
	PlayerStatusInfoSprite[1]->SetSprite("PummarolaSprite.png");
	PlayerStatusInfoSprite[2]->SetSprite("ArmorSprite.png");
	PlayerStatusInfoSprite[3]->SetSprite("WingsSprite.png");

	PlayerStatusInfoSprite[5]->SetSprite("SpinachSprite.png");
	PlayerStatusInfoSprite[6]->SetSprite("CandelabradorSprite.png");
	PlayerStatusInfoSprite[7]->SetSprite("BracerSprite.png");
	PlayerStatusInfoSprite[8]->SetSprite("SpellbinderSprite.png");
	PlayerStatusInfoSprite[9]->SetSprite("DuplicatorSprite.png");
	PlayerStatusInfoSprite[10]->SetSprite("EmptyTomeSprite.png");

	PlayerStatusInfoSprite[12]->SetSprite("CloverSprite.png");
	PlayerStatusInfoSprite[13]->SetSprite("Growth.png");
	PlayerStatusInfoSprite[14]->SetSprite("AttractorbSprite.png");

	for (int i = 0; i < 15; i++)
	{
		if (i == 4 || i == 11)
		{
			PlayerStatusInfoText.push_back(std::make_pair(nullptr,nullptr));
			continue;
		}

		PlayerStatusInfoText.push_back(std::make_pair(CreateWidget<UTextWidget>(GetWorld(), "StatusInfoText"), CreateWidget<UTextWidget>(GetWorld(), "StatusInfoText")));
		PlayerStatusInfoText[i].first->AddToViewPort(4);
		PlayerStatusInfoText[i].first->SetScale(14.f);
		PlayerStatusInfoText[i].first->SetFont("Liberation Sans 보통");
		PlayerStatusInfoText[i].first->SetColor(Color8Bit::White);
		PlayerStatusInfoText[i].first->SetPosition(FVector(-570.f, 130.f - 20.f * i, 10.f));
		PlayerStatusInfoText[i].first->SetActive(true);
		PlayerStatusInfoText[i].first->SetFlag(static_cast<FW1_TEXT_FLAG>(FW1_TEXT_FLAG::FW1_LEFT | FW1_TEXT_FLAG::FW1_VCENTER));

		PlayerStatusInfoText[i].second->AddToViewPort(4);
		PlayerStatusInfoText[i].second->SetScale(14.f);
		PlayerStatusInfoText[i].second->SetFont("Liberation Sans 보통");
		PlayerStatusInfoText[i].second->SetColor(Color8Bit::White);
		PlayerStatusInfoText[i].second->SetPosition(FVector(-400.f, 130.f - 20.f * i, 10.f));
		PlayerStatusInfoText[i].second->SetActive(true);
		PlayerStatusInfoText[i].second->SetFlag(static_cast<FW1_TEXT_FLAG>(FW1_TEXT_FLAG::FW1_RIGHT | FW1_TEXT_FLAG::FW1_VCENTER));
	}

	PlayerStatusInfoText[0].first->SetText("Max Health");
	PlayerStatusInfoText[1].first->SetText("Recovery");
	PlayerStatusInfoText[2].first->SetText("Armor");
	PlayerStatusInfoText[3].first->SetText("MoveSpeed");
						  
	PlayerStatusInfoText[5].first->SetText("Might");
	PlayerStatusInfoText[6].first->SetText("Area");
	PlayerStatusInfoText[7].first->SetText("Speed");
	PlayerStatusInfoText[8].first->SetText("Duration");
	PlayerStatusInfoText[9].first->SetText("Amount");
	PlayerStatusInfoText[10].first->SetText("Cooldown");
							
	PlayerStatusInfoText[12].first->SetText("Luck");
	PlayerStatusInfoText[13].first->SetText("Growth");
	PlayerStatusInfoText[14].first->SetText("Magnet");



	LevelUpBackBoard = CreateWidget<UImage>(GetWorld(), "LevelUpBackBoard");
	LevelUpBackBoard->AddToViewPort(2);
	LevelUpBackBoard->SetSprite("LevelUpMenu.png");
	LevelUpBackBoard->SetScale(FVector(346.f, 460.f));
	LevelUpBackBoard->SetPosition(FVector(0.f, 0.f));

	LevelUpText = CreateWidget<UTextWidget>(GetWorld(), "LevelUpText");
	LevelUpText->AddToViewPort(4);
	LevelUpText->SetScale(30.f);
	LevelUpText->SetFont("Liberation Sans 보통");
	LevelUpText->SetColor(Color8Bit::White);
	LevelUpText->SetPosition(FVector(0.f, 190.f,0.f));
	LevelUpText->SetActive(false);
	LevelUpText->SetText("레벨 업!");
	LevelUpText->SetFlag(static_cast<FW1_TEXT_FLAG>(FW1_TEXT_FLAG::FW1_CENTER | FW1_TEXT_FLAG::FW1_VCENTER));

	AdditionalMessage = CreateWidget<UTextWidget>(GetWorld(), "AdditionalMessage");
	AdditionalMessage->AddToViewPort(4);
	AdditionalMessage->SetScale(15.f);
	AdditionalMessage->SetFont("Liberation Sans 보통");
	AdditionalMessage->SetColor(Color8Bit::White);
	AdditionalMessage->SetPosition(FVector(0.f, -180.f, 0.f));
	AdditionalMessage->SetActive(false);
	AdditionalMessage->SetText("행운이 높으면\n 4번째 장비를 선택할 수 있습니다.");
	AdditionalMessage->SetFlag(static_cast<FW1_TEXT_FLAG>(FW1_TEXT_FLAG::FW1_CENTER | FW1_TEXT_FLAG::FW1_VCENTER));

	LevelUpList.resize(5);
	LevelUpListExplain.resize(5);

	for (int i = -1; i < 2; i++)
	{
		LevelUpList[i+1].resize(5);
		LevelUpListExplain[i + 1].resize(5);

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

		UTextWidget* WeaponNameUnit = CreateWidget<UTextWidget>(GetWorld(), "WeaponName");
		WeaponNameUnit->AddToViewPort(4);
		WeaponNameUnit->SetScale(15.f);
		WeaponNameUnit->SetFont("Liberation Sans 보통");
		WeaponNameUnit->SetColor(Color8Bit::White);
		WeaponNameUnit->SetPosition(FVector(-110.f, 35.f - 99.f * i));
		WeaponNameUnit->SetActive(false);
		WeaponNameUnit->SetFlag(static_cast<FW1_TEXT_FLAG>(FW1_TEXT_FLAG::FW1_LEFT | FW1_TEXT_FLAG::FW1_VCENTER));
		LevelUpListExplain[i + 1][0] = WeaponNameUnit;

		UTextWidget* WeaponExplainUnit = CreateWidget<UTextWidget>(GetWorld(), "WeaponExplain");
		WeaponExplainUnit->AddToViewPort(4);
		WeaponExplainUnit->SetScale(15.f);
		WeaponExplainUnit->SetFont("Liberation Sans 보통");
		WeaponExplainUnit->SetColor(Color8Bit::White);
		WeaponExplainUnit->SetPosition(FVector(-140.f, -20.f-99.f * i));
		WeaponExplainUnit->SetActive(false);
		WeaponExplainUnit->SetFlag(static_cast<FW1_TEXT_FLAG>(FW1_TEXT_FLAG::FW1_LEFT | FW1_TEXT_FLAG::FW1_VCENTER));

		LevelUpListExplain[i + 1][1] = WeaponExplainUnit;

		UTextWidget* LevelStatusUnit = CreateWidget<UTextWidget>(GetWorld(), "LevelStatus");
		LevelStatusUnit->AddToViewPort(4);
		LevelStatusUnit->SetScale(15.f);
		LevelStatusUnit->SetFont("Liberation Sans 보통");
		LevelStatusUnit->SetColor(Color8Bit::White);
		LevelStatusUnit->SetPosition(FVector(60.f, 35.f-99.f * i));
		LevelStatusUnit->SetActive(false);
		LevelStatusUnit->SetFlag(static_cast<FW1_TEXT_FLAG>(FW1_TEXT_FLAG::FW1_LEFT | FW1_TEXT_FLAG::FW1_VCENTER));

		LevelUpListExplain[i + 1][2] = LevelStatusUnit;
	}

	SelectArrows.first = CreateWidget<UImage>(GetWorld(), "ArrowLeft");
	SelectArrows.first->AddToViewPort(4);
	SelectArrows.first->SetOrder(1);
	SelectArrows.first->CreateAnimation("Rotate", "Arrow", 0.1f, true);
	SelectArrows.first->SetAutoSize(2.f, true);
	SelectArrows.first->ChangeAnimation("Rotate");


	SelectArrows.second = CreateWidget<UImage>(GetWorld(), "ArrowLeft");
	SelectArrows.second->AddToViewPort(4);
	SelectArrows.second->SetOrder(1);
	SelectArrows.second->CreateAnimation("Rotate", "Arrow", 0.1f, true);
	SelectArrows.second->SetAutoSize(2.f, true);
	
	/*FVector Scale = SelectArrows.second->GetLocalScale();
	Scale.X = -Scale.X;
	SelectArrows.second->SetScale(Scale);*/
	SelectArrows.second->SetRotationDeg(FVector(0.f, 0.f, 180.f));
	SelectArrows.second->ChangeAnimation("Rotate");

	KillCountText = CreateWidget<UTextWidget>(GetWorld(), "KillCount");
	KillCountText->AddToViewPort(4);
	KillCountText->SetScale(15.f);
	KillCountText->SetFont("Liberation Sans 보통");
	KillCountText->SetColor(Color8Bit::White);
	KillCountText->SetPosition(FVector(365.f,315.f));
	KillCountText->SetFlag(static_cast<FW1_TEXT_FLAG>(FW1_TEXT_FLAG::FW1_LEFT | FW1_TEXT_FLAG::FW1_VCENTER));

	GoldText = CreateWidget<UTextWidget>(GetWorld(), "Gold");
	GoldText->AddToViewPort(4);
	GoldText->SetScale(15.f);
	GoldText->SetFont("Liberation Sans 보통");
	GoldText->SetColor(Color8Bit::White);
	GoldText->SetPosition(FVector(580.f, 315.f));
	GoldText->SetFlag(static_cast<FW1_TEXT_FLAG>(FW1_TEXT_FLAG::FW1_LEFT | FW1_TEXT_FLAG::FW1_VCENTER));

	TimeUI = CreateWidget<UTextWidget>(GetWorld(), "Time");
	TimeUI->AddToViewPort(4);
	TimeUI->SetScale(30.f);
	TimeUI->SetFont("Liberation Sans 보통");
	TimeUI->SetColor(Color8Bit::White);
	TimeUI->SetPosition(FVector(0.f, 315.f));
	TimeUI->SetFlag(static_cast<FW1_TEXT_FLAG>(FW1_TEXT_FLAG::FW1_CENTER | FW1_TEXT_FLAG::FW1_VCENTER));

	ChestUI = CreateWidget<UChestUI>(GetWorld(), "Chest");
	DeathUI = CreateWidget<UDeathUI>(GetWorld(), "DeathUI");
}

void UIManager::UIUpdate()
{
	UIHPUpdate();
	UILevelUpdate();
	WeaponTilesUpdate();
	AccessoryTilesUpdate();
	UIPlayerStatusUpdate();
	KillCountUpdate();
	GoldUpdate();

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

		if (IsSelecting)
		{
			WeaponInfoBack[i]->SetActive(true);
			for (UImage* Info : WeaponInfo[i])
			{
				Info->SetActive(true);
			}
		}
		else
		{
			WeaponInfoBack[i]->SetActive(false);
			for (UImage* Info : WeaponInfo[i])
			{
				Info->SetActive(false);
			}
		}

		switch (_Weapon.first)
		{
		case EWeapon::Axe:
		{
			WeaponTiles[i]->SetSprite("AxeSprite.png");
			WeaponInfo[i][0]->SetSprite("AxeSprite.png");

			int WeaponLevel = dynamic_cast<UAxe*>(_Weapon.second.get())->Data.Level;
			for (int j = 0; j < WeaponLevel; j++)
			{
				WeaponInfo[i][j + 1]->SetSprite("LevelVal.png", 1);
			}
			break;
		}
		case EWeapon::Cross:
		{
			WeaponTiles[i]->SetSprite("CrossSprite.png");
			WeaponInfo[i][0]->SetSprite("CrossSprite.png");

			int WeaponLevel = dynamic_cast<UCross*>(_Weapon.second.get())->Data.Level;
			for (int j = 0; j < WeaponLevel; j++)
			{
				WeaponInfo[i][j + 1]->SetSprite("LevelVal.png", 1);
			}
			break;
		}
		case EWeapon::FireWand:
		{
			WeaponTiles[i]->SetSprite("FireWandSprite.png");
			WeaponInfo[i][0]->SetSprite("FireWandSprite.png");

			int WeaponLevel = dynamic_cast<UFireWand*>(_Weapon.second.get())->Data.Level;
			for (int j = 0; j < WeaponLevel; j++)
			{
				WeaponInfo[i][j + 1]->SetSprite("LevelVal.png", 1);
			}
			break;
		}
		case EWeapon::Garlic:
		{
			WeaponTiles[i]->SetSprite("GarlicSprite.png");
			WeaponInfo[i][0]->SetSprite("GarlicSprite.png");

			int WeaponLevel = dynamic_cast<UGarlic*>(_Weapon.second.get())->Data.Level;
			for (int j = 0; j < WeaponLevel; j++)
			{
				WeaponInfo[i][j + 1]->SetSprite("LevelVal.png", 1);
			}
			break;
		}
		case EWeapon::KingBible:
		{
			WeaponTiles[i]->SetSprite("KingBibleSprite.png");
			WeaponInfo[i][0]->SetSprite("KingBibleSprite.png");

			int WeaponLevel = dynamic_cast<UKingBible*>(_Weapon.second.get())->Data.Level;
			for (int j = 0; j < WeaponLevel; j++)
			{
				WeaponInfo[i][j + 1]->SetSprite("LevelVal.png", 1);
			}
			break;
		}
		case EWeapon::Knife:
		{
			WeaponTiles[i]->SetSprite("KnifeSprite.png");
			WeaponInfo[i][0]->SetSprite("KnifeSprite.png");

			int WeaponLevel = dynamic_cast<UKnife*>(_Weapon.second.get())->Data.Level;
			for (int j = 0; j < WeaponLevel; j++)
			{
				WeaponInfo[i][j + 1]->SetSprite("LevelVal.png", 1);
			}
			break;
		}
		case EWeapon::LightingRing:
		{
			WeaponTiles[i]->SetSprite("LightingRingSprite.png");
			WeaponInfo[i][0]->SetSprite("LightingRingSprite.png");

			int WeaponLevel = dynamic_cast<ULightingRing*>(_Weapon.second.get())->Data.Level;
			for (int j = 0; j < WeaponLevel; j++)
			{
				WeaponInfo[i][j + 1]->SetSprite("LevelVal.png", 1);
			}
			break;
		}
		case EWeapon::MagicWand:
		{
			WeaponTiles[i]->SetSprite("MagicWandSprite.png");
			WeaponInfo[i][0]->SetSprite("MagicWandSprite.png");

			int WeaponLevel = dynamic_cast<UMagicWand*>(_Weapon.second.get())->Data.Level;
			for (int j = 0; j < WeaponLevel; j++)
			{
				WeaponInfo[i][j + 1]->SetSprite("LevelVal.png", 1);
			}
			break;
		}
		case EWeapon::RuneTracer:
		{
			WeaponTiles[i]->SetSprite("RuneTracerSprite.png");
			WeaponInfo[i][0]->SetSprite("RuneTracerSprite.png");

			int WeaponLevel = dynamic_cast<URuneTracer*>(_Weapon.second.get())->Data.Level;
			for (int j = 0; j < WeaponLevel; j++)
			{
				WeaponInfo[i][j + 1]->SetSprite("LevelVal.png", 1);
			}
			break;
		}
		case EWeapon::SantaWater:
		{
			WeaponTiles[i]->SetSprite("SantaWaterSprite.png");
			WeaponInfo[i][0]->SetSprite("SantaWaterSprite.png");

			int WeaponLevel = dynamic_cast<USantaWater*>(_Weapon.second.get())->Data.Level;
			for (int j = 0; j < WeaponLevel; j++)
			{
				WeaponInfo[i][j + 1]->SetSprite("LevelVal.png", 1);
			}
			break;
		}
		case EWeapon::Whip:
		{
			WeaponTiles[i]->SetSprite("WhipSprite.png");
			WeaponInfo[i][0]->SetSprite("WhipSprite.png");

			int WeaponLevel = dynamic_cast<UWhip*>(_Weapon.second.get())->Data.Level;
			for (int j = 0; j < WeaponLevel; j++)
			{
				WeaponInfo[i][j + 1]->SetSprite("LevelVal.png", 1);
			}
			break;
		}
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

		if (IsSelecting)
		{
			AccessoryInfoBack[i]->SetActive(true);
			for (UImage* Info : AccessoryInfo[i])
			{
				Info->SetActive(true);
			}
		}
		else
		{
			AccessoryInfoBack[i]->SetActive(false);
			for (UImage* Info : AccessoryInfo[i])
			{
				Info->SetActive(false);
			}
		}

		switch (_Accessory.first)
		{
		case EAccessory::Armor:
		{
			AccessoryTiles[i]->SetSprite("ArmorSprite.png");
			AccessoryInfo[i][0]->SetSprite("ArmorSprite.png");

			int AccessoryLevel = dynamic_cast<UArmor*>(_Accessory.second.get())->Data.Level;
			for (int j = 0; j < AccessoryLevel; j++)
			{
				AccessoryInfo[i][j + 1]->SetSprite("LevelVal.png", 1);
			}
			break;
		}
		case EAccessory::Attractorb:
		{
			AccessoryTiles[i]->SetSprite("AttractorbSprite.png");
			AccessoryInfo[i][0]->SetSprite("AttractorbSprite.png");

			int AccessoryLevel = dynamic_cast<UAttractorb*>(_Accessory.second.get())->Data.Level;
			for (int j = 0; j < AccessoryLevel; j++)
			{
				AccessoryInfo[i][j + 1]->SetSprite("LevelVal.png", 1);
			}
			break;
		}
		case EAccessory::Bracer:
		{
			AccessoryTiles[i]->SetSprite("BracerSprite.png");
			AccessoryInfo[i][0]->SetSprite("BracerSprite.png");

			int AccessoryLevel = dynamic_cast<UBracer*>(_Accessory.second.get())->Data.Level;
			for (int j = 0; j < AccessoryLevel; j++)
			{
				AccessoryInfo[i][j + 1]->SetSprite("LevelVal.png", 1);
			}
			break;
		}
		case EAccessory::Candelabrador:
		{
			AccessoryTiles[i]->SetSprite("CandelabradorSprite.png");
			AccessoryInfo[i][0]->SetSprite("CandelabradorSprite.png");

			int AccessoryLevel = dynamic_cast<UCandelabrador*>(_Accessory.second.get())->Data.Level;
			for (int j = 0; j < AccessoryLevel; j++)
			{
				AccessoryInfo[i][j + 1]->SetSprite("LevelVal.png", 1);
			}
			break;
		}
		case EAccessory::Clover:
		{
			AccessoryTiles[i]->SetSprite("CloverSprite.png");
			AccessoryInfo[i][0]->SetSprite("CloverSprite.png");

			int AccessoryLevel = dynamic_cast<UClover*>(_Accessory.second.get())->Data.Level;
			for (int j = 0; j < AccessoryLevel; j++)
			{
				AccessoryInfo[i][j + 1]->SetSprite("LevelVal.png", 1);
			}
			break;
		}
		case EAccessory::Duplicator:
		{
			AccessoryTiles[i]->SetSprite("DuplicatorSprite.png");
			AccessoryInfo[i][0]->SetSprite("DuplicatorSprite.png");

			int AccessoryLevel = dynamic_cast<UDuplicator*>(_Accessory.second.get())->Data.Level;
			for (int j = 0; j < AccessoryLevel; j++)
			{
				AccessoryInfo[i][j + 1]->SetSprite("LevelVal.png", 1);
			}
			break;
		}
		case EAccessory::EmptyTome:
		{
			AccessoryTiles[i]->SetSprite("EmptyTomeSprite.png");
			AccessoryInfo[i][0]->SetSprite("EmptyTomeSprite.png");

			int AccessoryLevel = dynamic_cast<UEmptyTome*>(_Accessory.second.get())->Data.Level;
			for (int j = 0; j < AccessoryLevel; j++)
			{
				AccessoryInfo[i][j + 1]->SetSprite("LevelVal.png", 1);
			}
			break;
		}
		case EAccessory::HollowHeart:
		{
			AccessoryTiles[i]->SetSprite("HollowHeartSprite.png");
			AccessoryInfo[i][0]->SetSprite("HollowHeartSprite.png");

			int AccessoryLevel = dynamic_cast<UHollowHeart*>(_Accessory.second.get())->Data.Level;
			for (int j = 0; j < AccessoryLevel; j++)
			{
				AccessoryInfo[i][j + 1]->SetSprite("LevelVal.png", 1);
			}
			break;
		}
		case EAccessory::Pummarola:
		{
			AccessoryTiles[i]->SetSprite("PummarolaSprite.png");
			AccessoryInfo[i][0]->SetSprite("PummarolaSprite.png");

			int AccessoryLevel = dynamic_cast<UPummarola*>(_Accessory.second.get())->Data.Level;
			for (int j = 0; j < AccessoryLevel; j++)
			{
				AccessoryInfo[i][j + 1]->SetSprite("LevelVal.png", 1);
			}
			break;
		}
		case EAccessory::Spellbinder:
		{
			AccessoryTiles[i]->SetSprite("SpellbinderSprite.png");
			AccessoryInfo[i][0]->SetSprite("SpellbinderSprite.png");

			int AccessoryLevel = dynamic_cast<USpellbinder*>(_Accessory.second.get())->Data.Level;
			for (int j = 0; j < AccessoryLevel; j++)
			{
				AccessoryInfo[i][j + 1]->SetSprite("LevelVal.png", 1);
			}
			break;
		}
		case EAccessory::Spinach:
		{
			AccessoryTiles[i]->SetSprite("SpinachSprite.png");
			AccessoryInfo[i][0]->SetSprite("SpinachSprite.png");

			int AccessoryLevel = dynamic_cast<USpinach*>(_Accessory.second.get())->Data.Level;
			for (int j = 0; j < AccessoryLevel; j++)
			{
				AccessoryInfo[i][j + 1]->SetSprite("LevelVal.png", 1);
			}
			break;
		}
		case EAccessory::Wings:
		{
			AccessoryTiles[i]->SetSprite("WingsSprite.png");
			AccessoryInfo[i][0]->SetSprite("WingsSprite.png");

			int AccessoryLevel = dynamic_cast<UWings*>(_Accessory.second.get())->Data.Level;
			for (int j = 0; j < AccessoryLevel; j++)
			{
				AccessoryInfo[i][j + 1]->SetSprite("LevelVal.png", 1);
			}
			break;
		}
		default:
			break;
		}
		i++;
	}
}

void UIManager::UIPlayerStatusUpdate()
{

	FAccessoryData Data = UEquipManager::GetAccessoryResult();

	int MaxHealth = 100 + static_cast<int>(Data.MaxHealth);
	PlayerStatusInfoText[0].second->SetText(std::to_string(MaxHealth));

	float Recovery = Data.Recovery;
	if (Recovery < 0.01f)
	{
		PlayerStatusInfoText[1].second->SetText("-");
	}
	else
	{
		PlayerStatusInfoText[1].second->SetText(std::to_string(Recovery));
	}

	int Armor = static_cast<int>(Data.Armor);
	if (Armor == 0)
	{
		PlayerStatusInfoText[2].second->SetText("-");
	}
	else
	{
		PlayerStatusInfoText[2].second->SetText(std::to_string(Armor));
	}

	float MoveSpeed = Data.MoveSpeed;
	if (MoveSpeed < 1.05f)
	{
		PlayerStatusInfoText[3].second->SetText("-");
	}
	else
	{
		int MoveSpeedPercent = static_cast<int>((MoveSpeed - 1.f) * 100.f);
		PlayerStatusInfoText[3].second->SetText("+" + std::to_string(MoveSpeedPercent) + "%");
	}

	float Might = Data.Might;
	if (Might < 1.05f)
	{
		PlayerStatusInfoText[5].second->SetText("-");
	}
	else
	{
		int MightPercent = static_cast<int>((Might-1.f) * 100.f);
		PlayerStatusInfoText[5].second->SetText("+" + std::to_string(MightPercent) + "%");
	}

	float Area = Data.Area;
	if (Area < 0.05f)
	{
		PlayerStatusInfoText[6].second->SetText("-");
	}
	else
	{
		int AreaPercent = static_cast<int>(Area * 100.f);
		PlayerStatusInfoText[6].second->SetText("+" + std::to_string(AreaPercent) + "%");
	}

	float Speed = Data.Speed;
	if (Speed < 1.05f)
	{
		PlayerStatusInfoText[7].second->SetText("-");
	}
	else
	{
		int SpeedPercent = static_cast<int>((Speed - 1.f) * 100.f);
		PlayerStatusInfoText[7].second->SetText("+" + std::to_string(SpeedPercent) + "%");
	}

	float Duration = Data.Duration;
	if (Duration < 0.05f)
	{
		PlayerStatusInfoText[8].second->SetText("-");
	}
	else
	{
		int DurationPercent = static_cast<int>(Duration * 100.f);
		PlayerStatusInfoText[8].second->SetText("+" + std::to_string(DurationPercent) + "%");
	}

	int Amount = Data.Amount;
	if (Amount == 0)
	{
		PlayerStatusInfoText[9].second->SetText("-");
	}
	else
	{
		PlayerStatusInfoText[9].second->SetText(std::to_string(Amount));
	}

	float Cooldown = Data.Cooldown;
	if (Cooldown < 0.05f)
	{
		PlayerStatusInfoText[10].second->SetText("-");
	}
	else
	{
		int CooldownPercent = static_cast<int>(Cooldown * 100.f);
		PlayerStatusInfoText[10].second->SetText("+" + std::to_string(CooldownPercent) + "%");
	}

	float Luck = Data.Luck;
	if (Luck < 0.05f)
	{
		PlayerStatusInfoText[12].second->SetText("-");
	}
	else
	{
		int LuckPercent = static_cast<int>(Luck * 100.f);
		PlayerStatusInfoText[12].second->SetText("+" + std::to_string(LuckPercent) + "%");
	}

	PlayerStatusInfoText[13].second->SetText("-");

	float Magnet = Data.Magnet;
	if (Magnet < 1.05f)
	{
		PlayerStatusInfoText[14].second->SetText("-");
	}
	else
	{
		int MagnetPercent = static_cast<int>((Magnet - 1.f) * 100.f);
		PlayerStatusInfoText[14].second->SetText("+" + std::to_string(MagnetPercent) + "%");
	}
}

void UIManager::KillCountUpdate()
{
	KillCountText->SetText(std::to_string(UContentsValue::KillCount));
}

void UIManager::GoldUpdate()
{
	GoldText->SetText(std::to_string(UContentsValue::Gold));
}

void UIManager::TimeUpdate(float _DeltaTime)
{
	UContentsValue::Time += _DeltaTime;

	int Time = static_cast<int>(UContentsValue::Time);
	int Second = Time % 60;
	int Minute = Time / 60;

	std::string SecondZeroPadding = "00" + std::to_string(Second);
	std::string MinuteZeroPadding = "00" + std::to_string(Minute);

	std::string SecondText = SecondZeroPadding.substr(SecondZeroPadding.size() - 2, 2);
	std::string MinuteText = MinuteZeroPadding.substr(MinuteZeroPadding.size() - 2, 2);

	TimeUI->SetText(MinuteText + " : " + SecondText);
}

int UIManager::RandomPickLogic(int _Min, int _Max)
{
	int Random = UEngineRandom::MainRandom.RandomInt(_Min, _Max);

	if (Random < 12)
	{
		if (UEquipManager::Weapons.size() >= 6)
		{
			int rand = UEngineRandom::MainRandom.RandomInt(0, 5);

			switch (UEquipManager::Weapons[rand].first)
			{
			case EWeapon::Axe:
				Random = static_cast<int>(ESelectList::Axe);
				if (UAxe::Data.Level > 7)
				{
					return RandomPickLogic(_Min, _Max);
				}
				break;
			case EWeapon::Cross:
				Random = static_cast<int>(ESelectList::Cross);
				if (UCross::Data.Level > 7)
				{
					return RandomPickLogic(_Min, _Max);
				}
				break;
			case EWeapon::FireWand:
				Random = static_cast<int>(ESelectList::FireWand);
				if (UFireWand::Data.Level > 7)
				{
					return RandomPickLogic(_Min, _Max);
				}
				break;
			case EWeapon::Garlic:
				Random = static_cast<int>(ESelectList::Garlic);
				if (UGarlic::Data.Level > 7)
				{
					return RandomPickLogic(_Min, _Max);
				}
				break;
			case EWeapon::KingBible:
				Random = static_cast<int>(ESelectList::KingBible);
				if (UKingBible::Data.Level > 7)
				{
					return RandomPickLogic(_Min, _Max);
				}
				break;
			case EWeapon::Knife:
				Random = static_cast<int>(ESelectList::Knife);
				if (UKnife::Data.Level > 7)
				{
					return RandomPickLogic(_Min, _Max);
				}
				break;
			case EWeapon::LightingRing:
				Random = static_cast<int>(ESelectList::LightingRing);
				if (ULightingRing::Data.Level > 7)
				{
					return RandomPickLogic(_Min, _Max);
				}
				break;
			case EWeapon::MagicWand:
				Random = static_cast<int>(ESelectList::MagicWand);
				if (UMagicWand::Data.Level >7)
				{
					return RandomPickLogic(_Min, _Max);
				}
				break;
			case EWeapon::RuneTracer:
				Random = static_cast<int>(ESelectList::RuneTracer);
				if (URuneTracer::Data.Level > 7)
				{
					return RandomPickLogic(_Min, _Max);
				}
				break;
			case EWeapon::SantaWater:
				Random = static_cast<int>(ESelectList::SantaWater);
				if (USantaWater::Data.Level > 7)
				{
					return RandomPickLogic(_Min, _Max);
				}
				break;
			case EWeapon::Whip:
				Random = static_cast<int>(ESelectList::Whip);
				if (UWhip::Data.Level > 7)
				{
					return RandomPickLogic(_Min, _Max);
				}
				break;
			}
		}
	}
	else if (Random < 24)
	{
		if (UEquipManager::Accessories.size() >= 6)
		{
			int rand = UEngineRandom::MainRandom.RandomInt(0, 5);
			switch (UEquipManager::Accessories[rand].first)
			{
			case EAccessory::Armor:
				Random = static_cast<int>(ESelectList::Armor);
				if (UArmor::Data.Level > 4)
				{
					return RandomPickLogic(_Min, _Max);
				}
				break;
			case EAccessory::Attractorb:
				Random = static_cast<int>(ESelectList::Attractorb);
				if (UAttractorb::Data.Level > 4)
				{
					return RandomPickLogic(_Min, _Max);
				}
				break;
			case EAccessory::Bracer:
				Random = static_cast<int>(ESelectList::Bracer);
				if (UBracer::Data.Level > 4)
				{
					return RandomPickLogic(_Min, _Max);
				}
				break;
			case EAccessory::Candelabrador:
				Random = static_cast<int>(ESelectList::Candelabrador);
				if (UCandelabrador::Data.Level > 4)
				{
					return RandomPickLogic(_Min, _Max);
				}
				break;
			case EAccessory::Clover:
				Random = static_cast<int>(ESelectList::Clover);
				if (UClover::Data.Level > 4)
				{
					return RandomPickLogic(_Min, _Max);
				}
				break;
			case EAccessory::Duplicator:
				Random = static_cast<int>(ESelectList::Duplicator);
				if (UDuplicator::Data.Level > 4)
				{
					return RandomPickLogic(_Min, _Max);
				}
				break;
			case EAccessory::EmptyTome:
				Random = static_cast<int>(ESelectList::EmptyTome);
				if (UEmptyTome::Data.Level > 4)
				{
					return RandomPickLogic(_Min, _Max);
				}
				break;
			case EAccessory::HollowHeart:
				Random = static_cast<int>(ESelectList::HollowHeart);
				if (UHollowHeart::Data.Level > 4)
				{
					return RandomPickLogic(_Min, _Max);
				}
				break;
			case EAccessory::Pummarola: 
				Random = static_cast<int>(ESelectList::Pummarola);
				if (UPummarola::Data.Level > 4)
				{
					return RandomPickLogic(_Min, _Max);
				}
				break;
			case EAccessory::Spellbinder:
				Random = static_cast<int>(ESelectList::Spellbinder);
				if (USpellbinder::Data.Level > 4)
				{
					return RandomPickLogic(_Min, _Max);
				}
				break;
			case EAccessory::Spinach:
				Random = static_cast<int>(ESelectList::Spinach);
				if (USpinach::Data.Level > 4)
				{
					return RandomPickLogic(_Min, _Max);
				}
				break;
			case EAccessory::Wings:
				Random = static_cast<int>(ESelectList::Wings);
				if (UWings::Data.Level > 4)
				{
					return RandomPickLogic(_Min, _Max);
				}
				break;
			}
		}
	}

	return Random;
}

void UIManager::LevelUpEventStart()
{
	GEngine->SetOrderTimeScale(0, 0.f);
	LevelUpUIOn();
	IsSelecting = true;
	SelectIndex = 0;

	for (int i = 0; i < 3; i++)
	{
		int Random = RandomPickLogic(static_cast<int>(ESelectList::Axe), static_cast<int>(ESelectList::Wings));
		ESelectList List = static_cast<ESelectList>(Random);

		for (ESelectList Selected : InfoVec)
		{
			while(List == Selected)
			{
				Random = RandomPickLogic(static_cast<int>(ESelectList::Axe), static_cast<int>(ESelectList::Wings));
				List = static_cast<ESelectList>(Random);
			}
		}


		switch (List)
		{
		case ESelectList::Axe:
		{
			LevelUpList[i][1]->SetSprite("AxeSprite.png");
			InfoVec[i] = ESelectList::Axe;

			std::string ExplainText = UAxe::Data.ExplainText;
			int CurLevel = UAxe::Data.Level;

			LevelUpListExplain[i][0]->SetText("Axe");
			LevelUpListExplain[i][1]->SetText(ExplainText);

			if (CurLevel == 0)
			{
				LevelUpListExplain[i][2]->SetText("신규 무기!");
				LevelUpListExplain[i][2]->SetColor(Color8Bit::Yellow);
			}
			else
			{
				std::string NextLevel = std::to_string(CurLevel + 1);
				LevelUpListExplain[i][2]->SetText("레벨: " + NextLevel);
				LevelUpListExplain[i][2]->SetColor(Color8Bit::White);
			}
			break;
		}
		case ESelectList::Cross:
		{
			LevelUpList[i][1]->SetSprite("CrossSprite.png");
			InfoVec[i] = ESelectList::Cross;

			std::string ExplainText = UCross::Data.ExplainText;
			int CurLevel = UCross::Data.Level;

			LevelUpListExplain[i][0]->SetText("Cross");
			LevelUpListExplain[i][1]->SetText(ExplainText);

			if (CurLevel == 0)
			{
				LevelUpListExplain[i][2]->SetText("신규 무기!");
				LevelUpListExplain[i][2]->SetColor(Color8Bit::Yellow);
			}
			else
			{
				std::string NextLevel = std::to_string(CurLevel + 1);
				LevelUpListExplain[i][2]->SetText("레벨: " + NextLevel);
				LevelUpListExplain[i][2]->SetColor(Color8Bit::White);
			}
			break;
		}
		case ESelectList::FireWand:
		{
			LevelUpList[i][1]->SetSprite("FireWandSprite.png");
			InfoVec[i] = ESelectList::FireWand;

			std::string ExplainText = UFireWand::Data.ExplainText;
			int CurLevel = UFireWand::Data.Level;

			LevelUpListExplain[i][0]->SetText("FireWand");
			LevelUpListExplain[i][1]->SetText(ExplainText);

			if (CurLevel == 0)
			{
				LevelUpListExplain[i][2]->SetText("신규 무기!");
				LevelUpListExplain[i][2]->SetColor(Color8Bit::Yellow);
			}
			else
			{
				std::string NextLevel = std::to_string(CurLevel + 1);
				LevelUpListExplain[i][2]->SetText("레벨: " + NextLevel);
				LevelUpListExplain[i][2]->SetColor(Color8Bit::White);
			}
			break;
		}
		case ESelectList::Garlic:
		{
			LevelUpList[i][1]->SetSprite("GarlicSprite.png");
			InfoVec[i] = ESelectList::Garlic;

			std::string ExplainText = UGarlic::Data.ExplainText;
			int CurLevel = UGarlic::Data.Level;

			LevelUpListExplain[i][0]->SetText("Garlic");
			LevelUpListExplain[i][1]->SetText(ExplainText);

			if (CurLevel == 0)
			{
				LevelUpListExplain[i][2]->SetText("신규 무기!");
				LevelUpListExplain[i][2]->SetColor(Color8Bit::Yellow);
			}
			else
			{
				std::string NextLevel = std::to_string(CurLevel + 1);
				LevelUpListExplain[i][2]->SetText("레벨: " + NextLevel);
				LevelUpListExplain[i][2]->SetColor(Color8Bit::White);
			}
			break;
		}
		case ESelectList::KingBible:
		{
			LevelUpList[i][1]->SetSprite("KingBibleSprite.png");
			InfoVec[i] = ESelectList::KingBible;

			std::string ExplainText = UKingBible::Data.ExplainText;
			int CurLevel = UKingBible::Data.Level;

			LevelUpListExplain[i][0]->SetText("KingBible");
			LevelUpListExplain[i][1]->SetText(ExplainText);

			if (CurLevel == 0)
			{
				LevelUpListExplain[i][2]->SetText("신규 무기!");
				LevelUpListExplain[i][2]->SetColor(Color8Bit::Yellow);
			}
			else
			{
				std::string NextLevel = std::to_string(CurLevel + 1);
				LevelUpListExplain[i][2]->SetText("레벨: " + NextLevel);
				LevelUpListExplain[i][2]->SetColor(Color8Bit::White);
			}
			break;
		}
		case ESelectList::Knife:
		{
			LevelUpList[i][1]->SetSprite("KnifeSprite.png");
			InfoVec[i] = ESelectList::Knife;

			std::string ExplainText = UKnife::Data.ExplainText;
			int CurLevel = UKnife::Data.Level;

			LevelUpListExplain[i][0]->SetText("Knife");
			LevelUpListExplain[i][1]->SetText(ExplainText);

			if (CurLevel == 0)
			{
				LevelUpListExplain[i][2]->SetText("신규 무기!");
				LevelUpListExplain[i][2]->SetColor(Color8Bit::Yellow);
			}
			else
			{
				std::string NextLevel = std::to_string(CurLevel + 1);
				LevelUpListExplain[i][2]->SetText("레벨: " + NextLevel);
				LevelUpListExplain[i][2]->SetColor(Color8Bit::White);
			}
			break;
		}
		case ESelectList::LightingRing:
		{
			LevelUpList[i][1]->SetSprite("LightingRingSprite.png");
			InfoVec[i] = ESelectList::LightingRing;

			std::string ExplainText = ULightingRing::Data.ExplainText;
			int CurLevel = ULightingRing::Data.Level;

			LevelUpListExplain[i][0]->SetText("LightingRing");
			LevelUpListExplain[i][1]->SetText(ExplainText);

			if (CurLevel == 0)
			{
				LevelUpListExplain[i][2]->SetText("신규 무기!");
				LevelUpListExplain[i][2]->SetColor(Color8Bit::Yellow);
			}
			else
			{
				std::string NextLevel = std::to_string(CurLevel + 1);
				LevelUpListExplain[i][2]->SetText("레벨: " + NextLevel);
				LevelUpListExplain[i][2]->SetColor(Color8Bit::White);
			}
			break;
		}
		case ESelectList::MagicWand:
		{
			LevelUpList[i][1]->SetSprite("MagicWandSprite.png");
			InfoVec[i] = ESelectList::MagicWand;

			std::string ExplainText = UMagicWand::Data.ExplainText;
			int CurLevel = UMagicWand::Data.Level;

			LevelUpListExplain[i][0]->SetText("MagicWand");
			LevelUpListExplain[i][1]->SetText(ExplainText);

			if (CurLevel == 0)
			{
				LevelUpListExplain[i][2]->SetText("신규 무기!");
				LevelUpListExplain[i][2]->SetColor(Color8Bit::Yellow);
			}
			else
			{
				std::string NextLevel = std::to_string(CurLevel + 1);
				LevelUpListExplain[i][2]->SetText("레벨: " + NextLevel);
				LevelUpListExplain[i][2]->SetColor(Color8Bit::White);
			}
			break;
		}
		case ESelectList::RuneTracer:
		{
			LevelUpList[i][1]->SetSprite("RuneTracerSprite.png");
			InfoVec[i] = ESelectList::RuneTracer;

			std::string ExplainText = URuneTracer::Data.ExplainText;
			int CurLevel = URuneTracer::Data.Level;

			LevelUpListExplain[i][0]->SetText("RuneTracer");
			LevelUpListExplain[i][1]->SetText(ExplainText);

			if (CurLevel == 0)
			{
				LevelUpListExplain[i][2]->SetText("신규 무기!");
				LevelUpListExplain[i][2]->SetColor(Color8Bit::Yellow);
			}
			else
			{
				std::string NextLevel = std::to_string(CurLevel + 1);
				LevelUpListExplain[i][2]->SetText("레벨: " + NextLevel);
				LevelUpListExplain[i][2]->SetColor(Color8Bit::White);
			}
			break;
		}
		case ESelectList::SantaWater:
		{
			LevelUpList[i][1]->SetSprite("SantaWaterSprite.png");
			InfoVec[i] = ESelectList::SantaWater;

			std::string ExplainText = USantaWater::Data.ExplainText;
			int CurLevel = USantaWater::Data.Level;

			LevelUpListExplain[i][0]->SetText("SantaWater");
			LevelUpListExplain[i][1]->SetText(ExplainText);

			if (CurLevel == 0)
			{
				LevelUpListExplain[i][2]->SetText("신규 무기!");
				LevelUpListExplain[i][2]->SetColor(Color8Bit::Yellow);
			}
			else
			{
				std::string NextLevel = std::to_string(CurLevel + 1);
				LevelUpListExplain[i][2]->SetText("레벨: " + NextLevel);
				LevelUpListExplain[i][2]->SetColor(Color8Bit::White);
			}
			break;
		}
		case ESelectList::Whip:
		{
			LevelUpList[i][1]->SetSprite("WhipSprite.png");
			InfoVec[i] = ESelectList::Whip;

			std::string ExplainText = UWhip::Data.ExplainText;
			int CurLevel = UWhip::Data.Level;

			LevelUpListExplain[i][0]->SetText("Whip");
			LevelUpListExplain[i][1]->SetText(ExplainText);

			if (CurLevel == 0)
			{
				LevelUpListExplain[i][2]->SetText("신규 무기!");
				LevelUpListExplain[i][2]->SetColor(Color8Bit::Yellow);
			}
			else
			{
				std::string NextLevel = std::to_string(CurLevel + 1);
				LevelUpListExplain[i][2]->SetText("레벨: " + NextLevel);
				LevelUpListExplain[i][2]->SetColor(Color8Bit::White);
			}
			break;
		}
		case ESelectList::Armor:
		{
			LevelUpList[i][1]->SetSprite("ArmorSprite.png");
			InfoVec[i] = ESelectList::Armor;

			std::string ExplainText = UArmor::Data.ExplainText;
			int CurLevel = UArmor::Data.Level;

			LevelUpListExplain[i][0]->SetText("Armor");
			LevelUpListExplain[i][1]->SetText(ExplainText);

			if (CurLevel == 0)
			{
				LevelUpListExplain[i][2]->SetText("신규 무기!");
				LevelUpListExplain[i][2]->SetColor(Color8Bit::Yellow);
			}
			else
			{
				std::string NextLevel = std::to_string(CurLevel + 1);
				LevelUpListExplain[i][2]->SetText("레벨: " + NextLevel);
				LevelUpListExplain[i][2]->SetColor(Color8Bit::White);
			}
			break;
		}
		case ESelectList::Attractorb:
		{
			LevelUpList[i][1]->SetSprite("AttractorbSprite.png");
			InfoVec[i] = ESelectList::Attractorb;

			std::string ExplainText = UAttractorb::Data.ExplainText;
			int CurLevel = UAttractorb::Data.Level;

			LevelUpListExplain[i][0]->SetText("Attractorb");
			LevelUpListExplain[i][1]->SetText(ExplainText);

			if (CurLevel == 0)
			{
				LevelUpListExplain[i][2]->SetText("신규 무기!");
				LevelUpListExplain[i][2]->SetColor(Color8Bit::Yellow);
			}
			else
			{
				std::string NextLevel = std::to_string(CurLevel + 1);
				LevelUpListExplain[i][2]->SetText("레벨: " + NextLevel);
				LevelUpListExplain[i][2]->SetColor(Color8Bit::White);
			}
			break;
		}
		case ESelectList::Bracer:
		{
			LevelUpList[i][1]->SetSprite("BracerSprite.png");
			InfoVec[i] = ESelectList::Bracer;

			std::string ExplainText = UBracer::Data.ExplainText;
			int CurLevel = UBracer::Data.Level;

			LevelUpListExplain[i][0]->SetText("Bracer");
			LevelUpListExplain[i][1]->SetText(ExplainText);

			if (CurLevel == 0)
			{
				LevelUpListExplain[i][2]->SetText("신규 무기!");
				LevelUpListExplain[i][2]->SetColor(Color8Bit::Yellow);
			}
			else
			{
				std::string NextLevel = std::to_string(CurLevel + 1);
				LevelUpListExplain[i][2]->SetText("레벨: " + NextLevel);
				LevelUpListExplain[i][2]->SetColor(Color8Bit::White);
			}
			break;
		}
		case ESelectList::Candelabrador:
		{
			LevelUpList[i][1]->SetSprite("CandelabradorSprite.png");
			InfoVec[i] = ESelectList::Candelabrador;

			std::string ExplainText = UCandelabrador::Data.ExplainText;
			int CurLevel = UCandelabrador::Data.Level;

			LevelUpListExplain[i][0]->SetText("Candelabrador");
			LevelUpListExplain[i][1]->SetText(ExplainText);

			if (CurLevel == 0)
			{
				LevelUpListExplain[i][2]->SetText("신규 무기!");
				LevelUpListExplain[i][2]->SetColor(Color8Bit::Yellow);
			}
			else
			{
				std::string NextLevel = std::to_string(CurLevel + 1);
				LevelUpListExplain[i][2]->SetText("레벨: " + NextLevel);
				LevelUpListExplain[i][2]->SetColor(Color8Bit::White);
			}
			break;
		}
		case ESelectList::Clover:
		{
			LevelUpList[i][1]->SetSprite("CloverSprite.png");
			InfoVec[i] = ESelectList::Clover;

			std::string ExplainText = UClover::Data.ExplainText;
			int CurLevel = UClover::Data.Level;

			LevelUpListExplain[i][0]->SetText("Clover");
			LevelUpListExplain[i][1]->SetText(ExplainText);

			if (CurLevel == 0)
			{
				LevelUpListExplain[i][2]->SetText("신규 무기!");
				LevelUpListExplain[i][2]->SetColor(Color8Bit::Yellow);
			}
			else
			{
				std::string NextLevel = std::to_string(CurLevel + 1);
				LevelUpListExplain[i][2]->SetText("레벨: " + NextLevel);
				LevelUpListExplain[i][2]->SetColor(Color8Bit::White);
			}
			break;
		}
		case ESelectList::Duplicator:
		{
			LevelUpList[i][1]->SetSprite("DuplicatorSprite.png");
			InfoVec[i] = ESelectList::Duplicator;

			std::string ExplainText = UDuplicator::Data.ExplainText;
			int CurLevel = UDuplicator::Data.Level;

			LevelUpListExplain[i][0]->SetText("Duplicator");
			LevelUpListExplain[i][1]->SetText(ExplainText);

			if (CurLevel == 0)
			{
				LevelUpListExplain[i][2]->SetText("신규 무기!");
				LevelUpListExplain[i][2]->SetColor(Color8Bit::Yellow);
			}
			else
			{
				std::string NextLevel = std::to_string(CurLevel + 1);
				LevelUpListExplain[i][2]->SetText("레벨: " + NextLevel);
				LevelUpListExplain[i][2]->SetColor(Color8Bit::White);
			}
			break;
		}
		case ESelectList::EmptyTome:
		{
			LevelUpList[i][1]->SetSprite("EmptyTomeSprite.png");
			InfoVec[i] = ESelectList::EmptyTome;

			std::string ExplainText = UEmptyTome::Data.ExplainText;
			int CurLevel = UEmptyTome::Data.Level;

			LevelUpListExplain[i][0]->SetText("EmptyTome");
			LevelUpListExplain[i][1]->SetText(ExplainText);

			if (CurLevel == 0)
			{
				LevelUpListExplain[i][2]->SetText("신규 무기!");
				LevelUpListExplain[i][2]->SetColor(Color8Bit::Yellow);
			}
			else
			{
				std::string NextLevel = std::to_string(CurLevel + 1);
				LevelUpListExplain[i][2]->SetText("레벨: " + NextLevel);
				LevelUpListExplain[i][2]->SetColor(Color8Bit::White);
			}
			break;
		}
		case ESelectList::HollowHeart:
		{
			LevelUpList[i][1]->SetSprite("HollowHeartSprite.png");
			InfoVec[i] = ESelectList::HollowHeart;

			std::string ExplainText = UHollowHeart::Data.ExplainText;
			int CurLevel = UHollowHeart::Data.Level;

			LevelUpListExplain[i][0]->SetText("HollowHeart");
			LevelUpListExplain[i][1]->SetText(ExplainText);

			if (CurLevel == 0)
			{
				LevelUpListExplain[i][2]->SetText("신규 무기!");
				LevelUpListExplain[i][2]->SetColor(Color8Bit::Yellow);
			}
			else
			{
				std::string NextLevel = std::to_string(CurLevel + 1);
				LevelUpListExplain[i][2]->SetText("레벨: " + NextLevel);
				LevelUpListExplain[i][2]->SetColor(Color8Bit::White);
			}
			break;
		}
		case ESelectList::Pummarola:
		{
			LevelUpList[i][1]->SetSprite("PummarolaSprite.png");
			InfoVec[i] = ESelectList::Pummarola;

			std::string ExplainText = UPummarola::Data.ExplainText;
			int CurLevel = UPummarola::Data.Level;

			LevelUpListExplain[i][0]->SetText("Pummarola");
			LevelUpListExplain[i][1]->SetText(ExplainText);

			if (CurLevel == 0)
			{
				LevelUpListExplain[i][2]->SetText("신규 무기!");
				LevelUpListExplain[i][2]->SetColor(Color8Bit::Yellow);
			}
			else
			{
				std::string NextLevel = std::to_string(CurLevel + 1);
				LevelUpListExplain[i][2]->SetText("레벨: " + NextLevel);
				LevelUpListExplain[i][2]->SetColor(Color8Bit::White);
			}
			break;
		}
		case ESelectList::Spellbinder:
		{
			LevelUpList[i][1]->SetSprite("SpellbinderSprite.png");
			InfoVec[i] = ESelectList::Spellbinder;

			std::string ExplainText = USpellbinder::Data.ExplainText;
			int CurLevel = USpellbinder::Data.Level;

			LevelUpListExplain[i][0]->SetText("Spellbinder");
			LevelUpListExplain[i][1]->SetText(ExplainText);

			if (CurLevel == 0)
			{
				LevelUpListExplain[i][2]->SetText("신규 무기!");
				LevelUpListExplain[i][2]->SetColor(Color8Bit::Yellow);
			}
			else
			{
				std::string NextLevel = std::to_string(CurLevel + 1);
				LevelUpListExplain[i][2]->SetText("레벨: " + NextLevel);
				LevelUpListExplain[i][2]->SetColor(Color8Bit::White);
			}
			break;
		}
		case ESelectList::Spinach:
		{
			LevelUpList[i][1]->SetSprite("SpinachSprite.png");
			InfoVec[i] = ESelectList::Spinach;

			std::string ExplainText = USpinach::Data.ExplainText;
			int CurLevel = USpinach::Data.Level;

			LevelUpListExplain[i][0]->SetText("Spinach");
			LevelUpListExplain[i][1]->SetText(ExplainText);

			if (CurLevel == 0)
			{
				LevelUpListExplain[i][2]->SetText("신규 무기!");
				LevelUpListExplain[i][2]->SetColor(Color8Bit::Yellow);
			}
			else
			{
				std::string NextLevel = std::to_string(CurLevel + 1);
				LevelUpListExplain[i][2]->SetText("레벨: " + NextLevel);
				LevelUpListExplain[i][2]->SetColor(Color8Bit::White);
			}
			break;
		}
		case ESelectList::Wings:
		{
			LevelUpList[i][1]->SetSprite("WingsSprite.png");
			InfoVec[i] = ESelectList::Wings;

			std::string ExplainText = UWings::Data.ExplainText;
			int CurLevel = UWings::Data.Level;

			LevelUpListExplain[i][0]->SetText("Wings");
			LevelUpListExplain[i][1]->SetText(ExplainText);

			if (CurLevel == 0)
			{
				LevelUpListExplain[i][2]->SetText("신규 무기!");
				LevelUpListExplain[i][2]->SetColor(Color8Bit::Yellow);
			}
			else
			{
				std::string NextLevel = std::to_string(CurLevel + 1);
				LevelUpListExplain[i][2]->SetText("레벨: " + NextLevel);
				LevelUpListExplain[i][2]->SetColor(Color8Bit::White);
			}
			break;
		}
		default:
			break;
		}
	}
}

void UIManager::LevelUpEventEnd()
{
	//레벨업관련 UI 모두 activeoff
	GEngine->SetOrderTimeScale(0, 1.f);
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
	LevelUpText->SetActive(true);
	AdditionalMessage->SetActive(true);

	for (std::pair<UTextWidget*, UTextWidget*> StatusText : PlayerStatusInfoText)
	{
		if (StatusText.first != nullptr && StatusText.second != nullptr)
		{
			StatusText.first->SetActive(true);
			StatusText.second->SetActive(true);
		}
	}

	for (UImage* Sprite : PlayerStatusInfoSprite)
	{
		if (Sprite != nullptr)
		{
			Sprite->SetActive(true);
		}
	}

	for (std::vector<UTextWidget*> Explains : LevelUpListExplain)
	{
		for (UTextWidget* Explain : Explains)
		{
			if (Explain != nullptr)
			{
				Explain->SetActive(true);
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
	LevelUpText->SetActive(false);
	AdditionalMessage->SetActive(false);

	for (std::pair<UTextWidget*, UTextWidget*> StatusText : PlayerStatusInfoText)
	{
		if (StatusText.first != nullptr && StatusText.second != nullptr)
		{
			StatusText.first->SetActive(false);
			StatusText.second->SetActive(false);
		}
	}

	for (UImage* Sprite : PlayerStatusInfoSprite)
	{
		if (Sprite != nullptr)
		{
			Sprite->SetActive(false);
		}
	}

	for (std::vector<UTextWidget*> Explains : LevelUpListExplain)
	{
		for (UTextWidget* Explain : Explains)
		{
			if (Explain != nullptr)
			{
				Explain->SetActive(false);
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