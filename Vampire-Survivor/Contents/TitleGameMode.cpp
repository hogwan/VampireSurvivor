#include "PreCompile.h"
#include "TitleGameMode.h"
#include <EngineCore/Camera.h>

ATitleGameMode::ATitleGameMode() 
{
	Root = CreateDefaultSubObject<UDefaultSceneComponent>("Root");
	BG = CreateDefaultSubObject<USpriteRenderer>("BG");
	BG->SetupAttachment(Root);

	Title = CreateDefaultSubObject<USpriteRenderer>("Title");
	Title->SetupAttachment(Root);

	Cash = CreateDefaultSubObject<USpriteRenderer>("CashSprite");
	Cash->SetupAttachment(Root);

	CashBoard = CreateDefaultSubObject<USpriteRenderer>("CashBoard");
	CashBoard->SetupAttachment(Root);

	BlackBack = CreateDefaultSubObject<USpriteRenderer>("BlackBack");
	BlackBack->SetupAttachment(Root);

	SetRoot(Root);
}

ATitleGameMode::~ATitleGameMode() 
{
}

void ATitleGameMode::BeginPlay()
{
	Super::BeginPlay();

	GetWorld()->GetMainCamera()->SetActorLocation(FVector(0.f, 0.f, -1000.f));

	BG->SetSprite("IntroBG.png");
	BG->SetAutoSize(4.f, true);
	BG->SetOrder(ERenderOrder::Back);

	Title->SetSprite("Title.png");
	Title->SetAutoSize(1.f, true);
	Title->SetPosition(FVector(0.f, 150.f, 0.f));
	Title->SetOrder(ERenderOrder::Title);

	Cash->SetSprite("CashInHand.png");
	Cash->SetAutoSize(2.f, true);
	Cash->SetPosition(FVector(-80.f, 330.f, 0.f));
	Cash->SetOrder(ERenderOrder::Title);

	CashBoard->SetSprite("CashBoard.png");
	CashBoard->SetScale(FVector(250.f, 50.f, 10.f));
	CashBoard->SetPosition(FVector(0.f, 330.f, 0.f));
	CashBoard->SetOrder(ERenderOrder::Title);

	BlackBack->SetSprite("HpBar2.png");
	BlackBack->SetScale(FVector(1280.f, 80.f, 10.f));
	BlackBack->SetPosition(FVector(0.f, 330.f, 0.f));
	BlackBack->SetOrder(ERenderOrder::Title);
	BlackBack->SetMulColor(FVector(1.f, 1.f, 1.f, 0.5f));

	

	Buttons.push_back(std::pair(nullptr, nullptr));
	Buttons.push_back(std::pair(nullptr, nullptr));

	Buttons[0].first = CreateWidget<UImage>(GetWorld(), "GameStartButton");
	Buttons[0].first->AddToViewPort(1);
	Buttons[0].first->SetSprite("BlueButton.png");
	Buttons[0].first->SetScale(FVector(220.f, 70.f, 10.f));
	Buttons[0].first->SetPosition(FVector(0.f, -50.f));
	//Button[0].second = text

	Buttons[1].first = CreateWidget<UImage>(GetWorld(), "PowerUpButton");
	Buttons[1].first->AddToViewPort(1);
	Buttons[1].first->SetSprite("GreenButton.png");
	Buttons[1].first->SetScale(FVector(150.f, 70.f, 10.f));
	Buttons[1].first->SetPosition(FVector(0.f, -200.f));
	//Button[1].second = textp


	SelectArrows.first = CreateWidget<UImage>(GetWorld(), "ArrowLeft");
	SelectArrows.first->AddToViewPort(4);
	SelectArrows.first->CreateAnimation("Rotate", "Arrow", 0.1f, true);
	SelectArrows.first->SetAutoSize(3.f, true);
	SelectArrows.first->ChangeAnimation("Rotate");

	SelectArrows.second = CreateWidget<UImage>(GetWorld(), "ArrowLeft");
	SelectArrows.second->AddToViewPort(4);
	SelectArrows.second->CreateAnimation("Rotate", "Arrow", 0.1f, true);
	SelectArrows.second->SetAutoSize(3.f, true);

	/*FVector Scale = SelectArrows.second->GetLocalScale();
	Scale.X = -Scale.X;
	SelectArrows.second->SetScale(Scale);*/
	SelectArrows.second->SetRotationDeg(FVector(0.f, 0.f, 180.f));
	SelectArrows.second->ChangeAnimation("Rotate");

}

void ATitleGameMode::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	if (UEngineInput::IsDown(VK_DOWN))
	{
		if (SelectIndex > 0) return;

		SelectIndex++;
	}

	if (UEngineInput::IsDown(VK_UP))
	{
		if (SelectIndex == 0) return;

		SelectIndex--;
	}

	if (UEngineInput::IsDown(VK_SPACE))
	{
		switch (SelectIndex)
		{
		case 0:
			GEngine->ChangeLevel("PlayLevel");
			break;
		case 1 :
			OpenPowerUpUI();
			break;
		default:
			break;
		}
	}



	FVector ButtonPos = Buttons[SelectIndex].first->GetWorldPosition();
	FVector ButtonScale = Buttons[SelectIndex].first->GetWidgetScale3D();
	SelectArrows.first->SetPosition(FVector(ButtonPos.X - ButtonScale.X / 2.f - 20.f, ButtonPos.Y, 10.f));
	SelectArrows.second->SetPosition(FVector(ButtonPos.X + ButtonScale.X / 2.f + 20.f, ButtonPos.Y, 10.f));

	
}

void ATitleGameMode::OpenPowerUpUI()
{
}

