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

UChestUI::UChestUI() 
{

}

UChestUI::~UChestUI() 
{
}

void UChestUI::BeginPlay()
{
	
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
	EventStart();

	AddToViewPort(1);
	//UIOff();



}

void UChestUI::Tick(float _DeltaTime)
{
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
	Circuit->SetActive(false);
	UIOff();
	BlueLight->SetActive(false);
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
		EventEnd();
		return;
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
	ObtainGold = UEngineRandom::MainRandom.RandomFloat(50.f, 100.f);
	Circuit->SetActive(true);
	Light->SetActive(true);
	Light->TurnOn();

	Button->SetActive(false);
	ButtonText->SetActive(false);
	Text->SetActive(false);
	Arrows.first->SetActive(false);
	Arrows.second->SetActive(false);

	//goldsprite, goldText ActiveOn

}

void UChestUI::AfterUnboxingStart()
{
	Circuit->SetActive(false);
}

void UChestUI::EndWaitStart()
{

}