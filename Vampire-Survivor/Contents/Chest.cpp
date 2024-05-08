#include "PreCompile.h"
#include "Chest.h"
#include <EngineCore/TextWidget.h>
#include <EngineCore/Image.h>

UChest::UChest() 
{
}

UChest::~UChest() 
{
}

void UChest::BeginPlay()
{
	// UI를 관리하는 개념의 클래스가 된다.
	{
		Chest = CreateWidget<UImage>(GetWorld(), "Chest");
		Chest->SetupAttachment(this);
		Chest->CreateAnimation("Open", "ChestOpen", 0.05f, false);
		Chest->SetAutoSize(2.f, true);
		Chest->SetPosition({ 0, -100 });
	}

	{
		BackBoard = CreateWidget<UImage>(GetWorld(), "BackBoard");
		BackBoard->SetupAttachment(this);
		BackBoard->SetSprite("ChestBackBoard.png");
		BackBoard->SetWidgetScale3D(FVector(400.f, 500.f, 10.f));
		BackBoard->SetPosition({ 0, 0 });
	}

	{
		Text = CreateWidget<UTextWidget>(GetWorld(), "Text");
		Text->SetupAttachment(this);
		Text->SetScale(14.f);
		Text->SetFont("Liberation Sans 보통");
		Text->SetColor(Color8Bit::White);
		Text->SetFlag(static_cast<FW1_TEXT_FLAG>(FW1_TEXT_FLAG::FW1_CENTER | FW1_TEXT_FLAG::FW1_VCENTER));
		Text->SetPosition({ 0, 200 });
	}

	{
		Button = CreateWidget<UImage>(GetWorld(), "BackBoard");
		Button->SetupAttachment(this);
		Button->SetSprite("BlueButton.png");
		Button->SetWidgetScale3D(FVector(120.f, 50.f, 10.f));
		Button->SetPosition({ 0, -200 });
	}

	{
		ButtonText = CreateWidget<UImage>(GetWorld(), "BackBoard");
		ButtonText->SetupAttachment(this);
		ButtonText->SetSprite("ChestBackBoard.png");
		ButtonText->SetWidgetScale3D(FVector(300.f, 400.f, 10.f));
		ButtonText->SetPosition({ 0, 0 });
	}

	{
		Arrows.first = CreateWidget<UImage>(GetWorld(), "ArrowLeft");
		Arrows.first->SetupAttachment(this);
		Arrows.first->CreateAnimation("ArrowLeft", "Arrow", 0.1f, true);
		Arrows.first->SetWidgetScale3D(FVector(Button->GetPosition().X - Button->GetScale().X/2.f, Button->GetPosition().Y, 10.f));
		Arrows.first->SetPosition({ 0, 0 });
	}

	{
		Arrows.second = CreateWidget<UImage>(GetWorld(), "ArrowLeft");
		Arrows.second->SetupAttachment(this);
		Arrows.second->CreateAnimation("ArrowLeft", "Arrow", 0.1f, true);
		Arrows.second->SetWidgetScale3D(FVector(Button->GetPosition().X - Button->GetScale().X / 2.f, Button->GetPosition().Y, 10.f));
		Arrows.second->SetPosition({ 0, 0 });
	}





	AddToViewPort(1);
}

void UChest::Tick(float _DeltaTime)
{
}

