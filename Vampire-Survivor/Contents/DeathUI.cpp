#include "PreCompile.h"
#include "DeathUI.h"
#include <EngineCore/TextWidget.h>
#include <EngineCore/Image.h>

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
	BackGround->SetSprite("ChestBackBoard.png");
	BackGround->SetWidgetScale3D(FVector(400.f, 500.f, 10.f));
	BackGround->SetPosition({ 0, 0 });
	BackGround->AddToViewPort(2);


	BackGround = nullptr;
	Button = nullptr;
	ButtonText = nullptr;
	Arrows;
}

void UDeathUI::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}

