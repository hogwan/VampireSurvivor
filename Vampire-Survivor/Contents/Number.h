#pragma once
#include <EngineCore/Actor.h>

// Ό³Έν :
class ANumber : public AActor
{
	GENERATED_BODY(AActor)
public:
	// constructor destructor
	ANumber();
	~ANumber();

	// delete Function
	ANumber(const ANumber& _Other) = delete;
	ANumber(ANumber&& _Other) noexcept = delete;
	ANumber& operator=(const ANumber& _Other) = delete;
	ANumber& operator=(ANumber&& _Other) noexcept = delete;

	UDefaultSceneComponent* GetRoot()
	{
		return Root;
	}

	void SetNum(int _Num)
	{
		Renderer->SetSprite("Number", _Num);
	}


	USpriteRenderer* Renderer = nullptr;
	UDefaultSceneComponent* Root = nullptr;
protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	float MaxSize = 35.f;
	float CurSize = 0.f;
	float SizeUpSpeed = 70.f;
	float Alpha = 1.f;
	float DecreaseAlpha = 2.5f;

	bool ReachMax = false;

private:

};

