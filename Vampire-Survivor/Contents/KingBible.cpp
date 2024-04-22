#include "PreCompile.h"
#include "KingBible.h"

AKingBible::AKingBible()
{
}

AKingBible::~AKingBible()
{
}

void AKingBible::BeginPlay()
{
	Super::BeginPlay();
}

void AKingBible::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	ColLogic();
}

void AKingBible::ColLogic()
{

}
