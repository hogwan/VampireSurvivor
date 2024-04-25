#pragma once
#include "Accesory.h"

// Ό³Έν :
class UArmor : public UAccesory
{
	GENERATED_BODY(UAccesory)
public:
	// constructor destructor
	UArmor();
	~UArmor();

	// delete Function
	UArmor(const UArmor& _Other) = delete;
	UArmor(UArmor&& _Other) noexcept = delete;
	UArmor& operator=(const UArmor& _Other) = delete;
	UArmor& operator=(UArmor&& _Other) noexcept = delete;

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

