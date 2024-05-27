#include "PreCompile.h"
#include "FireWandCenter.h"
#include "FireWand.h"
#include "FireWandUnit.h"
#include "Player.h"
#include "Enemy.h"

AFireWandCenter::AFireWandCenter()
{
}

AFireWandCenter::~AFireWandCenter()
{
}

void AFireWandCenter::BeginPlay()
{
	Super::BeginPlay();
	SetData(UFireWand::Data);
}

void AFireWandCenter::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	UnitSpawnLogic();
}

void AFireWandCenter::UnitSpawnLogic()
{
	AEnemy* RandomTarget = UContentsValue::Player->GetRandomEnemy();
	if (RandomTarget == nullptr)
	{
		Destroy();
		return;
	}

	UEngineSound::SoundPlay("Fire.wav");
	FVector DirVector = RandomTarget->GetActorLocation() - GetActorLocation();
	DirVector.Normalize3D();

	float RotationDeg = -((Data.Amount * 10.f) / 2.f);
	for (int i = 0; i < Data.Amount; i++)
	{
		FVector Dir = DirVector;
		Dir.RotationZToDeg(RotationDeg + 10*i);

		std::shared_ptr< AFireWandUnit> FireWandUnit = GetWorld()->SpawnActor<AFireWandUnit>("FireWandUnit");
		FireWandUnit->SetMoveVector(Dir * Data.Speed);
		FireWandUnit->SetActorLocation(GetActorLocation());
	}

	Destroy();
}
