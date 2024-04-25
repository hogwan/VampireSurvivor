#pragma once
#include "Accesory.h"

// Ό³Έν :
class UPummarola : public UAccesory
{
public:
	// constructor destructor
	UPummarola();
	~UPummarola();

	// delete Function
	UPummarola(const UPummarola& _Other) = delete;
	UPummarola(UPummarola&& _Other) noexcept = delete;
	UPummarola& operator=(const UPummarola& _Other) = delete;
	UPummarola& operator=(UPummarola&& _Other) noexcept = delete;

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

