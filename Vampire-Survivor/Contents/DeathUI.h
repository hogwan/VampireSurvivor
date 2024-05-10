#pragma once
#include <EngineCore/Widget.h>

// Ό³Έν :
class UDeathUI : public UWidget
{
	GENERATED_BODY(UWidget)
public:
	// constructor destructor
	UDeathUI();
	~UDeathUI();

	// delete Function
	UDeathUI(const UDeathUI& _Other) = delete;
	UDeathUI(UDeathUI&& _Other) noexcept = delete;
	UDeathUI& operator=(const UDeathUI& _Other) = delete;
	UDeathUI& operator=(UDeathUI&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	class UImage* BackGround = nullptr;
	class UImage* GameOver = nullptr;
	class UImage* Button = nullptr;
	class UTextWidget* ButtonText = nullptr;
	std::pair<class UImage*, class UImage*> Arrows;
private:

};

