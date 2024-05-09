#include "PreCompile.h"
#include "SilverCoin.h"

ASilverCoin::ASilverCoin() 
{
}

ASilverCoin::~ASilverCoin() 
{
}

void ASilverCoin::BeginPlay()
{
	Super::BeginPlay();

	CreateAnimation("Spin", "CoinSpinSilver", 0.1f, true);
	AddToViewPort(5);
	SetAutoSize(2.f, true);
	SetActive(false);
}

void ASilverCoin::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}

