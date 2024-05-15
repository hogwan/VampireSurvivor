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

struct FPlayerData
{
	int Level = 1;
	float TargetExp = 5.f;
	float CurExp = 0.f;
	float MaxHealth = 100.f;
	float Hp = 100.f;
	float Recovery = 0.f;
	float Armor = 0.f;
	float MoveSpeed = 200.f;
	float Might = 1.f;
	float Speed = 1.f;
	float Duration = 1.f;
	float Area = 1.f;
	float Cooldown = 1.f;
	float Magnet = 30.f;
	float Luck = 1.f;
	float Growth = 1.f;
	float Greed = 1.f;
	float Curse = 1.f;

	int Amount = 0;
	int Revival = 0;
	int Skip = 0;
	int Banish = 0;
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

	FPlayerData* GetPlayerDataReference()
	{
		return &Data;
	}

	FPlayerData GetPlayerDataCopy()
	{
		return Data;
	}
	FPlayerData OriginalData;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	FVector InitialPos = FVector::Zero;
	FVector DirVector = FVector::Zero;
	AActorDir ECurDir = AActorDir::None;

	UCollision* DetectCollider = nullptr;

	float DetectDistance = 600.f;

	class AEnemy* NearestEnemy = nullptr;
	class AEnemy* RandomEnemy = nullptr;
	void NearEnemyCheck();
	void RandomEnemyCheck();
	void DebugMessageFunction(float _Delta);
	void LevelUpLogic();
	void DeathLogic();
	void StatusInit();
	FPlayerData Data = { 0, };
 private:
	void MoveLogic();
	void ColLogic();
};