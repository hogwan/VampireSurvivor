#include "PreCompile.h"
#include "LightingRingUnit.h"
#include "LightingRing.h"
#include "LightingRingCenter.h"
#include "ThunderShock.h"

ALightingRingUnit::ALightingRingUnit()
{
}

ALightingRingUnit::~ALightingRingUnit()
{
}

void ALightingRingUnit::BeginPlay()
{
	Super::BeginPlay();
	Renderer->SetSprite("LightingRing_1.png");
	Renderer->SetAutoSize(2.f, true);
	Renderer->SetOrder(ERenderOrder::PlayerWeapon);

	Renderer->SetPosition(FVector::Up * (Renderer->GetLocalScale().Y / 2.f));
	Collider->SetActive(false);
}

void ALightingRingUnit::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	if (!IsSpawn)
	{
		SpawnThunderShock();
		IsSpawn = true;
	}

	LiveTime -= _DeltaTime;
	if (LiveTime < 0.f)
	{
		Destroy();
	}

}

void ALightingRingUnit::SpawnThunderShock()
{
	std::shared_ptr<AThunderShock> Shock = GetWorld()->SpawnActor<AThunderShock>("ThunderShock");
	Shock->SetActorLocation(GetActorLocation());

}
