#include "PreCompile.h"
#include "MagicWandCenter.h"
#include "MagicWandUnit.h"
#include "Enemy.h"

AMagicWandCenter::AMagicWandCenter() 
{
}

AMagicWandCenter::~AMagicWandCenter() 
{
}

void AMagicWandCenter::BeginPlay()
{
	Super::BeginPlay();
	RemainTime = ShootTerm;
}

void AMagicWandCenter::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	if (ShootCount == Data.Amount)
	{
		Destroy();
	}

	RemainTime -= _DeltaTime;
	if (RemainTime < 0.f)
	{
		ShootLogic();
	}

}

AEnemy* AMagicWandCenter::DetectNearest()
{

	return nullptr;
}

void AMagicWandCenter::ShootLogic()
{
	Target = DetectNearest();
	FVector DirVector = Target->GetActorLocation() - GetActorLocation();
	DirVector.Z = 0.f;
	DirVector.Normalize3D();

	std::shared_ptr<AMagicWandUnit> Projectile = GetWorld()->SpawnActor<AMagicWandUnit>("Projectile");
	Projectile->SetMoveVector(DirVector * Data.Speed);

	++ShootCount;
}

