#include "PreCompile.h"
#include "Spawner.h"
#include "Player.h"
#include "Bat1.h"
#include "Bat2.h"
#include "Bat3.h"
#include "BossBat1.h"
#include "BossBat2.h"
#include "Ghoul1.h"
#include "Ghoul2.h"
#include "Ghoul3.h"
#include "Skeleton.h"
#include "Ghost.h"
#include "Mudman1.h"
#include "Mudman2.h"
#include "Mentis.h"
#include "SpawnerManager.h"
#include <EngineBase/EngineRandom.h>

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

	RemainTime -= _DeltaTime;
	if (RemainTime < 0.f)
	{
		if (USpawnerManager::EnemyCount >= 500) return;

		RemainTime = SpawnTime;
		std::shared_ptr<AEnemy> Monster = SpawnMonster();
		Monster->SetActorLocation(CurPos);

		USpawnerManager::EnemyCount++;
	}
}

std::shared_ptr<AEnemy> USpawner::SpawnMonster()
{
	std::shared_ptr<AEnemy> Monster = nullptr;

	MinOrder = static_cast<int>(EMonsterOrder::Bat1);
	MaxOrder = static_cast<int>(EMonsterOrder::Mentis);

	int Random = UEngineRandom::MainRandom.RandomInt(MinOrder, MaxOrder);

	EMonsterOrder RandomOrder = static_cast<EMonsterOrder>(Random);
	switch (RandomOrder)
	{
	case EMonsterOrder::Bat1:
		Monster = GetWorld()->SpawnActor<ABat1>("Bat1");
		break;
	case EMonsterOrder::Bat2:
		Monster = GetWorld()->SpawnActor<ABat2>("Bat2");
		break;
	case EMonsterOrder::Bat3:
		Monster = GetWorld()->SpawnActor<ABat3>("Bat3");
		break;
	case EMonsterOrder::BossBat1:
		Monster = GetWorld()->SpawnActor<ABossBat1>("BossBat1");
		break;
	case EMonsterOrder::BossBat2:
		Monster = GetWorld()->SpawnActor<ABossBat2>("BossBat2");
		break;
	case EMonsterOrder::Ghoul1:
		Monster = GetWorld()->SpawnActor<AGhoul1>("AGhoul1");
		break;
	case EMonsterOrder::Ghoul2:
		Monster = GetWorld()->SpawnActor<AGhoul2>("AGhoul2");
		break;
	case EMonsterOrder::Ghoul3:
		Monster = GetWorld()->SpawnActor<AGhoul3>("AGhoul3");
		break;
	case EMonsterOrder::Skeleton:
		Monster = GetWorld()->SpawnActor<ASkeleton>("ASkeleton");
		break;
	case EMonsterOrder::Ghost:
		Monster = GetWorld()->SpawnActor<AGhost>("AGhost");
		break;
	case EMonsterOrder::Mudman1:
		Monster = GetWorld()->SpawnActor<AMudman1>("AMudman1");
		break;
	case EMonsterOrder::Mudman2:
		Monster = GetWorld()->SpawnActor<AMudman2>("AMudman2");
		break;
	case EMonsterOrder::Mentis:
		Monster = GetWorld()->SpawnActor<AMentis>("AMudman2");
		break;
	default:
		break;
	}

	return Monster;
}

