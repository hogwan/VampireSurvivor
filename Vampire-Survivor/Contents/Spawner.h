#pragma once
#include <EngineCore/Actor.h>

class SpawnPointDesc
{
public:
	FVector InitialPos = FVector::Zero;
	FVector CurPos = FVector::Zero;
};

// Ό³Έν :
class Spawner : public AActor
{
	GENERATED_BODY(AActor)
public:
	// constructor destructor
	Spawner();
	~Spawner();

	// delete Function
	Spawner(const Spawner& _Other) = delete;
	Spawner(Spawner&& _Other) noexcept = delete;
	Spawner& operator=(const Spawner& _Other) = delete;
	Spawner& operator=(Spawner&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void SpawnPointInit();
	void SpawnPointReposition();
private:
	std::vector<SpawnPointDesc> SpawnPoint;

};

