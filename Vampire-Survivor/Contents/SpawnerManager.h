#pragma once
#include <EngineCore/Actor.h>
#include "Spawner.h"
#include "VSObject.h"

// Ό³Έν :
class USpawnerManager : public AActor
{
	GENERATED_BODY(AActor)
public:
	// constructor destructor
	USpawnerManager();
	~USpawnerManager();

	// delete Function
	USpawnerManager(const USpawnerManager& _Other) = delete;
	USpawnerManager(USpawnerManager&& _Other) noexcept = delete;
	USpawnerManager& operator=(const USpawnerManager& _Other) = delete;
	USpawnerManager& operator=(USpawnerManager&& _Other) noexcept = delete;

	static int EnemyCount;
protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void SpawnPointInit();
	void SpawnPointReposition();

private:
	std::vector<std::shared_ptr<USpawner>> Spawners;
};
