#pragma once
#include "Accesory.h"

// Ό³Έν :
class UAttractorb : public UAccesory
{
	GENERATED_BODY(UAccesory)
public:
	// constructor destructor
	UAttractorb();
	~UAttractorb();

	// delete Function
	UAttractorb(const UAttractorb& _Other) = delete;
	UAttractorb(UAttractorb&& _Other) noexcept = delete;
	UAttractorb& operator=(const UAttractorb& _Other) = delete;
	UAttractorb& operator=(UAttractorb&& _Other) noexcept = delete;

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

