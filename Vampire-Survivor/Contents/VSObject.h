#pragma once
#include <EngineCore/Actor.h>

// Ό³Έν :
class AVSObject : public AActor
{
	GENERATED_BODY(AActor)
public:
	// constructor destructor
	AVSObject();
	~AVSObject();

	// delete Function
	AVSObject(const AVSObject& _Other) = delete;
	AVSObject(AVSObject&& _Other) noexcept = delete;
	AVSObject& operator=(const AVSObject& _Other) = delete;
	AVSObject& operator=(AVSObject&& _Other) noexcept = delete;

	EEngineDir GetSpriteDir()
	{
		return SpriteDir;
	}

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	EEngineDir SpriteDir = EEngineDir::MAX;
	void DirCheck();

	UDefaultSceneComponent* Root = nullptr;
	USpriteRenderer* Renderer = nullptr;
	UCollision* Collider = nullptr;

	FVector MoveVector = FVector::Zero;
	float PushPower = 0.f;

private:

};

