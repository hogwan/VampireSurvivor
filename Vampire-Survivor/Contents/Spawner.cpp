#include "PreCompile.h"
#include "Spawner.h"
#include "Player.h"
#include "Bat1.h"
#include "SpawnerManager.h"

USpawner::USpawner() 
{
	Root = CreateDefaultSubObject<UDefaultSceneComponent>("Root");
	SetRoot(Root);
}

USpawner::~USpawner() 
{
}

void USpawner::BeginPlay()
{
	Super::BeginPlay();
}

void USpawner::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	
	CurPos = GetActorLocation();

	int a = 0;

	RemainTime -= _DeltaTime;
	if (RemainTime < 0.f)
	{
		if (USpawnerManager::EnemyCount >= 500) return;

		RemainTime = SpawnTime;
		//EnemySpawn<ABat1>();
		std::shared_ptr<ABat1> Bat = GetWorld()->SpawnActor<ABat1>("Bat1");
		Bat->SetActorLocation(CurPos);

		USpawnerManager::EnemyCount++;
	}
}

