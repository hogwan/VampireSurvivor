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

	bool IsUnboxing = false;
	int Random = -1;
	float UnboxingTime = 6.f;
	float TurnOffTime = 5.f;
	float AccTime = 0.f;

	void Wait(float _DeltaTime);
	void Unboxing(float _DeltaTime);
	void EndWait(float _DeltaTime);

	void WaitStart();
	void UnboxingStart();
	void EndWaitStart();

};

