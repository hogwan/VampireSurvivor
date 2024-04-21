#pragma once
#include <EngineCore/Actor.h>

// Ό³Έν :
class USpriteRenderer;
class ABackGroundMap : public AActor
{
	GENERATED_BODY(AActor)

public:
	// constrcuter destructer
	ABackGroundMap();
	~ABackGroundMap();

	// delete Function
	ABackGroundMap(const ABackGroundMap& _Other) = delete;
	ABackGroundMap(ABackGroundMap&& _Other) noexcept = delete;
	ABackGroundMap& operator=(const ABackGroundMap& _Other) = delete;
	ABackGroundMap& operator=(ABackGroundMap&& _Other) noexcept = delete;
	int index;

	USpriteRenderer* Renderer;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
private:

	float4 Color;
};
