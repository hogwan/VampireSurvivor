#include "PreCompile.h"
#include "DeathUI.h"
#include <EngineCore/TextWidget.h>
#include <EngineCore/Image.h>
#include <EnginePlatform/EngineInput.h>

UDeathUI::UDeathUI() 
{
}

UDeathUI::~UDeathUI() 
{
}

void UDeathUI::BeginPlay()
{
	Super::BeginPlay();

	BackGround = CreateWidget<UImage>(GetWorld(), "BackGround");
	BackGround->SetSprite("DeadBG.png");
	BackGround->SetWidgetScale3D(FVector(1280.f, 720.f, 10.f));
	BackGround->SetPosition({ 0, 0 });
	BackGround->AddToViewPort(10);
	BackGround->SetMulColor(FVector(1.f, 1.f, 1.f, 0.5f));
	BackGround->SetActive(false);

	GameOver = CreateWidget<UImage>(GetWorld(), "GameOver");
	GameOver->SetSprite("GameOver.png");
	GameOver->SetAutoSize(1.2f,true);
	GameOver->SetPosition({ 0.f, 100.f });
	GameOver->AddToViewPort(11);
	GameOver->SetActive(false);

	Button = CreateWidget<UImage>(GetWorld(), "Button");
	Button->SetSprite("RedButton.png");
	Button->SetWidgetScale3D(FVector(150.f, 50.f, 10.f));
	Button->SetPosition({ 0.f, -200.f });
	Button->AddToViewPort(12);
	Button->SetActive(false);

	{
		Arrows.first = CreateWidget<UImage>(GetWorld(), "ArrowLeft");
		Arrows.first->CreateAnimation("ArrowLeft", "Arrow", 0.1f, true);
		Arrows.first->SetAutoSize(2.f, true);
		Arrows.first->SetPosition({ Button->GetLocalPosition().X - Button->GetLocalScale().X / 2.f - 10.f, Button->GetLocalPosition().Y });
		Arrows.first->AddToViewPort(12);
		Arrows.first->ChangeAnimation("ArrowLeft");
		Arrows.first->SetActive(false);
	}

	{
		Arrows.second = CreateWidget<UImage>(GetWorld(), "ArrowRight");
		Arrows.second->CreateAnimation("ArrowRight", "Arrow", 0.1f, true);
		Arrows.second->SetAutoSize(2.f, true);
		Arrows.second->SetRotationDeg(FVector(0.f, 0.f, 180.f));
		Arrows.second->SetPosition({ Button->GetLocalPosition().X + Button->GetLocalScale().X / 2.f + 10.f, Button->GetLocalPosition().Y });
		Arrows.second->AddToViewPort(12);
		Arrows.second->ChangeAnimation("ArrowRight");
		Arrows.second->SetActive(false);
	}

	ButtonText = CreateWidget<UTextWidget>(GetWorld(), "ButtonText");
	ButtonText->SetScale(30.f);
	ButtonText->SetFont("Liberation Sans 보통");
	ButtonText->SetColor(Color8Bit::White);
	ButtonText->SetFlag(static_cast<FW1_TEXT_FLAG>(FW1_TEXT_FLAG::FW1_CENTER | FW1_TEXT_FLAG::FW1_VCENTER));
	ButtonText->SetPosition({ 0, -200 });
	ButtonText->AddToViewPort(13);
	ButtonText->SetText("나가기");
	ButtonText->SetActive(false);
}

void UDeathUI::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	if (IsDeath)
	{
		EventTick(_DeltaTime);
	}
}

void UDeathUI::EventStart()
{
	GEngine->SetOrderTimeScale(0, 0.f);
	IsDeath = true;
	BackGround->SetActive(true);
	GameOver->SetActive(true);
	Button->SetActive(true);
	ButtonText->SetActive(true);
	Arrows.first->SetActive(true);
	Arrows.second->SetActive(true);
}

void UDeathUI::EventTick(float _DeltaTime)
{
	if (UEngineInput::IsDown(VK_SPACE))
	{
		IsDeath = false;
		EventEnd();
	}
}

void UDeathUI::EventEnd()
{
	GEngine->ChangeLevel("TitleLevel");
}
