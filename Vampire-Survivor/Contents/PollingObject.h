#pragma once
#include "VSObject.h"

// Ό³Έν :
class APollingObject : public AVSObject
{
	GENERATED_BODY(AVSObject)
public:
	// constructor destructor
	APollingObject();
	~APollingObject();

	// delete Function
	APollingObject(const APollingObject& _Other) = delete;
	APollingObject(APollingObject&& _Other) noexcept = delete;
	APollingObject& operator=(const APollingObject& _Other) = delete;
	APollingObject& operator=(APollingObject&& _Other) noexcept = delete;

	void ActiveOn();
	void ActiveOff();

	bool GetIsLive()
	{
		return IsLive;
	}

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	bool IsLive = true;

private:

};

