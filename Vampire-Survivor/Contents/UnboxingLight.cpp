#include "PreCompile.h"
#include "UnboxingLight.h"

UnboxingLight::UnboxingLight()
{
}

UnboxingLight::~UnboxingLight()
{
}

void UnboxingLight::BeginPlay()
{
	Super::BeginPlay();
	SetMesh("Rect");
	SetMaterial("UnboxingLight");
	SetSprite("UnboxingLight.png");
	SetOrder(100);
}

void UnboxingLight::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	if (IsOn)
	{
		PlusAlpha += 0.15f * _DeltaTime;
	}
	else
	{
		PlusAlpha -= 0.2f * _DeltaTime;
	}

	SetPlusColor(FVector(0.f,0.f,0.f,PlusAlpha));
}

