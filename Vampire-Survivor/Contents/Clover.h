#pragma once
#include "Accesory.h"

// Ό³Έν :
class UClover : public UAccesory
{
	GENERATED_BODY(UAccesory)
public:
	// constructor destructor
	UClover();
	~UClover();

	// delete Function
	UClover(const UClover& _Other) = delete;
	UClover(UClover&& _Other) noexcept = delete;
	UClover& operator=(const UClover& _Other) = delete;
	UClover& operator=(UClover&& _Other) noexcept = delete;

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

