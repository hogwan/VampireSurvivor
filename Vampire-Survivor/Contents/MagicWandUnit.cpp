#include "PreCompile.h"
#include "MagicWandUnit.h"

AMagicWandUnit::AMagicWandUnit() 
{

}

AMagicWandUnit::~AMagicWandUnit() 
{
}

void AMagicWandUnit::BeginPlay()
{
	Super::BeginPlay();
	Renderer->CreateAnimation("Flying", "MagicWand", 0, 1, 0.1f, true);
	Renderer->SetAutoSize(1.f, true);
	Renderer->SetOrder(ERenderOrder::PlayerWeapon);

	Renderer->ChangeAnimation("Flying");
}

void AMagicWandUnit::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	ColLogic();
	AddActorLocation(MoveVector * _DeltaTime);
}

void AMagicWandUnit::ColLogic()
{
}

