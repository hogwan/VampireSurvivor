#pragma once
#include <EngineCore/Actor.h>
#include <EngineCore/StateManager.h>
#include "VSObject.h"


// Ό³Έν :
class USpawnerManager : public AActor
{
	GENERATED_BODY(AActor)
public:
	// constructor destructor
	USpawnerManager();
	~USpawnerManager();

	// delete Function
	USpawnerManager(const USpawnerManager& _Other) = delete;
	USpawnerManager(USpawnerManager&& _Other) noexcept = delete;
	USpawnerManager& operator=(const USpawnerManager& _Other) = delete;
	USpawnerManager& operator=(USpawnerManager&& _Other) noexcept = delete;

	static int EnemyCount;
	static float SpawnTime;
	static std::vector<EMonsterOrder> RandomList;

	UStateManager State;
protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void SpawnPointInit();
	void SpawnPointReposition();

	std::shared_ptr<class AEnemy> SpawnBoss(EMonsterOrder _BossMonsterOrder);

	void SpawnBatMass();
	void SpawnFlowerPrison();

	float MassSpawnTime = 10.f;
	float MassSpawnAcc = 0.f;
	int CurTime = 0;

	void StateInit();

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

private:
	std::vector<std::shared_ptr<class USpawner>> Spawners;
};
