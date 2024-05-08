#pragma once
#include <EngineCore/Widget.h>

// Ό³Έν :
class UChest : public UWidget
{
	// constructor destructor
public:
	UChest();
	~UChest();

	// delete Function
	UChest(const UChest& _Other) = delete;
	UChest(UChest&& _Other) noexcept = delete;
	UChest& operator=(const UChest& _Other) = delete;
	UChest& operator=(UChest&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
private:
	UImage* Chest = nullptr;
	UImage* BackBoard = nullptr;
	UTextWidget* Text = nullptr;
	UImage* Button = nullptr;
	UImage* ButtonText = nullptr;
	std::pair<UImage*, UImage*> Arrows;

};

