#pragma once
#include "PollingObject.h"

class EnemyData
{
public:
	float Hp;
	float MaxHp;
	float Speed;
	float Power;
	float Knockback;
	float MaxKnockBack;
	float XP;
};
// Ό³Έν :
class AEnemy : public APollingObject
{
	GENERATED_BODY(APollingObject)
public:
	// constructor destructor
	AEnemy();
	~AEnemy();

	// delete Function
	AEnemy(const AEnemy& _Other) = delete;
	AEnemy(AEnemy&& _Other) noexcept = delete;
	AEnemy& operator=(const AEnemy& _Other) = delete;
	AEnemy& operator=(AEnemy&& _Other) noexcept = delete;

	EnemyData GetEnemyData()
	{
		return Data;
	}

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void MoveLogic();
	void ColLogic();
	void DeathLogic();
	void RepositionLogic();
	void SpriteDirCheck();

	EnemyData Data = { 0, };
private:
};



