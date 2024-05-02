#include "PreCompile.h"
#include "Spawner.h"
#include "Player.h"
#include "Bat1.h"
#include "Bat2.h"
#include "Bat3.h"
#include "BossBat1.h"
#include "BossBat2.h"
#include "Ghoul1.h"
#include "Ghoul2.h"
#include "Ghoul3.h"
#include "Skeleton.h"
#include "Ghost.h"
#include "Mudman1.h"
#include "Mudman2.h"
#include "Mentis.h"
#include "SpawnerManager.h"
#include <EngineBase/EngineRandom.h>

USpawner::USpawner() 
{
	Root = CreateDefaultSubObject<UDefaultSceneComponent>("Root");
	SetRoot(Root);
}

USpawner::~USpawner() 
{
}

void USpawner::BeginPlay()
{
	Super::BeginPlay();

	StateInit();
}

void USpawner::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	
	CurPos = GetActorLocation();

	RemainTime -= _DeltaTime;
	if (RemainTime < 0.f)
	{
		if (USpawnerManager::EnemyCount >= 500) return;

		RemainTime = SpawnTime;
		std::shared_ptr<AEnemy> Monster = SpawnMonster();
		Monster->SetActorLocation(CurPos);

		USpawnerManager::EnemyCount++;
	}
}

void USpawner::StateInit()
{
	{
		State.CreateState("0");
		State.CreateState("1");
		State.CreateState("2");
		State.CreateState("3");
		State.CreateState("4");
		State.CreateState("5");
		State.CreateState("6");
		State.CreateState("7");
		State.CreateState("8");
		State.CreateState("9");

		State.CreateState("10");
		State.CreateState("11");
		State.CreateState("12");
		State.CreateState("13");
		State.CreateState("14");
		State.CreateState("15");
		State.CreateState("16");
		State.CreateState("17");
		State.CreateState("18");
		State.CreateState("19");

		State.CreateState("20");
		State.CreateState("21");
		State.CreateState("22");
		State.CreateState("23");
		State.CreateState("24");
		State.CreateState("25");
		State.CreateState("26");
		State.CreateState("27");
		State.CreateState("28");
		State.CreateState("29");
	}

	{
		State.SetStartFunction("0", std::bind(&USpawner::Minute_00Start, this));
		State.SetUpdateFunction("0", std::bind(&USpawner::Minute_00, this, std::placeholders::_1));
		State.SetStartFunction("1", std::bind(&USpawner::Minute_01Start, this));
		State.SetUpdateFunction("1", std::bind(&USpawner::Minute_01, this, std::placeholders::_1));
		State.SetStartFunction("2", std::bind(&USpawner::Minute_02Start, this));
		State.SetUpdateFunction("2", std::bind(&USpawner::Minute_02, this, std::placeholders::_1));
		State.SetStartFunction("3", std::bind(&USpawner::Minute_03Start, this));
		State.SetUpdateFunction("3", std::bind(&USpawner::Minute_03, this, std::placeholders::_1));
		State.SetStartFunction("4", std::bind(&USpawner::Minute_04Start, this));
		State.SetUpdateFunction("4", std::bind(&USpawner::Minute_04, this, std::placeholders::_1));
		State.SetStartFunction("5", std::bind(&USpawner::Minute_05Start, this));
		State.SetUpdateFunction("5", std::bind(&USpawner::Minute_05, this, std::placeholders::_1));
		State.SetStartFunction("6", std::bind(&USpawner::Minute_06Start, this));
		State.SetUpdateFunction("6", std::bind(&USpawner::Minute_06, this, std::placeholders::_1));
		State.SetStartFunction("7", std::bind(&USpawner::Minute_07Start, this));
		State.SetUpdateFunction("7", std::bind(&USpawner::Minute_07, this, std::placeholders::_1));
		State.SetStartFunction("8", std::bind(&USpawner::Minute_08Start, this));
		State.SetUpdateFunction("8", std::bind(&USpawner::Minute_08, this, std::placeholders::_1));
		State.SetStartFunction("9", std::bind(&USpawner::Minute_09Start, this));
		State.SetUpdateFunction("9", std::bind(&USpawner::Minute_09, this, std::placeholders::_1));

		State.SetStartFunction("10", std::bind(&USpawner::Minute_10Start, this));
		State.SetUpdateFunction("10", std::bind(&USpawner::Minute_10, this, std::placeholders::_1));
		State.SetStartFunction("11", std::bind(&USpawner::Minute_11Start, this));
		State.SetUpdateFunction("11", std::bind(&USpawner::Minute_11, this, std::placeholders::_1));
		State.SetStartFunction("12", std::bind(&USpawner::Minute_12Start, this));
		State.SetUpdateFunction("12", std::bind(&USpawner::Minute_12, this, std::placeholders::_1));
		State.SetStartFunction("13", std::bind(&USpawner::Minute_13Start, this));
		State.SetUpdateFunction("13", std::bind(&USpawner::Minute_13, this, std::placeholders::_1));
		State.SetStartFunction("14", std::bind(&USpawner::Minute_14Start, this));
		State.SetUpdateFunction("14", std::bind(&USpawner::Minute_14, this, std::placeholders::_1));
		State.SetStartFunction("15", std::bind(&USpawner::Minute_15Start, this));
		State.SetUpdateFunction("15", std::bind(&USpawner::Minute_15, this, std::placeholders::_1));
		State.SetStartFunction("16", std::bind(&USpawner::Minute_16Start, this));
		State.SetUpdateFunction("16", std::bind(&USpawner::Minute_16, this, std::placeholders::_1));
		State.SetStartFunction("17", std::bind(&USpawner::Minute_17Start, this));
		State.SetUpdateFunction("17", std::bind(&USpawner::Minute_17, this, std::placeholders::_1));
		State.SetStartFunction("18", std::bind(&USpawner::Minute_18Start, this));
		State.SetUpdateFunction("18", std::bind(&USpawner::Minute_18, this, std::placeholders::_1));
		State.SetStartFunction("19", std::bind(&USpawner::Minute_19Start, this));
		State.SetUpdateFunction("19", std::bind(&USpawner::Minute_19, this, std::placeholders::_1));

		State.SetStartFunction("20", std::bind(&USpawner::Minute_20Start, this));
		State.SetUpdateFunction("20", std::bind(&USpawner::Minute_20, this, std::placeholders::_1));
		State.SetStartFunction("21", std::bind(&USpawner::Minute_21Start, this));
		State.SetUpdateFunction("21", std::bind(&USpawner::Minute_21, this, std::placeholders::_1));
		State.SetStartFunction("22", std::bind(&USpawner::Minute_22Start, this));
		State.SetUpdateFunction("22", std::bind(&USpawner::Minute_22, this, std::placeholders::_1));
		State.SetStartFunction("23", std::bind(&USpawner::Minute_23Start, this));
		State.SetUpdateFunction("23", std::bind(&USpawner::Minute_23, this, std::placeholders::_1));
		State.SetStartFunction("24", std::bind(&USpawner::Minute_24Start, this));
		State.SetUpdateFunction("24", std::bind(&USpawner::Minute_24, this, std::placeholders::_1));
		State.SetStartFunction("25", std::bind(&USpawner::Minute_25Start, this));
		State.SetUpdateFunction("25", std::bind(&USpawner::Minute_25, this, std::placeholders::_1));
		State.SetStartFunction("26", std::bind(&USpawner::Minute_26Start, this));
		State.SetUpdateFunction("26", std::bind(&USpawner::Minute_26, this, std::placeholders::_1));
		State.SetStartFunction("27", std::bind(&USpawner::Minute_27Start, this));
		State.SetUpdateFunction("27", std::bind(&USpawner::Minute_27, this, std::placeholders::_1));
		State.SetStartFunction("28", std::bind(&USpawner::Minute_28Start, this));
		State.SetUpdateFunction("28", std::bind(&USpawner::Minute_28, this, std::placeholders::_1));
		State.SetStartFunction("29", std::bind(&USpawner::Minute_29Start, this));
		State.SetUpdateFunction("29", std::bind(&USpawner::Minute_29, this, std::placeholders::_1));
	}

	State.ChangeState("0");
}


std::shared_ptr<AEnemy> USpawner::SpawnMonster()
{
	std::shared_ptr<AEnemy> Monster = nullptr;

	int Random = UEngineRandom::MainRandom.RandomInt(0, static_cast<int>(RandomList.size()-1));

	EMonsterOrder RandomOrder = RandomList[Random];
	switch (RandomOrder)
	{
	case EMonsterOrder::Bat1:
		Monster = GetWorld()->SpawnActor<ABat1>("Bat1");
		break;
	case EMonsterOrder::Bat2:
		Monster = GetWorld()->SpawnActor<ABat2>("Bat2");
		break;
	case EMonsterOrder::Bat3:
		Monster = GetWorld()->SpawnActor<ABat3>("Bat3");
		break;
	case EMonsterOrder::BossBat1:
		Monster = GetWorld()->SpawnActor<ABossBat1>("BossBat1");
		break;
	case EMonsterOrder::BossBat2:
		Monster = GetWorld()->SpawnActor<ABossBat2>("BossBat2");
		break;
	case EMonsterOrder::Ghoul1:
		Monster = GetWorld()->SpawnActor<AGhoul1>("AGhoul1");
		break;
	case EMonsterOrder::Ghoul2:
		Monster = GetWorld()->SpawnActor<AGhoul2>("AGhoul2");
		break;
	case EMonsterOrder::Ghoul3:
		Monster = GetWorld()->SpawnActor<AGhoul3>("AGhoul3");
		break;
	case EMonsterOrder::Skeleton:
		Monster = GetWorld()->SpawnActor<ASkeleton>("ASkeleton");
		break;
	case EMonsterOrder::Ghost:
		Monster = GetWorld()->SpawnActor<AGhost>("AGhost");
		break;
	case EMonsterOrder::Mudman1:
		Monster = GetWorld()->SpawnActor<AMudman1>("AMudman1");
		break;
	case EMonsterOrder::Mudman2:
		Monster = GetWorld()->SpawnActor<AMudman2>("AMudman2");
		break;
	case EMonsterOrder::Mentis:
		Monster = GetWorld()->SpawnActor<AMentis>("AMudman2");
		break;
	default:
		break;
	}

	return Monster;
}

void USpawner::Minute_00(float _DeltaTime)
{
}

void USpawner::Minute_01(float _DeltaTime)
{
}

void USpawner::Minute_02(float _DeltaTime)
{
}

void USpawner::Minute_03(float _DeltaTime)
{
}

void USpawner::Minute_04(float _DeltaTime)
{
}

void USpawner::Minute_05(float _DeltaTime)
{
}

void USpawner::Minute_06(float _DeltaTime)
{
}

void USpawner::Minute_07(float _DeltaTime)
{
}

void USpawner::Minute_08(float _DeltaTime)
{
}

void USpawner::Minute_09(float _DeltaTime)
{
}

void USpawner::Minute_10(float _DeltaTime)
{
}

void USpawner::Minute_11(float _DeltaTime)
{
}

void USpawner::Minute_12(float _DeltaTime)
{
}

void USpawner::Minute_13(float _DeltaTime)
{
}

void USpawner::Minute_14(float _DeltaTime)
{
}

void USpawner::Minute_15(float _DeltaTime)
{
}

void USpawner::Minute_16(float _DeltaTime)
{
}

void USpawner::Minute_17(float _DeltaTime)
{
}

void USpawner::Minute_18(float _DeltaTime)
{
}

void USpawner::Minute_19(float _DeltaTime)
{
}

void USpawner::Minute_20(float _DeltaTime)
{
}

void USpawner::Minute_21(float _DeltaTime)
{
}

void USpawner::Minute_22(float _DeltaTime)
{
}

void USpawner::Minute_23(float _DeltaTime)
{
}

void USpawner::Minute_24(float _DeltaTime)
{
}

void USpawner::Minute_25(float _DeltaTime)
{
}

void USpawner::Minute_26(float _DeltaTime)
{
}

void USpawner::Minute_27(float _DeltaTime)
{
}

void USpawner::Minute_28(float _DeltaTime)
{
}

void USpawner::Minute_29(float _DeltaTime)
{
}

void USpawner::Minute_00Start()
{
	RandomList.clear();
	RandomList.push_back(EMonsterOrder::Bat1);
	RandomList.push_back(EMonsterOrder::Bat2);
	RandomList.push_back(EMonsterOrder::Bat3);

	SpawnTime = 5.f;
}

void USpawner::Minute_01Start()
{
	RandomList.clear();

	RandomList.push_back(EMonsterOrder::Bat1);
	RandomList.push_back(EMonsterOrder::Bat2);
	RandomList.push_back(EMonsterOrder::Bat3);
	RandomList.push_back(EMonsterOrder::Ghoul1);
	RandomList.push_back(EMonsterOrder::Ghoul2);
	RandomList.push_back(EMonsterOrder::Ghoul3);

	SpawnTime = 5.f;
}

void USpawner::Minute_02Start()
{
	RandomList.clear();

	RandomList.push_back(EMonsterOrder::Bat1);
	RandomList.push_back(EMonsterOrder::Bat2);
	RandomList.push_back(EMonsterOrder::Bat3);
	RandomList.push_back(EMonsterOrder::Ghoul1);
	RandomList.push_back(EMonsterOrder::Ghoul2);
	RandomList.push_back(EMonsterOrder::Ghoul3);

	SpawnTime = 5.f;
}

void USpawner::Minute_03Start()
{
	RandomList.clear();

	RandomList.push_back(EMonsterOrder::Skeleton);

	SpawnTime = 5.f;
}

void USpawner::Minute_04Start()
{
	RandomList.clear();

	RandomList.push_back(EMonsterOrder::Ghost);
	RandomList.push_back(EMonsterOrder::Skeleton);
	RandomList.push_back(EMonsterOrder::Bat1);
	RandomList.push_back(EMonsterOrder::Bat2);
	RandomList.push_back(EMonsterOrder::Bat3);

	SpawnTime = 5.f;
}

void USpawner::Minute_05Start()
{
	RandomList.clear();

	RandomList.push_back(EMonsterOrder::Mudman2);

	SpawnTime = 5.f;
}

void USpawner::Minute_06Start()
{
	RandomList.clear();
	RandomList.push_back(EMonsterOrder::Mudman2);
	RandomList.push_back(EMonsterOrder::Ghoul1);
	RandomList.push_back(EMonsterOrder::Ghoul2);
	RandomList.push_back(EMonsterOrder::Ghoul3);

	SpawnTime = 5.f;
}

void USpawner::Minute_07Start()
{
	RandomList.clear();
	RandomList.push_back(EMonsterOrder::Bat1);
	RandomList.push_back(EMonsterOrder::Bat2);
	RandomList.push_back(EMonsterOrder::Bat3);
	RandomList.push_back(EMonsterOrder::Mudman1);

	SpawnTime = 5.f;
}

void USpawner::Minute_08Start()
{
	RandomList.clear();
	RandomList.push_back(EMonsterOrder::Ghoul1);
	RandomList.push_back(EMonsterOrder::Ghoul2);
	RandomList.push_back(EMonsterOrder::Ghoul3);
	RandomList.push_back(EMonsterOrder::Bat1);
	RandomList.push_back(EMonsterOrder::Bat2);
	RandomList.push_back(EMonsterOrder::Bat3);

	SpawnTime = 5.f;
}

void USpawner::Minute_09Start()
{
	RandomList.clear();
	RandomList.push_back(EMonsterOrder::Ghoul1);
	RandomList.push_back(EMonsterOrder::Ghoul2);
	RandomList.push_back(EMonsterOrder::Ghoul3);
	RandomList.push_back(EMonsterOrder::Bat1);
	RandomList.push_back(EMonsterOrder::Bat2);
	RandomList.push_back(EMonsterOrder::Bat3);


	SpawnTime = 5.f;
}

void USpawner::Minute_10Start()
{
}

void USpawner::Minute_11Start()
{
}

void USpawner::Minute_12Start()
{
}

void USpawner::Minute_13Start()
{
}

void USpawner::Minute_14Start()
{
}

void USpawner::Minute_15Start()
{
}

void USpawner::Minute_16Start()
{
}

void USpawner::Minute_17Start()
{
}

void USpawner::Minute_18Start()
{
}

void USpawner::Minute_19Start()
{
}

void USpawner::Minute_20Start()
{
}

void USpawner::Minute_21Start()
{
}

void USpawner::Minute_22Start()
{
}

void USpawner::Minute_23Start()
{
}

void USpawner::Minute_24Start()
{
}

void USpawner::Minute_25Start()
{
}

void USpawner::Minute_26Start()
{
}

void USpawner::Minute_27Start()
{
}

void USpawner::Minute_28Start()
{
}

void USpawner::Minute_29Start()
{
}

