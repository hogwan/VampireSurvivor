#pragma once
#include "VSObject.h"
enum class AActorDir
{
	None,
	N,
	NE,
	E,
	SE,
	S,
	SW,
	W,
	NW
};

class APlayer : public AVSObject
{
	GENERATED_BODY(AVSObject)
public:
	//constructer destructer
	APlayer();
	~APlayer();

	//delete Function
	APlayer(const APlayer& _Other) = delete;
	APlayer(APlayer&& _Other) noexcept = delete;
	APlayer& operator=(const APlayer& _Other) = delete;
	APlayer& operator=(APlayer&& _Other) noexcept = delete;

	FVector GetInitialPos()
	{
		return InitialPos;
	}

	FVector GetPlayerDir()
	{
		return DirVector.Normalize3DReturn();
	}

	class AEnemy* GetNearestEnemy()
	{
		return NearestEnemy;
	}

	class AEnemy* GetRandomEnemy()
	{
		return RandomEnemy;
	}

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	FVector InitialPos = FVector::Zero;
	FVector DirVector = FVector::Zero;
	AActorDir ECurDir = AActorDir::None;

	UCollision* DetectCollider = nullptr;

	float DetectDistance = 600.f;
	float MoveSpeed = 300.f;

	class AEnemy* NearestEnemy = nullptr;
	class AEnemy* RandomEnemy = nullptr;
	void NearEnemyCheck();
	void RandomEnemyCheck();
	void DebugMessageFunction(float _Delta);
private:
	void MoveLogic();
	void ColLogic();
};