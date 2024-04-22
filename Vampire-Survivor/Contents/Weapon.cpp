#include "PreCompile.h"
#include "Weapon.h"
#include "Player.h"

UWeaponCenter::UWeaponCenter()
{
	Root = CreateDefaultSubObject<UDefaultSceneComponent>("Root");

	SetRoot(Root);
}

UWeaponCenter::~UWeaponCenter()
{
}

void UWeaponCenter::BeginPlay()
{
	Super::BeginPlay();
}

void UWeaponCenter::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	FVector CenterPos = UContentsValue::Player->GetActorLocation();
	SetActorLocation(CenterPos);
}
