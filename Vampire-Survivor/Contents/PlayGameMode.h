#pragma once
#include <EngineCore/GameMode.h>

struct FIntPoint
{
	union
	{
		struct
		{
			int X;
			int Y;
		};

		__int64 Key;
	};
};

class APlayGameMode : public AGameMode
{
	GENERATED_BODY(AGameMode)
public:
	//constructer destructer
	APlayGameMode();
	~APlayGameMode();

	//delete Function
	APlayGameMode(const APlayGameMode& _Other) = delete;
	APlayGameMode(APlayGameMode&& _Other) noexcept = delete;
	APlayGameMode& operator=(const APlayGameMode& _Other) = delete;
	APlayGameMode& operator=(APlayGameMode&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	std::shared_ptr<class APlayer> Player;
	std::vector<std::shared_ptr<class ABackGroundMap>> Grounds;
	float4 IndexToCenterPos(FIntPoint _Index);
	FIntPoint PosToIndex(float4 _Pos);
	void InfinityGroundCheck();
	void MapSpawn();

	void UISpawn();
	void UIUpdate();

	void UIHPUpdate();
	void UILevelUpdate();
	void WeaponTilesUpdate();
	void AccessoryTilesUpdate();
	
	class UImage* HPBar = nullptr;
	class UImage* HPBarBack = nullptr;
	class UImage* LevelBar = nullptr;
	class UImage* LevelBarBack = nullptr;
	class UImage* LevelVal = nullptr;
	class UImage* EquipTile = nullptr;
	class UImage* Gold = nullptr;
	class UImage* KillCount = nullptr;

	std::vector<UImage*> WeaponTilesBack;
	std::vector<UImage*> AccessoryTilesBack;

	std::vector<UImage*> WeaponTiles;
	std::vector<UImage*> AccessoryTiles;

private:
	FIntPoint CurIndex = { 0, };
	std::shared_ptr<UCamera> Camera;
};