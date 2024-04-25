#pragma once
#include "Accessory.h"

// Ό³Έν :
class UEmptyTome : public UAccessory
{
	GENERATED_BODY(UAccessory)
public:
	// constructor destructor
	UEmptyTome();
	~UEmptyTome();

	// delete Function
	UEmptyTome(const UEmptyTome& _Other) = delete;
	UEmptyTome(UEmptyTome&& _Other) noexcept = delete;
	UEmptyTome& operator=(const UEmptyTome& _Other) = delete;
	UEmptyTome& operator=(UEmptyTome&& _Other) noexcept = delete;

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

