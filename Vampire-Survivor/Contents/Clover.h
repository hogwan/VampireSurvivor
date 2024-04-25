#pragma once
#include "Accessory.h"

// Ό³Έν :
class UClover : public UAccessory
{
	GENERATED_BODY(UAccessory)
public:
	// constructor destructor
	UClover();
	~UClover();

	// delete Function
	UClover(const UClover& _Other) = delete;
	UClover(UClover&& _Other) noexcept = delete;
	UClover& operator=(const UClover& _Other) = delete;
	UClover& operator=(UClover&& _Other) noexcept = delete;

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

