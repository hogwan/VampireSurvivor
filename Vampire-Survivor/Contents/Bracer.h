#pragma once
#include "Accesory.h"

// Ό³Έν :
class UBracer : public UAccesory
{
	GENERATED_BODY(UAccesory)
public:
	// constructor destructor
	UBracer();
	~UBracer();

	// delete Function
	UBracer(const UBracer& _Other) = delete;
	UBracer(UBracer&& _Other) noexcept = delete;
	UBracer& operator=(const UBracer& _Other) = delete;
	UBracer& operator=(UBracer&& _Other) noexcept = delete;

	static FAccesoryData Data;

	FAccesoryData GetData() override
	{
		return Data;
	}

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void DataInit() override;
	void LevelUp() override;
private:

};

