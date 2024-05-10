#include "PreCompile.h"
#include "ChestUI.h"
#include <EngineCore/TextWidget.h>
#include <EngineCore/Image.h>
#include <EngineBase/EngineRandom.h>
#include "UIManager.h"
#include "CircuitWeapon.h"
#include "UnboxingLight.h"
#include "GoldCoin.h"
#include "SilverCoin.h"
#include "EquipManager.h"
#include "PlayGameMode.h"
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

UChestUI::UChestUI() 
{

}

UChestUI::~UChestUI() 
{
}

void UChestUI::BeginPlay()
{
	Super::BeginPlay();
	{
		Circuit = CreateWidget<CircuitWeapon>(GetWorld(), "Circuit");
		Circuit->SetPosition(FVector(0.f, -340.f, 10.f));
		Circuit->AddToViewPort(5);
		Circuit->SetActive(false);
	}

	{
		Light = CreateWidget<UnboxingLight>(GetWorld(), "Light");
		Light->SetWidgetScale3D(FVector(1280.f, 720.f, 10.f));
		Light->AddToViewPort(1);
		Light->SetActive(false);
	}

	// UI를 관리하는 개념의 클래스가 된다.
	{
		Chest = CreateWidget<UImage>(GetWorld(), "Chest");
		Chest->CreateAnimation("Wait", "ChestSpawn", 0.05f, false);
		Chest->CreateAnimation("Open", "ChestOpen", 0.05f, false);
		Chest->SetAutoSize(5.f, true);
		Chest->SetPosition({ 0, -100 });
		Chest->AddToViewPort(3);
	}

	{
		BackBoard = CreateWidget<UImage>(GetWorld(), "BackBoard");
		BackBoard->SetSprite("ChestBackBoard.png");
		BackBoard->SetWidgetScale3D(FVector(400.f, 500.f, 10.f));
		BackBoard->SetPosition({ 0, 0 });
		BackBoard->AddToViewPort(2);
	}

	{
		Text = CreateWidget<UTextWidget>(GetWorld(), "Text");
		Text->SetScale(30.f);
		Text->SetFont("Liberation Sans 보통");
		Text->SetColor(Color8Bit::White);
		Text->SetFlag(static_cast<FW1_TEXT_FLAG>(FW1_TEXT_FLAG::FW1_CENTER | FW1_TEXT_FLAG::FW1_VCENTER));
		Text->SetPosition({ 0, 200 });
		Text->AddToViewPort(3);
		Text->SetText("보물 발견!");
	}

	{
		Button = CreateWidget<UImage>(GetWorld(), "BackBoard");
		Button->SetSprite("BlueButton.png");
		Button->SetWidgetScale3D(FVector(120.f, 50.f, 10.f));
		Button->SetPosition({ 0, -200 });
		Button->AddToViewPort(3);
	}

	{
		ButtonText = CreateWidget<UTextWidget>(GetWorld(), "Text");
		ButtonText->SetScale(30.f);
		ButtonText->SetFont("Liberation Sans 보통");
		ButtonText->SetColor(Color8Bit::White);
		ButtonText->SetFlag(static_cast<FW1_TEXT_FLAG>(FW1_TEXT_FLAG::FW1_CENTER | FW1_TEXT_FLAG::FW1_VCENTER));
		ButtonText->SetPosition({ 0, -200 });
		ButtonText->AddToViewPort(3);
		ButtonText->SetText("열기");
	}

	{
		Arrows.first = CreateWidget<UImage>(GetWorld(), "ArrowLeft");
		Arrows.first->CreateAnimation("ArrowLeft", "Arrow", 0.1f, true);
		Arrows.first->SetAutoSize(2.f, true);
		Arrows.first->SetPosition({ Button->GetLocalPosition().X - Button->GetLocalScale().X/2.f - 10.f, Button->GetLocalPosition().Y});
		Arrows.first->AddToViewPort(3);
		Arrows.first->ChangeAnimation("ArrowLeft");
	}

	{
		Arrows.second = CreateWidget<UImage>(GetWorld(), "ArrowRight");
		Arrows.second->CreateAnimation("ArrowRight", "Arrow", 0.1f, true);
		Arrows.second->SetAutoSize(2.f, true);
		Arrows.second->SetRotationDeg(FVector(0.f, 0.f, 180.f));
		Arrows.second->SetPosition({ Button->GetLocalPosition().X + Button->GetLocalScale().X / 2.f + 10.f, Button->GetLocalPosition().Y });
		Arrows.second->AddToViewPort(3);
		Arrows.second->ChangeAnimation("ArrowRight");
	}

	{
		BlueLight = CreateWidget<UImage>(GetWorld(), "BlueLight");
		BlueLight->SetSprite("OpenEffect1.png");
		BlueLight->SetWidgetScale3D(FVector(50.f, 350.f, 10.f));
		BlueLight->SetPosition({ 0, 67 });
		BlueLight->AddToViewPort(4);
		BlueLight->SetMulColor(FVector(1.f, 1.f, 1.f, 0.7f));
		BlueLight->SetActive(false);
	}

	{
		GoldStatus.first = CreateWidget<UTextWidget>(GetWorld(), "GoldText");
		GoldStatus.first->SetScale(30.f);
		GoldStatus.first->SetFont("Liberation Sans 보통");
		GoldStatus.first->SetColor(Color8Bit::Yellow);
		GoldStatus.first->SetFlag(static_cast<FW1_TEXT_FLAG>(FW1_TEXT_FLAG::FW1_CENTER | FW1_TEXT_FLAG::FW1_VCENTER));
		GoldStatus.first->SetPosition({ 0, -200 });
		GoldStatus.first->AddToViewPort(3);
		GoldStatus.first->SetActive(false);

		GoldStatus.second = CreateWidget<UImage>(GetWorld(), "GoldSprite");
		GoldStatus.second->SetSprite("CoinSpinGold_0.png");
		GoldStatus.second->SetAutoSize(2.f, true);
		GoldStatus.second->SetPosition({ 0, -200 });
		GoldStatus.second->AddToViewPort(3);
		GoldStatus.second->SetActive(false);
	}

	{
		SelectedWeapon.push_back(CreateWidget<UImage>(GetWorld(), "WeaponSprite"));
		SelectedWeapon[0]->SetAutoSize(2.f, true);
		SelectedWeapon[0]->SetPosition({ 0.f, 50.f });
		SelectedWeapon[0]->AddToViewPort(6);
		SelectedWeapon[0]->SetActive(false);

		SelectedWeapon.push_back(CreateWidget<UImage>(GetWorld(), "WeaponSpriteBack"));
		SelectedWeapon[1]->SetMaterial("Sphere");
		SelectedWeapon[1]->SetPlusColor(FVector(0.1f, 0.1f, 0.1f));
		SelectedWeapon[1]->SetAutoSize(1.f, true);
		SelectedWeapon[1]->SetPosition({ 0.f, 50.f });
		SelectedWeapon[1]->SetSprite("ItemEffect.png");
		SelectedWeapon[1]->AddToViewPort(5);
		SelectedWeapon[1]->SetActive(false);

		SelectedWeapon.push_back(CreateWidget<UImage>(GetWorld(), "FX"));
		SelectedWeapon[2]->SetScale(FVector(100.f, 100.f, 10.f));
		SelectedWeapon[2]->SetPosition({ 0.f, 50.f });
		SelectedWeapon[2]->SetSprite("Chestfx.png");
		SelectedWeapon[2]->AddToViewPort(4);
		SelectedWeapon[2]->SetActive(false);
	}

	for (int i = 0; i < 3; i++)
	{
		ExplainSpriteVec.push_back(CreateWidget<UImage>(GetWorld(), "ExplainSprite"));
		ExplainSpriteVec[i]->SetActive(false);
	}

	{
		ExplainSpriteVec[0]->SetSprite("Explain.png");
		ExplainSpriteVec[0]->SetWidgetScale3D(FVector(500.f, 120.f, 10.f));
		ExplainSpriteVec[0]->SetPosition(FVector(0.f, -300.f, 10.f));
		ExplainSpriteVec[0]->AddToViewPort(5);
		ExplainSpriteVec[0]->SetPlusColor(FVector(0.2f, 0.2f, 0.2f));

		ExplainSpriteVec[1]->SetSprite("ItemBox.png");
		ExplainSpriteVec[1]->SetAutoSize(2.f, true);
		ExplainSpriteVec[1]->SetPosition(FVector(-200.f, -300.f, 10.f));
		ExplainSpriteVec[1]->AddToViewPort(6);

		ExplainSpriteVec[2]->SetAutoSize(2.f, true);
		ExplainSpriteVec[2]->SetPosition(FVector(-200.f, -300.f, 10.f));
		ExplainSpriteVec[2]->AddToViewPort(7);
	}

	for (int i = 0; i < 3; i++)
	{
		ExplainTextVec.push_back(CreateWidget<UTextWidget>(GetWorld(), "ExplainText"));
		ExplainTextVec[i]->SetActive(false);
	}

	{
		ExplainTextVec[0]->SetScale(15.f);
		ExplainTextVec[0]->SetFont("Liberation Sans 보통");
		ExplainTextVec[0]->SetColor(Color8Bit::White);
		ExplainTextVec[0]->SetFlag(static_cast<FW1_TEXT_FLAG>(FW1_TEXT_FLAG::FW1_CENTER | FW1_TEXT_FLAG::FW1_VCENTER));
		ExplainTextVec[0]->SetPosition({ -200.f, -250.f });
		ExplainTextVec[0]->AddToViewPort(6);

		ExplainTextVec[1]->SetScale(15.f);
		ExplainTextVec[1]->SetFont("Liberation Sans 보통");
		ExplainTextVec[1]->SetColor(Color8Bit::Yellow);
		ExplainTextVec[1]->SetFlag(static_cast<FW1_TEXT_FLAG>(FW1_TEXT_FLAG::FW1_CENTER | FW1_TEXT_FLAG::FW1_VCENTER));
		ExplainTextVec[1]->SetPosition({ 0.f, -250.f });
		ExplainTextVec[1]->AddToViewPort(6);

		ExplainTextVec[2]->SetScale(15.f);
		ExplainTextVec[2]->SetFont("Liberation Sans 보통");
		ExplainTextVec[2]->SetColor(Color8Bit::White);
		ExplainTextVec[2]->SetFlag(static_cast<FW1_TEXT_FLAG>(FW1_TEXT_FLAG::FW1_LEFT | FW1_TEXT_FLAG::FW1_VCENTER));
		ExplainTextVec[2]->SetPosition({ -150.f, -300.f });
		ExplainTextVec[2]->AddToViewPort(6);
	}

	for (int i = 0; i < 50; i++)
	{
		int rand = UEngineRandom::MainRandom.RandomInt(0, 1);
		ACoin* Coin = nullptr;
		if (rand == 0)
		{
			Coin = CreateWidget<ASilverCoin>(GetWorld(), "SilverCoin");
		}
		else
		{
			Coin = CreateWidget<AGoldCoin>(GetWorld(), "GoldCoin");
		}

		CoinVec.push_back(Coin);
	}


	StateInit();
	UIOff();

	AddToViewPort(1);

}

void UChestUI::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	if (IsUnboxing)
	{
		EventTick(_DeltaTime);
	}
}


void UChestUI::EventStart()
{
	GEngine->SetOrderTimeScale(0, 0.f);
	IsUnboxing = true;
	UIOn();
	ButtonText->SetText("열기");
	AccGold = 0.f;
	State.ChangeState("Wait");
}

void UChestUI::EventTick(float _DeltaTime)
{
	if (IsUnboxing)
	{
		State.Update(_DeltaTime);
	}
}

void UChestUI::EventEnd()
{
	GEngine->SetOrderTimeScale(0, 1.f);
	UContentsValue::Gold += static_cast<int>(AccGold);
	AccGold = 0.f;
	UIOff();
	IsUnboxing = false;
}

void UChestUI::UIOn()
{
	Chest->SetActive(true);
	BackBoard->SetActive(true);
	Text->SetActive(true);
	Button->SetActive(true);
	ButtonText->SetActive(true);
	Arrows.first->SetActive(true);
	Arrows.second->SetActive(true);
}

void UChestUI::UIOff()
{
	Chest->SetActive(false);
	BackBoard->SetActive(false);
	Text->SetActive(false);
	Button->SetActive(false);
	ButtonText->SetActive(false);
	Arrows.first->SetActive(false);
	Arrows.second->SetActive(false);
	Circuit->SetActive(false);
	BlueLight->SetActive(false);
	GoldStatus.first->SetActive(false);
	GoldStatus.second->SetActive(false);

	for (int i = 0; i < 3; i++)
	{
		SelectedWeapon[i]->SetActive(false);
	}
	for (int i = 0; i < 3; i++)
	{
		ExplainTextVec[i]->SetActive(false);
	}
	for (int i = 0; i < 3; i++)
	{
		ExplainSpriteVec[i]->SetActive(false);
	}
}

void UChestUI::StateInit()
{
	State.CreateState("Wait");
	State.CreateState("Unboxing");
	State.CreateState("AfterUnboxing");
	State.CreateState("EndWait");

	State.SetStartFunction("Wait", std::bind(&UChestUI::WaitStart, this));
	State.SetUpdateFunction("Wait", std::bind(&UChestUI::Wait, this, std::placeholders::_1));

	State.SetStartFunction("Unboxing", std::bind(&UChestUI::UnboxingStart, this));
	State.SetUpdateFunction("Unboxing", std::bind(&UChestUI::Unboxing, this, std::placeholders::_1));

	State.SetStartFunction("AfterUnboxing", std::bind(&UChestUI::AfterUnboxingStart, this));
	State.SetUpdateFunction("AfterUnboxing", std::bind(&UChestUI::AfterUnboxing, this, std::placeholders::_1));

	State.SetStartFunction("EndWait", std::bind(&UChestUI::EndWaitStart, this));
	State.SetUpdateFunction("EndWait", std::bind(&UChestUI::EndWait, this, std::placeholders::_1));
}

void UChestUI::Wait(float _DeltaTime)
{
	if (UEngineInput::IsDown(VK_SPACE))
	{
		State.ChangeState("Unboxing");
		return;
	}
}

void UChestUI::Unboxing(float _DeltaTime)
{
	BlueLight->SetActive(true);
	AccTime += _DeltaTime;
	if (AccTime > UnboxingTime)
	{
		AccTime = 0.f;
		State.ChangeState("AfterUnboxing");
		return;
	}

	if (AccTime > TurnOffTime)
	{
		Light->TurnOff();
	}

	float IncreaseSpeed = ObtainGold / UnboxingTime;
	AccGold += IncreaseSpeed * _DeltaTime;
	GoldStatus.first->SetText(std::to_string(AccGold).substr(0,5));


	CoinTimeAcc += _DeltaTime;
	if (CoinTimeAcc > CoinThrowTime)
	{
		if (CoinNumber > 49) CoinNumber = 0;

		CoinTimeAcc = 0.f;

		FVector ThrowVector = FVector::Up;

		float RandomThrowPower = UEngineRandom::MainRandom.RandomFloat(300.f, 500.f);
		float RandomThrowVectorX = UEngineRandom::MainRandom.RandomFloat(-1.5f, 1.5f);
		float RandomRotation = UEngineRandom::MainRandom.RandomFloat(0.f, 180.f);

		ThrowVector += FVector::Right * RandomThrowVectorX;

		CoinVec[CoinNumber]->SetRotationDeg(FVector(0.f, 0.f, RandomRotation));
		CoinVec[CoinNumber]->SetPosition({ 0, -100 });
		CoinVec[CoinNumber]->SetInitialVector(ThrowVector, RandomThrowPower);

		++CoinNumber;
	}

}

void UChestUI::AfterUnboxing(float _DeltaTime)
{
	AfterUnboxingAcc += _DeltaTime;
	if (AfterUnboxingAcc > AfterUnboxingTime)
	{
		AfterUnboxingAcc = 0.f;
		State.ChangeState("EndWait");
	}

	SelectedWeapon[2]->AddRotationDeg(FVector(0.f, 0.f, 90.f * _DeltaTime));

	if (!Bigger)
	{
		SelectedWeapon[2]->AddWidgetScale3D(FVector(50.f, 50.f, 0.f) * _DeltaTime);
	}
	else
	{
		SelectedWeapon[2]->AddWidgetScale3D(FVector(-50.f, -50.f, 0.f) * _DeltaTime);
	}

	SwitchAccTime += _DeltaTime;
	if (SwitchAccTime > SwitchTime)
	{
		SwitchAccTime = 0.f;
		Bigger = !Bigger;
	}

}

void UChestUI::EndWait(float _DeltaTime)
{
	Button->SetActive(true);
	ButtonText->SetActive(true);
	ButtonText->SetText("DONE");
	Arrows.first->SetActive(true);
	Arrows.second->SetActive(true);

	if (UEngineInput::IsDown(VK_SPACE))
	{
		ItemEquipLogic();
		EventEnd();
		return;
	}

	SelectedWeapon[2]->AddRotationDeg(FVector(0.f, 0.f, 90.f * _DeltaTime));

	if (!Bigger)
	{
		SelectedWeapon[2]->AddWidgetScale3D(FVector(50.f, 50.f, 0.f) * _DeltaTime);
	}
	else
	{
		SelectedWeapon[2]->AddWidgetScale3D(FVector(-50.f, -50.f, 0.f) * _DeltaTime);
	}

	SwitchAccTime += _DeltaTime;
	if (SwitchAccTime > SwitchTime)
	{
		SwitchAccTime = 0.f;
		Bigger = !Bigger;
	}
}

void UChestUI::WaitStart()
{
	Chest->ChangeAnimation("Wait");
	return;
}

void UChestUI::UnboxingStart()
{
	Chest->ChangeAnimation("Open");
	Random = UIManager::RandomPickLogic(static_cast<int>(ESelectList::Axe), static_cast<int>(ESelectList::Whip));
	ItemSelectLogic();
	ObtainGold = static_cast<float>(UEngineRandom::MainRandom.RandomInt(50, 100));
	Circuit->SetActive(true);
	Light->SetActive(true);
	Light->TurnOn();

	Button->SetActive(false);
	ButtonText->SetActive(false);
	Text->SetActive(false);
	Arrows.first->SetActive(false);
	Arrows.second->SetActive(false);

	GoldStatus.first->SetPosition(FVector(0.f, -200.f, 10.f));
	GoldStatus.first->SetActive(true);

	GoldStatus.second->SetPosition(FVector(50.f, -200.f, 10.f));
	GoldStatus.second->SetActive(true);
}

void UChestUI::AfterUnboxingStart()
{
	Circuit->SetActive(false);
	GoldStatus.first->SetText(std::to_string(ObtainGold).substr(0, 5));
	SelectedWeapon[2]->SetActive(true);
	SelectedWeapon[1]->SetActive(true);
	SelectedWeapon[0]->SetActive(true);
}

void UChestUI::EndWaitStart()
{
	BlueLight->SetActive(false);
	GoldStatus.first->SetPosition(FVector(0.f, 200.f, 10.f));
	GoldStatus.second->SetPosition(FVector(50.f, 200.f, 10.f));

	for (int i = 0; i < 3; i++)
	{
		ExplainSpriteVec[i]->SetActive(true);
	}

	for (int i = 0; i < 3; i++)
	{
		ExplainTextVec[i]->SetActive(true);
	}
}

void UChestUI::ItemSelectLogic()
{
	ESelectList List = static_cast<ESelectList>(Random);
	switch (List)
	{
	case ESelectList::Axe:
	{
		SelectedWeapon[0]->SetSprite("AxeSprite.png");
		std::string ExplainText = UAxe::Data.ExplainText;
		int CurLevel = UAxe::Data.Level;

		ExplainSpriteVec[2]->SetSprite("AxeSprite.png");
		ExplainTextVec[0]->SetText("레벨: " + std::to_string(CurLevel + 1));
		ExplainTextVec[1]->SetText("Axe");
		ExplainTextVec[2]->SetText(ExplainText);
		break;
	}
	case ESelectList::Cross:
	{
		SelectedWeapon[0]->SetSprite("CrossSprite.png");
		std::string ExplainText = UCross::Data.ExplainText;
		int CurLevel = UCross::Data.Level;

		ExplainSpriteVec[2]->SetSprite("CrossSprite.png");
		ExplainTextVec[0]->SetText("레벨: " + std::to_string(CurLevel + 1));
		ExplainTextVec[1]->SetText("Cross");
		ExplainTextVec[2]->SetText(ExplainText);
		break;
	}
	case ESelectList::FireWand:
	{
		SelectedWeapon[0]->SetSprite("FireWandSprite.png");
		std::string ExplainText = UFireWand::Data.ExplainText;
		int CurLevel = UFireWand::Data.Level;

		ExplainSpriteVec[2]->SetSprite("FireWandSprite.png");
		ExplainTextVec[0]->SetText("레벨: " + std::to_string(CurLevel + 1));
		ExplainTextVec[1]->SetText("FireWand");
		ExplainTextVec[2]->SetText(ExplainText);
		break;
	}
	case ESelectList::Garlic:
	{
		SelectedWeapon[0]->SetSprite("GarlicSprite.png");
		std::string ExplainText = UGarlic::Data.ExplainText;
		int CurLevel = UGarlic::Data.Level;

		ExplainSpriteVec[2]->SetSprite("GarlicSprite.png");
		ExplainTextVec[0]->SetText("레벨: " + std::to_string(CurLevel + 1));
		ExplainTextVec[1]->SetText("Garlic");
		ExplainTextVec[2]->SetText(ExplainText);
		break;
	}
	case ESelectList::KingBible:
	{
		SelectedWeapon[0]->SetSprite("KingBibleSprite.png");
		std::string ExplainText = UKingBible::Data.ExplainText;
		int CurLevel = UKingBible::Data.Level;

		ExplainSpriteVec[2]->SetSprite("KingBibleSprite.png");
		ExplainTextVec[0]->SetText("레벨: " + std::to_string(CurLevel + 1));
		ExplainTextVec[1]->SetText("KingBible");
		ExplainTextVec[2]->SetText(ExplainText);
		break;
	}
	case ESelectList::Knife:
	{
		SelectedWeapon[0]->SetSprite("KnifeSprite.png");
		std::string ExplainText = UKnife::Data.ExplainText;
		int CurLevel = UKnife::Data.Level;

		ExplainSpriteVec[2]->SetSprite("KnifeSprite.png");
		ExplainTextVec[0]->SetText("레벨: " + std::to_string(CurLevel + 1));
		ExplainTextVec[1]->SetText("Knife");
		ExplainTextVec[2]->SetText(ExplainText);
		break;
	}
	case ESelectList::LightingRing:
	{
		SelectedWeapon[0]->SetSprite("LightingRingSprite.png");
		std::string ExplainText = ULightingRing::Data.ExplainText;
		int CurLevel = ULightingRing::Data.Level;

		ExplainSpriteVec[2]->SetSprite("LightingRingSprite.png");
		ExplainTextVec[0]->SetText("레벨: " + std::to_string(CurLevel + 1));
		ExplainTextVec[1]->SetText("LightingRing");
		ExplainTextVec[2]->SetText(ExplainText);
		break;
	}
	case ESelectList::MagicWand:
	{
		SelectedWeapon[0]->SetSprite("MagicWandSprite.png");
		std::string ExplainText = UMagicWand::Data.ExplainText;
		int CurLevel = UMagicWand::Data.Level;

		ExplainSpriteVec[2]->SetSprite("MagicWandSprite.png");
		ExplainTextVec[0]->SetText("레벨: " + std::to_string(CurLevel + 1));
		ExplainTextVec[1]->SetText("MagicWand");
		ExplainTextVec[2]->SetText(ExplainText);
		break;
	}
	case ESelectList::RuneTracer:
	{
		SelectedWeapon[0]->SetSprite("RuneTracerSprite.png");
		std::string ExplainText = URuneTracer::Data.ExplainText;
		int CurLevel = URuneTracer::Data.Level;

		ExplainSpriteVec[2]->SetSprite("RuneTracerSprite.png");
		ExplainTextVec[0]->SetText("레벨: " + std::to_string(CurLevel + 1));
		ExplainTextVec[1]->SetText("RuneTracer");
		ExplainTextVec[2]->SetText(ExplainText);
		break;

	}
	case ESelectList::SantaWater:
	{
		SelectedWeapon[0]->SetSprite("SantaWaterSprite.png");
		std::string ExplainText = USantaWater::Data.ExplainText;
		int CurLevel = USantaWater::Data.Level;

		ExplainSpriteVec[2]->SetSprite("SantaWaterSprite.png");
		ExplainTextVec[0]->SetText("레벨: " + std::to_string(CurLevel + 1));
		ExplainTextVec[1]->SetText("SantaWater");
		ExplainTextVec[2]->SetText(ExplainText);
		break;
	}
	case ESelectList::Whip:
	{
		SelectedWeapon[0]->SetSprite("WhipSprite.png");
		std::string ExplainText = UWhip::Data.ExplainText;
		int CurLevel = UWhip::Data.Level;

		ExplainSpriteVec[2]->SetSprite("WhipSprite.png");
		ExplainTextVec[0]->SetText("레벨: " + std::to_string(CurLevel + 1));
		ExplainTextVec[1]->SetText("Whip");
		ExplainTextVec[2]->SetText(ExplainText);
		break;
	}
	default:
		break;
	}
}

void UChestUI::ItemEquipLogic()
{
	ESelectList List = static_cast<ESelectList>(Random);
	switch (List)
	{
	case ESelectList::Axe:
	{
		APlayGameMode::EquipManager->EquipWeapon(EWeapon::Axe);
		break;
	}
	case ESelectList::Cross:
	{
		APlayGameMode::EquipManager->EquipWeapon(EWeapon::Cross);
		break;
	}
	case ESelectList::FireWand:
	{
		APlayGameMode::EquipManager->EquipWeapon(EWeapon::FireWand);
		break;
	}
	case ESelectList::Garlic:
	{
		APlayGameMode::EquipManager->EquipWeapon(EWeapon::Garlic);
		break;
	}
	case ESelectList::KingBible:
	{
		APlayGameMode::EquipManager->EquipWeapon(EWeapon::KingBible);
		break;
	}
	case ESelectList::Knife:
	{
		APlayGameMode::EquipManager->EquipWeapon(EWeapon::Knife);
		break;
	}
	case ESelectList::LightingRing:
	{
		APlayGameMode::EquipManager->EquipWeapon(EWeapon::LightingRing);
		break;
	}
	case ESelectList::MagicWand:
	{
		APlayGameMode::EquipManager->EquipWeapon(EWeapon::MagicWand);
		break;
	}
	case ESelectList::RuneTracer:
	{
		APlayGameMode::EquipManager->EquipWeapon(EWeapon::RuneTracer);
		break;

	}
	case ESelectList::SantaWater:
	{
		APlayGameMode::EquipManager->EquipWeapon(EWeapon::SantaWater);
		break;
	}
	case ESelectList::Whip:
	{
		APlayGameMode::EquipManager->EquipWeapon(EWeapon::Whip);
		break;
	}
	default:
		break;
	}
}
