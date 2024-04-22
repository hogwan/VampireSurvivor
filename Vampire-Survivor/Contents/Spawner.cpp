#include "PreCompile.h"
#include "Spawner.h"
#include "Player.h"
#include "Bat1.h"

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
		RemainTime = SpawnTime;
		EnemySpawn<ABat1>();
	}
}

