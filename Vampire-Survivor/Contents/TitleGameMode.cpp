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

	LeftCharactor = CreateDefaultSubObject<USpriteRenderer>("LeftCharactor");
	LeftCharactor->SetupAttachment(Root);

	CenterCharactor = CreateDefaultSubObject<USpriteRenderer>("CenterCharactor");
	CenterCharactor->SetupAttachment(Root);

	RightCharactor = CreateDefaultSubObject<USpriteRenderer>("RightCharactor");
	RightCharactor->SetupAttachment(Root);

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


	Buttons.first = CreateWidget<UImage>(GetWorld(), "GameStartButton");
	Buttons.first->AddToViewPort(1);
	Buttons.first->SetSprite("BlueButton.png");
	Buttons.first->SetScale(FVector(220.f, 70.f, 10.f));
	Buttons.first->SetPosition(FVector(0.f, -100.f));
	
	Buttons.second = CreateWidget<UTextWidget>(GetWorld(), "GameStartButton");
	Buttons.second->SetFont("Liberation Sans 보통");
	Buttons.second->SetScale(30.0f);
	Buttons.second->SetColor(Color8Bit::White);
	Buttons.second->SetPosition({ 0.f, -100.f });
	Buttons.second->SetText("시작");
	Buttons.second->AddToViewPort(3);


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

	if (UEngineInput::IsDown(VK_SPACE))
	{

		GEngine->ChangeLevel("PlayLevel");
	}



	FVector ButtonPos = Buttons.first->GetWorldPosition();
	FVector ButtonScale = Buttons.first->GetWidgetScale3D();
	SelectArrows.first->SetPosition(FVector(ButtonPos.X - ButtonScale.X / 2.f - 20.f, ButtonPos.Y, 10.f));
	SelectArrows.second->SetPosition(FVector(ButtonPos.X + ButtonScale.X / 2.f + 20.f, ButtonPos.Y, 10.f));

	
}
