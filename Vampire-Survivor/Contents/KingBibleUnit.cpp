#include "PreCompile.h"
#include "KingBibleUnit.h"

AKingBibleUnit::AKingBibleUnit()
{
}

AKingBibleUnit::~AKingBibleUnit()
{
}

void AKingBibleUnit::BeginPlay()
{
	Super::BeginPlay();
	Renderer->SetSprite("KingBible_0.png");
	Renderer->SetAutoSize(1.f, true);

	Collider->SetScale(FVector(30.f, 30.f, 10.f));
	Collider->SetCollisionGroup(ECollisionOrder::PlayerWeapon);
	Collider->SetCollisionType(ECollisionType::RotRect);
}

void AKingBibleUnit::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	ColLogic();
}

void AKingBibleUnit::ColLogic()
{

}
