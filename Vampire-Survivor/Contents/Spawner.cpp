#include "PreCompile.h"
#include "Spawner.h"
#include "Player.h"

Spawner::Spawner() 
{
}

Spawner::~Spawner() 
{
}

void Spawner::BeginPlay()
{
	Super::BeginPlay();

	SpawnPointInit();
}

void Spawner::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	SpawnPointReposition();
}

void Spawner::SpawnPointInit()
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
			SpawnPointDesc Desc;
			Desc.InitialPos = FirstPos + FVector(XBot * X, YBot * Y, 0.f);
			Desc.CurPos = FirstPos + FVector(XBot * X, YBot * Y, 0.f);
			SpawnPoint.push_back(Desc);
		}
	}
}

void Spawner::SpawnPointReposition()
{
	for (SpawnPointDesc _Desc : SpawnPoint)
	{

	}
}

