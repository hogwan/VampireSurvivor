#pragma once
#include <EngineCore/Widget.h>
#include <EngineCore/StateManager.h>

// Ό³Έν :
class UChestUI : public UWidget
{
	// constructor destructor
public:
	UChestUI();
	~UChestUI();

	// delete Function
	UChestUI(const UChestUI& _Other) = delete;
	UChestUI(UChestUI&& _Other) noexcept = delete;
	UChestUI& operator=(const UChestUI& _Other) = delete;
	UChestUI& operator=(UChestUI&& _Other) noexcept = delete;

	void EventStart();
	void EventTick(float _DeltaTime);
	void EventEnd();

	void UIOn();
	void UIOff();

	void StateInit();

	UStateManager State;
protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
private:
	class UImage* Chest = nullptr;
	class UImage* BackBoard = nullptr;
	class UTextWidget* Text = nullptr;
	class UImage* Button = nullptr;
	class UTextWidget* ButtonText = nullptr;
	std::pair<class UImage*, class UImage*> Arrows;
	class UImage* BlueLight = nullptr;
	class CircuitWeapon* Circuit = nullptr;
	class UnboxingLight* Light = nullptr;
	std::pair<class UTextWidget*, class UImage*> GoldStatus;
	std::vector<class UImage*> SelectedWeapon;

	std::vector<class ACoin*> CoinVec;
	std::vector<class UImage*> ExplainSpriteVec;
	std::vector<class UTextWidget*> ExplainTextVec;

	bool IsUnboxing = false;
	int Random = -1;
	float ObtainGold = 0.f;
	float AccGold = 0.f;

	float UnboxingTime = 6.f;
	float TurnOffTime = 5.f;
	float AccTime = 0.f;

	float AfterUnboxingTime = 3.f;
	float AfterUnboxingAcc = 0.f;

	float CoinThrowTime = 0.05f;
	float CoinTimeAcc = 0.f;
	int CoinNumber = 0;

	bool Bigger = false;
	float SwitchTime = 2.f;
	float SwitchAccTime = 0.f;

	void Wait(float _DeltaTime);
	void Unboxing(float _DeltaTime);
	void AfterUnboxing(float _DeltaTime);
	void EndWait(float _DeltaTime);

	void WaitStart();
	void UnboxingStart();
	void AfterUnboxingStart();
	void EndWaitStart();


	void ItemSelectLogic();
	void ItemEquipLogic();
};

