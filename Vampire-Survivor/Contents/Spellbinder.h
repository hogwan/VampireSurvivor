#pragma once
#include "Accesory.h"

// Ό³Έν :
class USpellbinder : public UAccesory
{
	GENERATED_BODY(UAccesory)
public:
	// constructor destructor
	USpellbinder();
	~USpellbinder();

	// delete Function
	USpellbinder(const USpellbinder& _Other) = delete;
	USpellbinder(USpellbinder&& _Other) noexcept = delete;
	USpellbinder& operator=(const USpellbinder& _Other) = delete;
	USpellbinder& operator=(USpellbinder&& _Other) noexcept = delete;

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

