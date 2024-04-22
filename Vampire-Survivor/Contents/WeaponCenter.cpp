#include "PreCompile.h"
#include "WeaponCenter.h"
#include "Player.h"

AWeaponCenter::AWeaponCenter()
{
	Root = CreateDefaultSubObject<UDefaultSceneComponent>("Root");

	SetRoot(Root);
}

AWeaponCenter::~AWeaponCenter()
{
}

void AWeaponCenter::BeginPlay()
{
	Super::BeginPlay();
}

void AWeaponCenter::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	FVector CenterPos = UContentsValue::Player->GetActorLocation();
	SetActorLocation(CenterPos);
}
