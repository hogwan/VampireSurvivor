#pragma once
#include <EngineCore/Actor.h>
#include <EngineCore/StateManager.h>

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
	

	std::shared_ptr<class AEnemy> SpawnMonster();


private:
	UDefaultSceneComponent* Root = nullptr;

	FVector InitialPos = FVector::Zero;
	FVector CurPos = FVector::Zero;

	float RemainTime = 1.f;
	float TorchSpawnCooldown = 5.f;
	float TorchSpawnAcc = 0.f;

	int MinOrder = 0;
	int MaxOrder = 0;
};

