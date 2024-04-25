#pragma once
#include "Accessory.h"

// Ό³Έν :
class UCandelabrador : public UAccessory
{
	GENERATED_BODY(UAccessory)
public:
	// constructor destructor
	UCandelabrador();
	~UCandelabrador();

	// delete Function
	UCandelabrador(const UCandelabrador& _Other) = delete;
	UCandelabrador(UCandelabrador&& _Other) noexcept = delete;
	UCandelabrador& operator=(const UCandelabrador& _Other) = delete;
	UCandelabrador& operator=(UCandelabrador&& _Other) noexcept = delete;

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

