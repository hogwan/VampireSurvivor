#include "PreCompile.h"
#include "SpawnerManager.h"
#include "Player.h"

USpawnerManager::USpawnerManager() 
{
}

USpawnerManager::~USpawnerManager() 
{
}

void USpawnerManager::BeginPlay()
{
	Super::BeginPlay();
	SpawnPointInit();
}

void USpawnerManager::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	SpawnPointReposition();
}

void USpawnerManager::SpawnPointInit()
{
	float XBot = 1280.f / 4.f;
	float YBot = 720.f / 2.f;

	FVector PlayerPos = UContentsValue::Player->GetActorLocation();
	FVector FirstPos = PlayerPos - FVector(640.f, 360.f, 0.f);
	FirstPos -= FVector(XBot, YBot, 0.f);

	for (int Y = 0; Y < 5; Y++)
	{
		for (int X = 0; X < 7; X++)
		{
			if (Y >= 1 && Y <= 3 &&
				X >= 1 && X <= 5)
			{
				continue;
			}
			std::shared_ptr<USpawner> Spawner = GetWorld()->SpawnActor<USpawner>("Spawner");
			Spawner->SetInitialPos(FirstPos + FVector(XBot * X, YBot * Y, 0.f));
			Spawners.push_back(Spawner);
		}
	}
}

void USpawnerManager::SpawnPointReposition()
{
	for (std::shared_ptr<USpawner> Spawner : Spawners)
	{
		FVector PlayerPos = UContentsValue::Player->GetActorLocation();
		FVector PlayerInitPos = UContentsValue::Player->GetInitialPos();
		FVector MoveDistance = PlayerPos - PlayerInitPos;

		FVector SpawnerInitPos = Spawner->GetInitialPos();
		FVector SpawnerPos = SpawnerInitPos + MoveDistance;
		Spawner->SetActorLocation(SpawnerPos);
	}
}