#include "PreCompile.h"
#include "DetectManager.h"
#include "Player.h"

std::list<AEnemy*> UDetectManager::AllDetectedEnemy;
float UDetectManager::DetectRange = 300.f;

UDetectManager::UDetectManager() 
{
}

UDetectManager::~UDetectManager() 
{
}

void UDetectManager::BeginPlay()
{
	Super::BeginPlay();
}

void UDetectManager::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	DetectUpdate();
}

void UDetectManager::DetectUpdate()
{
	std::list<AEnemy*>::iterator iter = AllDetectedEnemy.begin();
	for (; iter == AllDetectedEnemy.end();)
	{
		if (false == (*iter)->GetIsLive())
		{
			(*iter)->InDetectRange = false;
			iter = AllDetectedEnemy.erase(iter);
			continue;
		}

		FVector PlayerPos = UContentsValue::Player->GetActorLocation();
		PlayerPos.Z = 0.f;
		FVector CurPos = (*iter)->GetActorLocation();
		CurPos.Z = 0.f;

		float Distance = (PlayerPos - CurPos).Size3D();
		if (Distance > DetectRange)
		{
			(*iter)->InDetectRange = false;
			iter = AllDetectedEnemy.erase(iter);
			continue;
		}

		iter++;
	}
}

