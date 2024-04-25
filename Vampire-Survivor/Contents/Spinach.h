#pragma once
#include "Accessory.h"

// Ό³Έν :
class USpinach : public UAccessory
{
	GENERATED_BODY(UAccessory)
public:
	// constructor destructor
	USpinach();
	~USpinach();

	// delete Function
	USpinach(const USpinach& _Other) = delete;
	USpinach(USpinach&& _Other) noexcept = delete;
	USpinach& operator=(const USpinach& _Other) = delete;
	USpinach& operator=(USpinach&& _Other) noexcept = delete;

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

