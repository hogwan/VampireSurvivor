#pragma once
#include <EngineCore/Actor.h>
#include "PollingObject.h"

// Ό³Έν :
class UPollingManager : public AActor
{
	GENERATED_BODY(AActor)
public:
	// constructor destructor
	UPollingManager();
	~UPollingManager();

	// delete Function
	UPollingManager(const UPollingManager& _Other) = delete;
	UPollingManager(UPollingManager&& _Other) noexcept = delete;
	UPollingManager& operator=(const UPollingManager& _Other) = delete;
	UPollingManager& operator=(UPollingManager&& _Other) noexcept = delete;

	static std::map<EPollingOrder, std::vector<std::shared_ptr<APollingObject>>> PollingObjects;
protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
private:
};

