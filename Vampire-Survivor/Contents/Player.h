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

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	FVector InitialPos = FVector::Zero;
	FVector MoveVector = FVector::Zero;
	AActorDir CurDir = AActorDir::None;
	EEngineDir SpriteDir = EEngineDir::MAX;

	float MoveSpeed = 300.f;

private:
	UCollision* Collision;
	void MoveLogic();
	void ColLogic(float _DeltaTime);
};