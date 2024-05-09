#include "PreCompile.h"
#include "FireCenter.h"
#include "FireUnit.h"
#include "Player.h"

FireCenter::FireCenter()
{
	Root = CreateDefaultSubObject<UDefaultSceneComponent>("Root");
	SetRoot(Root);
}

FireCenter::~FireCenter()
{
}

void FireCenter::BeginPlay()
{
	Super::BeginPlay();

	DelayCallBack(10.f, [=]
		{
			Destroy();
		});
}

void FireCenter::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	SetActorLocation(UContentsValue::Player->GetActorLocation());

	ShootAcc += _DeltaTime;
	if (ShootAcc > ShootCooldown)
	{
		ShootAcc = 0.f;
		ShootFire();
	}
}

void FireCenter::ShootFire()
{
	DirVector = UContentsValue::Player->GetPlayerDir();
	std::shared_ptr<FireUnit> FUnit = GetWorld()->SpawnActor<FireUnit>("FireUnit");
	FUnit->SetActorLocation(GetActorLocation());
	FUnit->SetDir(DirVector);
}
