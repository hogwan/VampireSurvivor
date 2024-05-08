#pragma once
#include <EngineCore/Image.h>
class UnboxingLight : public UImage
{
	GENERATED_BODY(UImage)
public:
	//constructer destructer
	UnboxingLight();
	~UnboxingLight();

	//delete Function
	UnboxingLight(const UnboxingLight& _Other) = delete;
	UnboxingLight(UnboxingLight&& _Other) noexcept = delete;
	UnboxingLight& operator=(const UnboxingLight& _Other) = delete;
	UnboxingLight& operator=(UnboxingLight&& _Other) noexcept = delete;

	void TurnOn()
	{
		IsOn = true;
	}

	void TurnOff()
	{
		IsOn = false;
	}

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	float PlusAlpha = 0.f;

	bool IsOn = false;

private:

};