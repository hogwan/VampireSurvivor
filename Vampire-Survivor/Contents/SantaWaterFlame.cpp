#include "PreCompile.h"
#include "SantaWaterFlame.h"

ASantaWaterFlame::ASantaWaterFlame() 
{
}

ASantaWaterFlame::~ASantaWaterFlame() 
{
}

void ASantaWaterFlame::BeginPlay()
{
	Super::BeginPlay();

	Renderer->SetSprite("FlameFX.png");
	Renderer->SetScale(FVector(2.f, 3.f, 10.f));
	Renderer->SetOrder(ERenderOrder::Particle);
	Renderer->SetPlusColor({ 0.f, 1.0f, 1.f });

	Collider->SetActive(false);
}

void ASantaWaterFlame::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	LiveTime -= _DeltaTime;
	if (LiveTime < 0.f)
	{
		Destroy();
	}

	AddActorScale3D(IncreaseTerm * _DeltaTime);

	Alpha -= AlphaDecrease * _DeltaTime;
	Renderer->SetMulColor({ 0.3f, 0.7f, 1.0f, Alpha});
}

