#pragma once
#include <EngineCore/Actor.h>
#include "PollingManager.h"
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

	UStateManager State;
	std::vector<EMonsterOrder> RandomList;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
	void StateInit();

	std::shared_ptr<class AEnemy> SpawnMonster();

	void Minute_00(float _DeltaTime);
	void Minute_01(float _DeltaTime);
	void Minute_02(float _DeltaTime);
	void Minute_03(float _DeltaTime);
	void Minute_04(float _DeltaTime);
	void Minute_05(float _DeltaTime);
	void Minute_06(float _DeltaTime);
	void Minute_07(float _DeltaTime);
	void Minute_08(float _DeltaTime);
	void Minute_09(float _DeltaTime);

	void Minute_10(float _DeltaTime);
	void Minute_11(float _DeltaTime);
	void Minute_12(float _DeltaTime);
	void Minute_13(float _DeltaTime);
	void Minute_14(float _DeltaTime);
	void Minute_15(float _DeltaTime);
	void Minute_16(float _DeltaTime);
	void Minute_17(float _DeltaTime);
	void Minute_18(float _DeltaTime);
	void Minute_19(float _DeltaTime);

	void Minute_20(float _DeltaTime);
	void Minute_21(float _DeltaTime);
	void Minute_22(float _DeltaTime);
	void Minute_23(float _DeltaTime);
	void Minute_24(float _DeltaTime);
	void Minute_25(float _DeltaTime);
	void Minute_26(float _DeltaTime);
	void Minute_27(float _DeltaTime);
	void Minute_28(float _DeltaTime);
	void Minute_29(float _DeltaTime);

	void Minute_00Start();
	void Minute_01Start();
	void Minute_02Start();
	void Minute_03Start();
	void Minute_04Start();
	void Minute_05Start();
	void Minute_06Start();
	void Minute_07Start();
	void Minute_08Start();
	void Minute_09Start();
	void Minute_10Start();
	void Minute_11Start();
	void Minute_12Start();
	void Minute_13Start();
	void Minute_14Start();
	void Minute_15Start();
	void Minute_16Start();
	void Minute_17Start();
	void Minute_18Start();
	void Minute_19Start();
	void Minute_20Start();
	void Minute_21Start();
	void Minute_22Start();
	void Minute_23Start();
	void Minute_24Start();
	void Minute_25Start();
	void Minute_26Start();
	void Minute_27Start();
	void Minute_28Start();
	void Minute_29Start();


	/*template<typename Enemy>
	void EnemySpawn()
	{
		std::shared_ptr<APollingObject> Monster = nullptr;

		for (std::shared_ptr<APollingObject> Object : UPollingManager::PollingObjects[Enemy::PollingOrder])
		{
			if (Object->GetIsLive())
			{
				continue;
			}
			else
			{
				Monster = Object;
				break;
			}
		}

		if (Monster == nullptr)
		{
			Monster = GetWorld()->SpawnActor<Enemy>("Monster");
			UPollingManager::PollingObjects[Enemy::PollingOrder].push_back(Monster);
		}

		Monster->SetActorLocation(CurPos);
		Monster->ActiveOn();
	}*/

private:
	UDefaultSceneComponent* Root = nullptr;

	FVector InitialPos = FVector::Zero;
	FVector CurPos = FVector::Zero;

	float SpawnTime = 5.f;
	float RemainTime = SpawnTime;

	int MinOrder = 0;
	int MaxOrder = 0;
};

