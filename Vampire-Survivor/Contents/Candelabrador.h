#pragma once
#include "Accesory.h"

// Ό³Έν :
class UCandelabrador : public UAccesory
{
	GENERATED_BODY(UAccesory)
public:
	// constructor destructor
	UCandelabrador();
	~UCandelabrador();

	// delete Function
	UCandelabrador(const UCandelabrador& _Other) = delete;
	UCandelabrador(UCandelabrador&& _Other) noexcept = delete;
	UCandelabrador& operator=(const UCandelabrador& _Other) = delete;
	UCandelabrador& operator=(UCandelabrador&& _Other) noexcept = delete;

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

