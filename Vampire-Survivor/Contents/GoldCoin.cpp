#include "PreCompile.h"
#include "GoldCoin.h"

AGoldCoin::AGoldCoin() 
{
}

AGoldCoin::~AGoldCoin() 
{
}

void AGoldCoin::BeginPlay()
{
	Super::BeginPlay();
	
	CreateAnimation("Spin", "CoinSpinGold", 0.1f, true);
	AddToViewPort(5);
	SetAutoSize(2.f, true);
	SetActive(false);
}

void AGoldCoin::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}

