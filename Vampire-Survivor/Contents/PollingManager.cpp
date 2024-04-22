#include "PreCompile.h"
#include "PollingManager.h"

std::map<EPollingOrder, std::vector<std::shared_ptr<APollingObject>>> UPollingManager::PollingObjects;

UPollingManager::UPollingManager() 
{
}

UPollingManager::~UPollingManager() 
{
}

void UPollingManager::BeginPlay()
{
	Super::BeginPlay();
}

void UPollingManager::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}

