#pragma once
#include <EngineCore/GameMode.h>
#include <EngineCore/Image.h>
// Ό³Έν :
class ATitleGameMode : public AGameMode
{
	GENERATED_BODY(AGameMode)
public:
	// constructor destructor
	ATitleGameMode();
	~ATitleGameMode();

	// delete Function
	ATitleGameMode(const ATitleGameMode& _Other) = delete;
	ATitleGameMode(ATitleGameMode&& _Other) noexcept = delete;
	ATitleGameMode& operator=(const ATitleGameMode& _Other) = delete;
	ATitleGameMode& operator=(ATitleGameMode&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	UDefaultSceneComponent* Root = nullptr;
	USpriteRenderer* BG = nullptr;
	USpriteRenderer* Title = nullptr;
	USpriteRenderer* Cash = nullptr;
	USpriteRenderer* CashBoard = nullptr;
	USpriteRenderer* BlackBack = nullptr;


	int SelectIndex = 0;
	std::vector<std::pair<UImage*, UImage*>> Buttons;
	std::pair<UImage*, UImage*> SelectArrows;

	void OpenPowerUpUI();

	
private:

};

