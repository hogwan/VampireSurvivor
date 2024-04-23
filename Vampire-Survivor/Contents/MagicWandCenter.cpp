#include "PreCompile.h"
#include "MagicWandCenter.h"
#include "MagicWandUnit.h"
#include "Enemy.h"
#include "MagicWand.h"
#include "Player.h"

AMagicWandCenter::AMagicWandCenter() 
{
}

AMagicWandCenter::~AMagicWandCenter() 
{
}

void AMagicWandCenter::BeginPlay()
{
	Super::BeginPlay();
	SetData(UMagicWand::Data);
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
		RemainTime = ShootTerm;
		ShootLogic();
	}

}

void AMagicWandCenter::ShootLogic()
{
	Target = UContentsValue::Player->GetNearestEnemy();
	if (Target == nullptr)
	{
		++ShootCount;
		return;
	}
	FVector DirVector = Target->GetActorLocation() - GetActorLocation();
	DirVector.Z = 0.f;
	DirVector.Normalize3D();

	std::shared_ptr<AMagicWandUnit> Projectile = GetWorld()->SpawnActor<AMagicWandUnit>("Projectile");
	Projectile->SetActorLocation(GetActorLocation());
	Projectile->SetMoveVector(DirVector * Data.Speed);

	if (DirVector.X >= 0)
	{
		Projectile->SetActorRotation(FVector(0.f, 0.f, DirVector.Y * 90.f));
	}
	else
	{
		Projectile->SetActorRotation(FVector(0.f, 0.f, 180 - (DirVector.Y * 90.f)));
	}

	++ShootCount;
}

