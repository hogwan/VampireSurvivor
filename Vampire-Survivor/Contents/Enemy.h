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

	void SetMass(bool _IsMass)
	{
		IsMass = _IsMass;
		Data.Hp = 1;
	}

	void SetMassDir(FVector _Dir)
	{
		_Dir.Normalize3D();
		MassDir = _Dir;
	}
	void SetTargetPos(FVector _MassTargetPos)
	{
		MassTargetPos = _MassTargetPos;
	}


protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void ActiveOn() override;
	void ActiveOff() override;

	void MoveLogic();
	void ColLogic(float _DeltaTime);
	void RepositionLogic();
	void SpriteDirCheck();

	void KnockBackStart();
	void KnockBack(float _DeltaTime);

	void ChasePlayerStart();
	void ChasePlayer(float _DeltaTime);

	void MassMoveStart();
	void MassMove(float _DeltaTime);
	void MassChangeDir();

	void DeathStart();
	void Death(float _DeltaTime);

	float KnockBackTime = 0.15f;
	float AccTime = 0.f;
	FVector KnockBackVector = FVector::Zero;
	FEnemyData Data = { 0, };

	bool IsMass = false;
	FVector MassDir = FVector::Zero;
	FVector MassTargetPos = FVector::Zero;
	float MassSpeed = 300.f;
	float MassDirChangeTime = 5.f;
private:

};



