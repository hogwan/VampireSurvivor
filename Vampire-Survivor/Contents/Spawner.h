#pragma once
#include <EngineCore/Actor.h>
#include "PollingManager.h"

// Ό³Έν :
class USpawner : public AActor
{
	GENERATED_BODY(AActor)
public:
	// constructor destructor
	USpawner();
	~USpawner();

	// delete Function
	USpawner(const USpawner& _Other) = delete;
	USpawner(USpawner&& _Other) noexcept = delete;
	USpawner& operator=(const USpawner& _Other) = delete;
	USpawner& operator=(USpawner&& _Other) noexcept = delete;

	void SetInitialPos(FVector _Pos)
	{
		InitialPos = _Pos;
	}

	FVector GetInitialPos()
	{
		return InitialPos;
	}

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	/*template<typename Enemy>
	void EnemySpawn()
	{
		std::shared_ptr<APollingObject> Monster = nullptr;

		for (std::shared_ptr<APollingObject> Object : UPollingManager::PollingObjects[Enemy::PollingOrder])
		{
			if (Object->GetIsLive())
			{
				continue;
			}
			else
			{
				Monster = Object;
				break;
			}
		}

		if (Monster == nullptr)
		{
			Monster = GetWorld()->SpawnActor<Enemy>("Monster");
			UPollingManager::PollingObjects[Enemy::PollingOrder].push_back(Monster);
		}

		Monster->SetActorLocation(CurPos);
		Monster->ActiveOn();
	}*/

private:
	UDefaultSceneComponent* Root = nullptr;

	FVector InitialPos = FVector::Zero;
	FVector CurPos = FVector::Zero;

	float SpawnTime = 5.f;
	float RemainTime = SpawnTime;
};

