#pragma once
#include "VSObject.h"
enum class AActorDir
{
	None,
	N,
	NE,
	E,
	SE,
	S,
	SW,
	W,
	NW
};

class APlayer : public AVSObject
{
	GENERATED_BODY(AVSObject)
public:
	//constructer destructer
	APlayer();
	~APlayer();

	//delete Function
	APlayer(const APlayer& _Other) = delete;
	APlayer(APlayer&& _Other) noexcept = delete;
	APlayer& operator=(const APlayer& _Other) = delete;
	APlayer& operator=(APlayer&& _Other) noexcept = delete;

	FVector GetInitialPos()
	{
		return InitialPos;
	}

	FVector GetPlayerDir()
	{
		return DirVector.Normalize3DReturn();
	}

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	FVector InitialPos = FVector::Zero;
	FVector DirVector = FVector::Zero;
	AActorDir ECurDir = AActorDir::None;

	float MoveSpeed = 300.f;

private:
	void MoveLogic();
	void ColLogic();
};