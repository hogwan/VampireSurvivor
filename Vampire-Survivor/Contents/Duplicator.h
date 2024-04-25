#pragma once
#include "Accesory.h"

// Ό³Έν :
class UDuplicator : public UAccesory
{
	GENERATED_BODY(UAccesory)
public:
	// constructor destructor
	UDuplicator();
	~UDuplicator();

	// delete Function
	UDuplicator(const UDuplicator& _Other) = delete;
	UDuplicator(UDuplicator&& _Other) noexcept = delete;
	UDuplicator& operator=(const UDuplicator& _Other) = delete;
	UDuplicator& operator=(UDuplicator&& _Other) noexcept = delete;

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

