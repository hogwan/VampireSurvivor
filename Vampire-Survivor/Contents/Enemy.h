#pragma once
#include "VSObject.h"

class EnemySpawnData
{
public:
	float Speed;
	float SpawnTime;
	float MaxHp;
	float Hp;
};

// Ό³Έν :
class AEnemy : public AVSObject
{
	GENERATED_BODY(AVSObject)
public:
	// constructor destructor
	AEnemy();
	~AEnemy();

	// delete Function
	AEnemy(const AEnemy& _Other) = delete;
	AEnemy(AEnemy&& _Other) noexcept = delete;
	AEnemy& operator=(const AEnemy& _Other) = delete;
	AEnemy& operator=(AEnemy&& _Other) noexcept = delete;

	void PushData(EnemySpawnData _Data)
	{
		Data = _Data;
	}

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	EnemySpawnData Data;
};



