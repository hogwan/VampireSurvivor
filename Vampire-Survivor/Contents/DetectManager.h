#pragma once
#include <EngineCore/Actor.h>
#include "Enemy.h"

// Ό³Έν :
class UDetectManager : public AActor
{
	GENERATED_BODY(AActor)
public:
	// constructor destructor
	UDetectManager();
	~UDetectManager();

	// delete Function
	UDetectManager(const UDetectManager& _Other) = delete;
	UDetectManager(UDetectManager&& _Other) noexcept = delete;
	UDetectManager& operator=(const UDetectManager& _Other) = delete;
	UDetectManager& operator=(UDetectManager&& _Other) noexcept = delete;

	static std::list<AEnemy*> AllDetectedEnemy;
	static float DetectRange;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void DetectUpdate();
private:

};

