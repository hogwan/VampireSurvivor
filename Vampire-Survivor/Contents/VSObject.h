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

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	UDefaultSceneComponent* Root = nullptr;
	USpriteRenderer* Renderer = nullptr;

private:

};

