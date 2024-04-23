#include "PreCompile.h"
#include "MagicWandCenter.h"
#include "MagicWandUnit.h"
#include "Enemy.h"
#include "DetectManager.h"

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
		RemainTime = ShootTerm;
		ShootLogic();
	}

}

AEnemy* AMagicWandCenter::DetectNearest()
{
	int Min = INT_MAX;
	AEnemy* TempEnemy = nullptr;
	for (AEnemy* Enemy : UDetectManager::AllDetectedEnemy)
	{
		FVector EnemyPos = Enemy->GetActorLocation();
		FVector PlayerPos =GetActorLocation();
		EnemyPos.Z = 0.f;
		PlayerPos.Z = 0.f;

		TempEnemy = Enemy;
		int ret = (EnemyPos - PlayerPos).Size3D();

		Min = min(ret, Min);
	}

	return Min == INT_MAX ? nullptr : TempEnemy;
}

void AMagicWandCenter::ShootLogic()
{
	Target = DetectNearest();
	if (Target == nullptr) return;
	FVector DirVector = Target->GetActorLocation() - GetActorLocation();
	DirVector.Z = 0.f;
	DirVector.Normalize3D();

	std::shared_ptr<AMagicWandUnit> Projectile = GetWorld()->SpawnActor<AMagicWandUnit>("Projectile");
	Projectile->SetMoveVector(DirVector * Data.Speed);

	++ShootCount;
}

