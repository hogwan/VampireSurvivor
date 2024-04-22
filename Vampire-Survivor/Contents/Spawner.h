#pragma once
#include <EngineCore/Actor.h>

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

private:
	FVector InitialPos = FVector::Zero;
	FVector CurPos = FVector::Zero;

};

