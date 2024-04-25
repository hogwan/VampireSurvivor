#pragma once
#include "Accessory.h"

// Ό³Έν :
class UAttractorb : public UAccessory
{
	GENERATED_BODY(UAccessory)
public:
	// constructor destructor
	UAttractorb();
	~UAttractorb();

	// delete Function
	UAttractorb(const UAttractorb& _Other) = delete;
	UAttractorb(UAttractorb&& _Other) noexcept = delete;
	UAttractorb& operator=(const UAttractorb& _Other) = delete;
	UAttractorb& operator=(UAttractorb&& _Other) noexcept = delete;

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

