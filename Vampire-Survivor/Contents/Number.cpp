#include "PreCompile.h"
#include "Number.h"

ANumber::ANumber() 
{
	Root = CreateDefaultSubObject<UDefaultSceneComponent>("Root");
	Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	Renderer->SetupAttachment(Root);

	SetRoot(Root);
}

ANumber::~ANumber() 
{
}

void ANumber::BeginPlay()
{
	Super::BeginPlay();
	Renderer->SetScale(FVector::Zero);
	Renderer->SetOrder(ERenderOrder::DamageSprite);
}

void ANumber::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	if (ReachMax)
	{
		CurSize -= SizeUpSpeed * _DeltaTime;
		Alpha -= DecreaseAlpha * _DeltaTime;
		Renderer->SetMulColor({ 1.f,1.f,1.f,Alpha });
	}
	else
	{
		CurSize += SizeUpSpeed * _DeltaTime;
		if (CurSize > MaxSize)
		{
			ReachMax = true;
		}
	}
	Renderer->SetScale(FVector(CurSize, CurSize, 10.f));
}

