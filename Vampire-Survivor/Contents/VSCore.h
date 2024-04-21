#pragma once
#include <EngineCore/EngineCore.h>

// Ό³Έν :
class UVSCore : public UserCore
{
public:
	// constrcuter destructer
	UVSCore();
	~UVSCore();

	// delete Function
	UVSCore(const UVSCore& _Other) = delete;
	UVSCore(UVSCore&& _Other) noexcept = delete;
	UVSCore& operator=(const UVSCore& _Other) = delete;
	UVSCore& operator=(UVSCore&& _Other) noexcept = delete;

protected:
	void Initialize() override;

private:

};

