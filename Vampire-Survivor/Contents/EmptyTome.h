#pragma once
#include "Accesory.h"

// Ό³Έν :
class UEmptyTome : public UAccesory
{
	GENERATED_BODY(UAccesory)
public:
	// constructor destructor
	UEmptyTome();
	~UEmptyTome();

	// delete Function
	UEmptyTome(const UEmptyTome& _Other) = delete;
	UEmptyTome(UEmptyTome&& _Other) noexcept = delete;
	UEmptyTome& operator=(const UEmptyTome& _Other) = delete;
	UEmptyTome& operator=(UEmptyTome&& _Other) noexcept = delete;

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

