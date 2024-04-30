#pragma once
#include "PollingObject.h"
#include <EngineCore/TextWidget.h>
#include <EngineCore/StateManager.h>

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

	FEnemyData& GetEnemyData()
	{
		return Data;
	}

	UStateManager State;

	void SetKnockBack(FVector _KnockBackVector)
	{
		KnockBackVector = _KnockBackVector * Data.Knockback;
	}

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void ActiveOn() override;
	void ActiveOff() override;

	void MoveLogic();
	void ColLogic(float _DeltaTime);
	void DeathLogic();
	void RepositionLogic();
	void SpriteDirCheck();

	void KnockBackStart();
	void KnockBack(float _DeltaTime);

	void ChasePlayerStart();
	void ChasePlayer(float _DeltaTime);

	float KnockBackTime = 0.15f;
	float AccTime = 0.f;
	FVector KnockBackVector = FVector::Zero;
	FEnemyData Data = { 0, };
private:

};



