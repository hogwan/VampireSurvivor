#pragma once
#include "Accessory.h"

// Ό³Έν :
class UPummarola : public UAccessory
{
	GENERATED_BODY(UAccessory)
public:
	// constructor destructor
	UPummarola();
	~UPummarola();

	// delete Function
	UPummarola(const UPummarola& _Other) = delete;
	UPummarola(UPummarola&& _Other) noexcept = delete;
	UPummarola& operator=(const UPummarola& _Other) = delete;
	UPummarola& operator=(UPummarola&& _Other) noexcept = delete;

	static FAccessoryData Data;

	FAccessoryData GetData() override
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

