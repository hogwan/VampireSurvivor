#pragma once
#include <EngineCore/Actor.h>
#include <EngineCore/Image.h>
#include <EngineCore/TextWidget.h>

// Ό³Έν :
class UIManager : public AActor
{
	GENERATED_BODY(AActor)
public:
	// constructor destructor
	UIManager();
	~UIManager();

	// delete Function
	UIManager(const UIManager& _Other) = delete;
	UIManager(UIManager&& _Other) noexcept = delete;
	UIManager& operator=(const UIManager& _Other) = delete;
	UIManager& operator=(UIManager&& _Other) noexcept = delete;

	void LevelUpEventStart();
	void LevelUpEventEnd();
	void LevelUpEventTick();
protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void UISpawn();
	void UIUpdate();

	void UIHPUpdate();
	void UILevelUpdate();
	void WeaponTilesUpdate();
	void AccessoryTilesUpdate();
	void UIPlayerStatusUpdate();
	void KillCountUpdate();
	void GoldUpdate();
	void TimeUpdate(float _DeltaTime);
	
	int RandomPickLogic();

	void LevelUpUIOn();
	void LevelUpUIOff();

	UImage* HPBar = nullptr;
	UImage* HPBarBack = nullptr;
	UImage* LevelBar = nullptr;
	UImage* LevelBarBack = nullptr;
	UImage* EquipTile = nullptr;
	UImage* Gold = nullptr;
	UImage* KillCount = nullptr;
	UImage* WeaponInfoBackBoard = nullptr;
	UImage* PlayerStatusInfoBackBoard = nullptr;
	UImage* LevelUpBackBoard = nullptr;
	UTextWidget* LevelUpText = nullptr;
	UTextWidget* AdditionalMessage = nullptr;
	UTextWidget* KillCountText = nullptr;
	UTextWidget* GoldText = nullptr;
	UTextWidget* TimeUI = nullptr;

	std::vector<UImage*> WeaponTilesBack;
	std::vector<UImage*> AccessoryTilesBack;

	std::vector<UImage*> WeaponTiles;
	std::vector<UImage*> AccessoryTiles;

	std::vector<UImage*> WeaponInfoBack;
	std::vector<std::vector<UImage*>> WeaponInfo;

	std::vector<UImage*> AccessoryInfoBack;
	std::vector<std::vector<UImage*>> AccessoryInfo;

	std::vector<UImage*> PlayerStatusInfoSprite;
	std::vector<std::pair<UTextWidget*, UTextWidget*>> PlayerStatusInfoText;


	std::vector<std::vector<UImage*>> LevelUpList;
	std::vector<std::vector<UTextWidget*>> LevelUpListExplain;
	std::pair<UImage*, UImage*> SelectArrows;

	std::list<ESelectList> SelectList;
	std::vector<ESelectList> InfoVec;


	bool IsSelecting = false;
	int SelectIndex = 0;
private:

};

