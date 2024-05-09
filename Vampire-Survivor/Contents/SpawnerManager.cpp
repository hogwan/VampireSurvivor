#include "PreCompile.h"
#include "SpawnerManager.h"
#include "Player.h"
#include "Spawner.h"
#include "Mentis.h"
#include "BossBat1.h"
#include "BossBat2.h"
#include "Flower.h"
#include "XLFlower.h"
#include "XLMummy.h"
#include "Bat1.h"
#include "Bat2.h"
#include "Bat3.h"
#include <EngineBase/EngineRandom.h>

int USpawnerManager::EnemyCount=0;
float USpawnerManager::SpawnTime = 5.f;
std::vector<EMonsterOrder> USpawnerManager::RandomList;

USpawnerManager::USpawnerManager() 
{
}

USpawnerManager::~USpawnerManager() 
{
}

void USpawnerManager::BeginPlay()
{
	Super::BeginPlay();
	SpawnPointInit();
	StateInit();
}

void USpawnerManager::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	CurTime = static_cast<int>(UContentsValue::Time / 60.f);
	SpawnPointReposition();
	State.Update(_DeltaTime);
}

void USpawnerManager::SpawnPointInit()
{
	float XBot = 1280.f / 4.f;
	float YBot = 720.f / 2.f;

	FVector PlayerPos = UContentsValue::Player->GetActorLocation();
	FVector FirstPos = PlayerPos - FVector(640.f, 360.f, 0.f);
	FirstPos -= FVector(XBot, YBot, 0.f);

	for (int Y = 0; Y < 5; Y++)
	{
		for (int X = 0; X < 7; X++)
		{
			if (Y >= 1 && Y <= 3 &&
				X >= 1 && X <= 5)
			{
				continue;
			}
			std::shared_ptr<USpawner> Spawner = GetWorld()->SpawnActor<USpawner>("Spawner");
			Spawner->SetInitialPos(FirstPos + FVector(XBot * X, YBot * Y, 0.f));
			Spawners.push_back(Spawner);
		}
	}
}

void USpawnerManager::SpawnPointReposition()
{
	for (std::shared_ptr<USpawner> Spawner : Spawners)
	{
		FVector PlayerPos = UContentsValue::Player->GetActorLocation();
		FVector PlayerInitPos = UContentsValue::Player->GetInitialPos();
		FVector MoveDistance = PlayerPos - PlayerInitPos;

		FVector SpawnerInitPos = Spawner->GetInitialPos();
		FVector SpawnerPos = SpawnerInitPos + MoveDistance;
		Spawner->SetActorLocation(SpawnerPos);
	}
}

std::shared_ptr<AEnemy> USpawnerManager::SpawnBoss(EMonsterOrder _BossMonsterOrder)
{
	std::shared_ptr<AEnemy> Boss = nullptr;

	switch (_BossMonsterOrder)
	{
	case EMonsterOrder::BossBat1:
		Boss = GetWorld()->SpawnActor<ABossBat1>("BossBat1");
		break;
	case EMonsterOrder::BossBat2:
		Boss = GetWorld()->SpawnActor<ABossBat2>("BossBat2");
		break;
	case EMonsterOrder::Mentis:
		Boss = GetWorld()->SpawnActor<AMentis>("Mentis");
		break;
	case EMonsterOrder::XLMummy:
		Boss = GetWorld()->SpawnActor<AXLMummy>("BossMummy");
		break;
	case EMonsterOrder::XLFlower:
		Boss = GetWorld()->SpawnActor<AXLFlower>("BossFlower");
		break;
	default:
		break;
	}

	Boss->SetActorLocation(UContentsValue::Player->GetActorLocation() + FVector(1000.f, 0.f, 0.f));

	Boss->SetBoss();

	return Boss;
}

void USpawnerManager::SpawnBatMass()
{
	FVector PlayerPos = UContentsValue::Player->GetActorLocation();
	float Random = UEngineRandom::MainRandom.RandomFloat(0.f, 360.f);

	FVector DistanceVector = FVector::Right;
	DistanceVector.RotationZToDeg(Random);
	DistanceVector *= 1000.f;

	FVector InitialPos = PlayerPos + DistanceVector;
	FVector TargetPos = PlayerPos - DistanceVector;

	FVector MassDir = (TargetPos - InitialPos).Normalize3DReturn();
	

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			int Random = UEngineRandom::MainRandom.RandomInt(0, 2);

			std::shared_ptr<AEnemy> Bat = nullptr;
			switch (Random)
			{
			case 0:
				Bat = GetWorld()->SpawnActor<ABat1>("Bat1");
				break;
			case 1:
				Bat = GetWorld()->SpawnActor<ABat2>("Bat2");
				break;
			case 2:
				Bat = GetWorld()->SpawnActor<ABat3>("Bat3");
				break;
			}

			Bat->SetActorLocation(InitialPos  + FVector(10.f * i, 10.f*j,0.f));
			Bat->SetTargetPos(TargetPos);
			Bat->SetMass(true);
			DelayCallBack(1.f, [=]
				{
					Bat->SetMassDir(MassDir);
				});
		}
	}
}

void USpawnerManager::SpawnFlowerPrison()
{
	for (int i = 0; i < 360; i += 3)
	{
		FVector PlayerPos = UContentsValue::Player->GetActorLocation();
		float XCos = cosf(static_cast<float>(i));
		float YSin = 0.7f * sinf(static_cast<float>(i));

		float SpawnDistance = 1000.f;

		FVector SpawnPos = PlayerPos + FVector(XCos * SpawnDistance, YSin * SpawnDistance, 0.f);

		std::shared_ptr<AFlower> Flower = GetWorld()->SpawnActor<AFlower>("Flower");
		Flower->GetEnemyData().MaxHp = 30 * UContentsValue::PlayerLevel;
		Flower->GetEnemyData().Hp = 30 * UContentsValue::PlayerLevel;
		Flower->SetActorLocation(SpawnPos);
		DelayCallBack(30.f, [=]
			{
				Flower->Destroy();
			});
	}
}


void USpawnerManager::StateInit()
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
		State.SetStartFunction("0", std::bind(&USpawnerManager::Minute_00Start, this));
		State.SetUpdateFunction("0", std::bind(&USpawnerManager::Minute_00, this, std::placeholders::_1));
		State.SetStartFunction("1", std::bind(&USpawnerManager::Minute_01Start, this));
		State.SetUpdateFunction("1", std::bind(&USpawnerManager::Minute_01, this, std::placeholders::_1));
		State.SetStartFunction("2", std::bind(&USpawnerManager::Minute_02Start, this));
		State.SetUpdateFunction("2", std::bind(&USpawnerManager::Minute_02, this, std::placeholders::_1));
		State.SetStartFunction("3", std::bind(&USpawnerManager::Minute_03Start, this));
		State.SetUpdateFunction("3", std::bind(&USpawnerManager::Minute_03, this, std::placeholders::_1));
		State.SetStartFunction("4", std::bind(&USpawnerManager::Minute_04Start, this));
		State.SetUpdateFunction("4", std::bind(&USpawnerManager::Minute_04, this, std::placeholders::_1));
		State.SetStartFunction("5", std::bind(&USpawnerManager::Minute_05Start, this));
		State.SetUpdateFunction("5", std::bind(&USpawnerManager::Minute_05, this, std::placeholders::_1));
		State.SetStartFunction("6", std::bind(&USpawnerManager::Minute_06Start, this));
		State.SetUpdateFunction("6", std::bind(&USpawnerManager::Minute_06, this, std::placeholders::_1));
		State.SetStartFunction("7", std::bind(&USpawnerManager::Minute_07Start, this));
		State.SetUpdateFunction("7", std::bind(&USpawnerManager::Minute_07, this, std::placeholders::_1));
		State.SetStartFunction("8", std::bind(&USpawnerManager::Minute_08Start, this));
		State.SetUpdateFunction("8", std::bind(&USpawnerManager::Minute_08, this, std::placeholders::_1));
		State.SetStartFunction("9", std::bind(&USpawnerManager::Minute_09Start, this));
		State.SetUpdateFunction("9", std::bind(&USpawnerManager::Minute_09, this, std::placeholders::_1));

		State.SetStartFunction("10", std::bind(&USpawnerManager::Minute_10Start, this));
		State.SetUpdateFunction("10", std::bind(&USpawnerManager::Minute_10, this, std::placeholders::_1));
		State.SetStartFunction("11", std::bind(&USpawnerManager::Minute_11Start, this));
		State.SetUpdateFunction("11", std::bind(&USpawnerManager::Minute_11, this, std::placeholders::_1));
		State.SetStartFunction("12", std::bind(&USpawnerManager::Minute_12Start, this));
		State.SetUpdateFunction("12", std::bind(&USpawnerManager::Minute_12, this, std::placeholders::_1));
		State.SetStartFunction("13", std::bind(&USpawnerManager::Minute_13Start, this));
		State.SetUpdateFunction("13", std::bind(&USpawnerManager::Minute_13, this, std::placeholders::_1));
		State.SetStartFunction("14", std::bind(&USpawnerManager::Minute_14Start, this));
		State.SetUpdateFunction("14", std::bind(&USpawnerManager::Minute_14, this, std::placeholders::_1));
		State.SetStartFunction("15", std::bind(&USpawnerManager::Minute_15Start, this));
		State.SetUpdateFunction("15", std::bind(&USpawnerManager::Minute_15, this, std::placeholders::_1));
		State.SetStartFunction("16", std::bind(&USpawnerManager::Minute_16Start, this));
		State.SetUpdateFunction("16", std::bind(&USpawnerManager::Minute_16, this, std::placeholders::_1));
		State.SetStartFunction("17", std::bind(&USpawnerManager::Minute_17Start, this));
		State.SetUpdateFunction("17", std::bind(&USpawnerManager::Minute_17, this, std::placeholders::_1));
		State.SetStartFunction("18", std::bind(&USpawnerManager::Minute_18Start, this));
		State.SetUpdateFunction("18", std::bind(&USpawnerManager::Minute_18, this, std::placeholders::_1));
		State.SetStartFunction("19", std::bind(&USpawnerManager::Minute_19Start, this));
		State.SetUpdateFunction("19", std::bind(&USpawnerManager::Minute_19, this, std::placeholders::_1));

		State.SetStartFunction("20", std::bind(&USpawnerManager::Minute_20Start, this));
		State.SetUpdateFunction("20", std::bind(&USpawnerManager::Minute_20, this, std::placeholders::_1));
		State.SetStartFunction("21", std::bind(&USpawnerManager::Minute_21Start, this));
		State.SetUpdateFunction("21", std::bind(&USpawnerManager::Minute_21, this, std::placeholders::_1));
		State.SetStartFunction("22", std::bind(&USpawnerManager::Minute_22Start, this));
		State.SetUpdateFunction("22", std::bind(&USpawnerManager::Minute_22, this, std::placeholders::_1));
		State.SetStartFunction("23", std::bind(&USpawnerManager::Minute_23Start, this));
		State.SetUpdateFunction("23", std::bind(&USpawnerManager::Minute_23, this, std::placeholders::_1));
		State.SetStartFunction("24", std::bind(&USpawnerManager::Minute_24Start, this));
		State.SetUpdateFunction("24", std::bind(&USpawnerManager::Minute_24, this, std::placeholders::_1));
		State.SetStartFunction("25", std::bind(&USpawnerManager::Minute_25Start, this));
		State.SetUpdateFunction("25", std::bind(&USpawnerManager::Minute_25, this, std::placeholders::_1));
		State.SetStartFunction("26", std::bind(&USpawnerManager::Minute_26Start, this));
		State.SetUpdateFunction("26", std::bind(&USpawnerManager::Minute_26, this, std::placeholders::_1));
		State.SetStartFunction("27", std::bind(&USpawnerManager::Minute_27Start, this));
		State.SetUpdateFunction("27", std::bind(&USpawnerManager::Minute_27, this, std::placeholders::_1));
		State.SetStartFunction("28", std::bind(&USpawnerManager::Minute_28Start, this));
		State.SetUpdateFunction("28", std::bind(&USpawnerManager::Minute_28, this, std::placeholders::_1));
		State.SetStartFunction("29", std::bind(&USpawnerManager::Minute_29Start, this));
		State.SetUpdateFunction("29", std::bind(&USpawnerManager::Minute_29, this, std::placeholders::_1));
	}

	State.ChangeState("0");
}

void USpawnerManager::Minute_00(float _DeltaTime)
{
	if (CurTime > 0)
	{
		State.ChangeState("1");
	}
}

void USpawnerManager::Minute_01(float _DeltaTime)
{
	if (CurTime > 1)
	{
		State.ChangeState("2");
	}
}

void USpawnerManager::Minute_02(float _DeltaTime)
{
	if (CurTime > 2)
	{
		MassSpawnAcc = 0.f;
		State.ChangeState("3");
	}


	MassSpawnAcc += _DeltaTime;
	if (MassSpawnAcc > MassSpawnTime)
	{
		MassSpawnAcc = 0.f;
		SpawnBatMass();
	}

}

void USpawnerManager::Minute_03(float _DeltaTime)
{
	if (CurTime > 3)
	{
		State.ChangeState("4");
	}
}

void USpawnerManager::Minute_04(float _DeltaTime)
{
	if (CurTime > 4)
	{
		State.ChangeState("5");
	}
}

void USpawnerManager::Minute_05(float _DeltaTime)
{
	if (CurTime > 5)
	{
		State.ChangeState("6");
	}
}

void USpawnerManager::Minute_06(float _DeltaTime)
{
	if (CurTime > 6)
	{
		State.ChangeState("7");
	}
}

void USpawnerManager::Minute_07(float _DeltaTime)
{
	if (CurTime > 7)
	{
		State.ChangeState("8");
	}
}

void USpawnerManager::Minute_08(float _DeltaTime)
{
	if (CurTime > 8)
	{
		State.ChangeState("9");
	}
}

void USpawnerManager::Minute_09(float _DeltaTime)
{
	if (CurTime > 9)
	{
		State.ChangeState("10");
	}
}

void USpawnerManager::Minute_10(float _DeltaTime)
{
	if (CurTime > 10)
	{
		State.ChangeState("11");
	}
}

void USpawnerManager::Minute_11(float _DeltaTime)
{
	if (CurTime > 11)
	{
		State.ChangeState("12");
	}
}

void USpawnerManager::Minute_12(float _DeltaTime)
{
	if (CurTime > 12)
	{
		State.ChangeState("13");
	}
}

void USpawnerManager::Minute_13(float _DeltaTime)
{
	if (CurTime > 13)
	{
		State.ChangeState("14");
	}
}

void USpawnerManager::Minute_14(float _DeltaTime)
{
	if (CurTime > 14)
	{
		State.ChangeState("15");
	}
}

void USpawnerManager::Minute_15(float _DeltaTime)
{
	if (CurTime > 15)
	{
		State.ChangeState("16");
	}
}

void USpawnerManager::Minute_16(float _DeltaTime)
{
	if (CurTime > 16)
	{
		State.ChangeState("17");
	}
}

void USpawnerManager::Minute_17(float _DeltaTime)
{
	if (CurTime > 17)
	{
		State.ChangeState("18");
	}
}

void USpawnerManager::Minute_18(float _DeltaTime)
{
	if (CurTime > 18)
	{
		State.ChangeState("19");
	}
}

void USpawnerManager::Minute_19(float _DeltaTime)
{
	if (CurTime > 19)
	{
		State.ChangeState("20");
	}
}

void USpawnerManager::Minute_20(float _DeltaTime)
{
	if (CurTime > 20)
	{
		State.ChangeState("21");
	}
}

void USpawnerManager::Minute_21(float _DeltaTime)
{
	if (CurTime > 21)
	{
		State.ChangeState("22");
	}
}

void USpawnerManager::Minute_22(float _DeltaTime)
{
	if (CurTime > 22)
	{
		State.ChangeState("23");
	}
}

void USpawnerManager::Minute_23(float _DeltaTime)
{
	if (CurTime > 23)
	{
		State.ChangeState("24");
	}
}

void USpawnerManager::Minute_24(float _DeltaTime)
{
	if (CurTime > 24)
	{
		State.ChangeState("25");
	}
}

void USpawnerManager::Minute_25(float _DeltaTime)
{
	if (CurTime > 25)
	{
		State.ChangeState("26");
	}
}

void USpawnerManager::Minute_26(float _DeltaTime)
{
	if (CurTime > 26)
	{
		State.ChangeState("27");
	}
}

void USpawnerManager::Minute_27(float _DeltaTime)
{
	if (CurTime > 27)
	{
		State.ChangeState("28");
	}
}

void USpawnerManager::Minute_28(float _DeltaTime)
{
	if (CurTime > 28)
	{
		State.ChangeState("29");
	}
}

void USpawnerManager::Minute_29(float _DeltaTime)
{

}

void USpawnerManager::Minute_00Start()
{
	RandomList.clear();
	RandomList.push_back(EMonsterOrder::Bat1);
	RandomList.push_back(EMonsterOrder::Bat2);
	RandomList.push_back(EMonsterOrder::Bat3);

	SpawnTime = 5.f;

}

void USpawnerManager::Minute_01Start()
{
	RandomList.clear();

	RandomList.push_back(EMonsterOrder::Bat1);
	RandomList.push_back(EMonsterOrder::Bat2);
	RandomList.push_back(EMonsterOrder::Bat3);
	RandomList.push_back(EMonsterOrder::Ghoul1);
	RandomList.push_back(EMonsterOrder::Ghoul2);
	RandomList.push_back(EMonsterOrder::Ghoul3);

	SpawnTime = 5.f;

	SpawnBoss(EMonsterOrder::BossBat1);
}

void USpawnerManager::Minute_02Start()
{
	RandomList.clear();

	RandomList.push_back(EMonsterOrder::Bat1);
	RandomList.push_back(EMonsterOrder::Bat2);
	RandomList.push_back(EMonsterOrder::Bat3);
	RandomList.push_back(EMonsterOrder::Ghoul1);
	RandomList.push_back(EMonsterOrder::Ghoul2);
	RandomList.push_back(EMonsterOrder::Ghoul3);

	SpawnTime = 5.f;
	
	MassSpawnTime = 10.f;
	SpawnBatMass();																																																																																																																																																																					
}

void USpawnerManager::Minute_03Start()
{
	RandomList.clear();

	RandomList.push_back(EMonsterOrder::Skeleton);

	SpawnTime = 5.f;

	SpawnBoss(EMonsterOrder::BossBat1);
}

void USpawnerManager::Minute_04Start()
{
	RandomList.clear();

	RandomList.push_back(EMonsterOrder::Ghost);
	RandomList.push_back(EMonsterOrder::Skeleton);

	SpawnTime = 5.f;

}

void USpawnerManager::Minute_05Start()
{
	RandomList.clear();

	RandomList.push_back(EMonsterOrder::Mudman2);

	SpawnTime = 5.f;

	SpawnBoss(EMonsterOrder::Mentis);

	SpawnFlowerPrison();
}

void USpawnerManager::Minute_06Start()
{
	RandomList.clear();
	RandomList.push_back(EMonsterOrder::Mudman2);
	RandomList.push_back(EMonsterOrder::Ghoul1);
	RandomList.push_back(EMonsterOrder::Ghoul2);
	RandomList.push_back(EMonsterOrder::Ghoul3);

	SpawnTime = 5.f;
}

void USpawnerManager::Minute_07Start()
{
	RandomList.clear();
	RandomList.push_back(EMonsterOrder::Bat1);
	RandomList.push_back(EMonsterOrder::Bat2);
	RandomList.push_back(EMonsterOrder::Bat3);
	RandomList.push_back(EMonsterOrder::Mudman1);

	SpawnTime = 5.f;

	SpawnBoss(EMonsterOrder::BossBat1);

}

void USpawnerManager::Minute_08Start()
{
	RandomList.clear();
	RandomList.push_back(EMonsterOrder::Ghoul1);
	RandomList.push_back(EMonsterOrder::Ghoul2);
	RandomList.push_back(EMonsterOrder::Ghoul3);

	SpawnTime = 5.f;
}

void USpawnerManager::Minute_09Start()
{
	RandomList.clear();
	RandomList.push_back(EMonsterOrder::Ghoul1);
	RandomList.push_back(EMonsterOrder::Ghoul2);
	RandomList.push_back(EMonsterOrder::Ghoul3);
	RandomList.push_back(EMonsterOrder::XLBat);

	SpawnTime = 5.f;

	SpawnBoss(EMonsterOrder::BossBat2);
}

void USpawnerManager::Minute_10Start()
{
	RandomList.clear();
	RandomList.push_back(EMonsterOrder::Mummy);
	RandomList.push_back(EMonsterOrder::Mudman2);


	SpawnTime = 5.f;

	SpawnBoss(EMonsterOrder::Mentis);

	SpawnFlowerPrison();
}

void USpawnerManager::Minute_11Start()
{
	RandomList.clear();
	RandomList.push_back(EMonsterOrder::Skeleton);

	SpawnTime = 0.5f;
}

void USpawnerManager::Minute_12Start()
{
	RandomList.clear();
	RandomList.push_back(EMonsterOrder::Ghost);
	RandomList.push_back(EMonsterOrder::Werewolf);
	RandomList.push_back(EMonsterOrder::Skeleton);

	SpawnTime = 5.f;

	SpawnBoss(EMonsterOrder::BossBat1);
}

void USpawnerManager::Minute_13Start()
{
	RandomList.clear();
	RandomList.push_back(EMonsterOrder::Ghost);
	RandomList.push_back(EMonsterOrder::Werewolf);

	SpawnTime = 5.f;
}

void USpawnerManager::Minute_14Start()
{
	RandomList.clear();
	RandomList.push_back(EMonsterOrder::Werewolf);
	RandomList.push_back(EMonsterOrder::XLBat);

	SpawnTime = 5.f;

	SpawnBoss(EMonsterOrder::BossBat2);
}

void USpawnerManager::Minute_15Start()
{
	RandomList.clear();
	RandomList.push_back(EMonsterOrder::Werewolf);
	RandomList.push_back(EMonsterOrder::XLBat);
	RandomList.push_back(EMonsterOrder::Mudman2);

	SpawnTime = 5.f;

	SpawnFlowerPrison();
}

void USpawnerManager::Minute_16Start()
{
	RandomList.clear();
	RandomList.push_back(EMonsterOrder::Mentis);
	RandomList.push_back(EMonsterOrder::Mummy);
	RandomList.push_back(EMonsterOrder::Mudman2);

	SpawnTime = 5.f;

	SpawnBoss(EMonsterOrder::BossBat1);
}

void USpawnerManager::Minute_17Start()
{
	RandomList.clear();
	RandomList.push_back(EMonsterOrder::SmallMummy);

	SpawnTime = 5.f;
}

void USpawnerManager::Minute_18Start()
{
	RandomList.clear();
	RandomList.push_back(EMonsterOrder::SmallMummy);
	RandomList.push_back(EMonsterOrder::Mummy);

	SpawnTime = 5.f;

	SpawnBoss(EMonsterOrder::BossBat2);
}

void USpawnerManager::Minute_19Start()
{
	RandomList.clear();
	RandomList.push_back(EMonsterOrder::SmallMummy);
	RandomList.push_back(EMonsterOrder::Mummy);

	SpawnTime = 5.f;

}

void USpawnerManager::Minute_20Start()
{
	RandomList.clear();
	RandomList.push_back(EMonsterOrder::SmallMummy);
	RandomList.push_back(EMonsterOrder::Mudman2);
	RandomList.push_back(EMonsterOrder::XLBat);

	SpawnTime = 5.f;

	SpawnBoss(EMonsterOrder::XLMummy);

}

void USpawnerManager::Minute_21Start()
{
	RandomList.clear();
	RandomList.push_back(EMonsterOrder::Flower);

	SpawnTime = 5.f;
}

void USpawnerManager::Minute_22Start()
{
	RandomList.clear();
	RandomList.push_back(EMonsterOrder::Flower);
	RandomList.push_back(EMonsterOrder::SmallMummy);

	SpawnTime = 5.f;

	SpawnBoss(EMonsterOrder::BossBat1);
}

void USpawnerManager::Minute_23Start()
{
	RandomList.clear();
	RandomList.push_back(EMonsterOrder::Flower);
	RandomList.push_back(EMonsterOrder::SmallMummy);

	SpawnTime = 5.f;

	SpawnBoss(EMonsterOrder::BossBat2);
}

void USpawnerManager::Minute_24Start()
{
	RandomList.clear();
	RandomList.push_back(EMonsterOrder::Flower);
	RandomList.push_back(EMonsterOrder::SmallMummy);

	SpawnTime = 5.f;
}

void USpawnerManager::Minute_25Start()
{
	RandomList.clear();
	RandomList.push_back(EMonsterOrder::Flower);
	RandomList.push_back(EMonsterOrder::SmallFlower);

	SpawnTime = 5.f;

	SpawnBoss(EMonsterOrder::XLFlower);
}

void USpawnerManager::Minute_26Start()
{
	RandomList.clear();
	RandomList.push_back(EMonsterOrder::SmallFlower);

	SpawnTime = 5.f;
}

void USpawnerManager::Minute_27Start()
{
	RandomList.clear();
	RandomList.push_back(EMonsterOrder::Mudman2);
	RandomList.push_back(EMonsterOrder::SmallMummy);
	RandomList.push_back(EMonsterOrder::Mummy);

	SpawnTime = 5.f;
}

void USpawnerManager::Minute_28Start()
{
	RandomList.clear();
	RandomList.push_back(EMonsterOrder::BossBat1);
	RandomList.push_back(EMonsterOrder::XLBat);

	SpawnTime = 5.f;
}

void USpawnerManager::Minute_29Start()
{
	RandomList.clear();
	RandomList.push_back(EMonsterOrder::BossBat2);
	RandomList.push_back(EMonsterOrder::BossBat1);

	SpawnTime = 5.f;

}

