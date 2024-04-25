#pragma once
#include "Accessory.h"

// ���� :
class UHollowHeart : public UAccessory
{
	GENERATED_BODY(UAccessory);
public:
	// constructor destructor
	UHollowHeart();
	~UHollowHeart();

	// delete Function
	UHollowHeart(const UHollowHeart& _Other) = delete;
	UHollowHeart(UHollowHeart&& _Other) noexcept = delete;
	UHollowHeart& operator=(const UHollowHeart& _Other) = delete;
	UHollowHeart& operator=(UHollowHeart&& _Other) noexcept = delete;

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

