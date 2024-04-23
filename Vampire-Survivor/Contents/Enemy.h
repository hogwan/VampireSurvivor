#pragma once
#include "PollingObject.h"

struct FEnemyData
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

	FEnemyData GetEnemyData()
	{
		return Data;
	}

	bool InDetectRange = false;
protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void ActiveOn() override;
	void ActiveOff() override;

	void MoveLogic();
	void ColLogic();
	void DeathLogic();
	void RepositionLogic();
	void SpriteDirCheck();
	void DetectLogic();

	FEnemyData Data = { 0, };
private:
};



