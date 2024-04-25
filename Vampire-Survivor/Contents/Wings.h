#pragma once
#include "Accesory.h"

// Ό³Έν :
class UWings : public UAccesory
{
	GENERATED_BODY(UAccesory)
public:
	// constructor destructor
	UWings();
	~UWings();

	// delete Function
	UWings(const UWings& _Other) = delete;
	UWings(UWings&& _Other) noexcept = delete;
	UWings& operator=(const UWings& _Other) = delete;
	UWings& operator=(UWings&& _Other) noexcept = delete;

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

