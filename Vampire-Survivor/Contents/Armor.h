#pragma once
#include "Accessory.h"

// Ό³Έν :
class UArmor : public UAccessory
{
	GENERATED_BODY(UAccessory)
public:
	// constructor destructor
	UArmor();
	~UArmor();

	// delete Function
	UArmor(const UArmor& _Other) = delete;
	UArmor(UArmor&& _Other) noexcept = delete;
	UArmor& operator=(const UArmor& _Other) = delete;
	UArmor& operator=(UArmor&& _Other) noexcept = delete;

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

