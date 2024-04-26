#include "PreCompile.h"
#include "PlayGameMode.h"
#include "BackGroundMap.h"
#include "Player.h"
#include "SpawnerManager.h"
#include "EquipManager.h"
#include "ContentsEditerGUI.h"
#include <EngineCore/Image.h>
#include <EngineCore/Camera.h>

APlayGameMode::APlayGameMode()
{
}

APlayGameMode::~APlayGameMode()
{
}

void APlayGameMode::BeginPlay()
{
	Super::BeginPlay();
	

	Camera = GetWorld()->GetMainCamera();

	std::shared_ptr<UEngineTexture> Tex = UEngineTexture::FindRes("BG_1.png");

	MapSpawn();

	Player = GetWorld()->SpawnActor<APlayer>("Player");
	UContentsValue::Player = Player;
	UContentsValue::StartPosition = Player->GetActorLocation();

	GetWorld()->SpawnActor<USpawnerManager>("SpawnerManager");
	std::shared_ptr<UEquipManager> EquipManager = GetWorld()->SpawnActor<UEquipManager>("EquipManager");
	EquipManager->EquipWeapon(EWeapon::Axe);
	EquipManager->EquipWeapon(EWeapon::Cross);
	EquipManager->EquipWeapon(EWeapon::FireWand);
	EquipManager->EquipWeapon(EWeapon::Garlic);
	EquipManager->EquipWeapon(EWeapon::KingBible);
	EquipManager->EquipWeapon(EWeapon::Knife);
	//EquipManager->EquipWeapon(EWeapon::LightingRing);
	//EquipManager->EquipWeapon(EWeapon::MagicWand);
	//EquipManager->EquipWeapon(EWeapon::RuneTracer);
	//EquipManager->EquipWeapon(EWeapon::SantaWater);

	UISpawn();
}

void APlayGameMode::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	Camera->SetActorLocation(Player->GetActorLocation() - FVector(0.f,0.f,1000.f));
	InfinityGroundCheck();
	UIUpdate();
}

float4 APlayGameMode::IndexToCenterPos(FIntPoint _Index)
{
	float4 Pos;
	Pos.X = UContentsValue::GroundTileSize.X * _Index.X;
	Pos.Y = UContentsValue::GroundTileSize.Y * _Index.Y;

	Pos.X += UContentsValue::GroundTileSize.hX();
	Pos.Y += UContentsValue::GroundTileSize.hY();

	return Pos;
}

FIntPoint APlayGameMode::PosToIndex(float4 _Pos)
{
	FIntPoint Index;

	float4 Location = _Pos;

	float4 Pos;
	Pos.X = Location.X / UContentsValue::GroundTileSize.X;
	Pos.Y = Location.Y / UContentsValue::GroundTileSize.Y;

	if (0 >= Pos.X)
	{
		Pos.X += -1;
	}
	if (0 >= Pos.Y)
	{
		Pos.Y += -1;
	}

	Index.X = static_cast<int>(Pos.X);
	Index.Y = static_cast<int>(Pos.Y);
	return Index;
}

void APlayGameMode::InfinityGroundCheck()
{
	float4 PlayerPos = Player->GetActorLocation();

	FIntPoint Index = PosToIndex(PlayerPos);

	if (Index.X != CurIndex.X || Index.Y != CurIndex.Y)
	{
		int GroundCount = 0;

		float4 MovePos;
		MovePos.X = Index.X * UContentsValue::GroundTileSize.X;
		MovePos.Y = Index.Y * UContentsValue::GroundTileSize.Y;

		for (int y = -1; y < 2; y++)
		{
			for (int x = -1; x < 2; x++)
			{
				std::shared_ptr<ABackGroundMap> Back = Grounds[GroundCount];

				Back->SetActorScale3D(UContentsValue::GroundTileSize);
				FIntPoint Point;
				Point.X = x;
				Point.Y = y;

				float4 Pos;
				Pos.X = UContentsValue::GroundTileSize.X * x;
				Pos.Y = UContentsValue::GroundTileSize.Y * y;

				Pos.X += UContentsValue::GroundTileSize.hX();
				Pos.Y += UContentsValue::GroundTileSize.hY();
				Back->SetActorLocation(Pos + MovePos);
				++GroundCount;
			}
		}

		CurIndex = Index;
	}
}

void APlayGameMode::MapSpawn()
{
	for (int y = -1; y < 2; y++)
	{
		for (int x = -1; x < 2; x++)
		{
			std::shared_ptr<ABackGroundMap> Back = GetWorld()->SpawnActor<ABackGroundMap>("BackGroundMap");

			Back->SetActorScale3D(UContentsValue::GroundTileSize);

			FIntPoint Point;
			Point.X = x;
			Point.Y = y;

			float4 Pos;
			Pos.X = UContentsValue::GroundTileSize.X * x;
			Pos.Y = UContentsValue::GroundTileSize.Y * y;

			Pos.X += UContentsValue::GroundTileSize.hX();
			Pos.Y += UContentsValue::GroundTileSize.hY();
			Back->SetActorLocation(Pos);

			Grounds.push_back(Back);

		}
	}
}

void APlayGameMode::UISpawn()
{
	HPBar = CreateWidget<UImage>(GetWorld(),"HPBar");
	HPBar->AddToViewPort(1);
	HPBar->SetSprite("HpBar.png");
	HPBar->SetScale({ 54.f,7.f });
	HPBar->SetPosition(FVector(0.f, -30.f));

	HPBarBack = CreateWidget<UImage>(GetWorld(), "HPBarBack");
	HPBarBack->AddToViewPort(0);
	HPBarBack->SetSprite("HpBar2.png");
	HPBarBack->SetScale({ 54.f,7.f });
	HPBarBack->SetPosition(FVector(0.f, -30.f));

	LevelBar = CreateWidget<UImage>(GetWorld(), "LevelBar");
	LevelBar->AddToViewPort(1);
	LevelBar->SetSprite("Level.png");
	LevelBar->SetScale(FVector(1270.f, 22.f));
	LevelBar->SetPosition(FVector(0.f, 344.f));
	LevelBar->SetPlusColor({ 0.2f,0.2f,0.5f,1.0f });

	LevelBarBack = CreateWidget<UImage>(GetWorld(), "LevelBarBack");
	LevelBarBack->AddToViewPort(0);
	LevelBarBack->SetSprite("LevelBar.png");
	LevelBarBack->SetScale(FVector(1280.f, 32.f));
	LevelBarBack->SetPosition(FVector(0.f, 344.f));

	for (int i = 0; i < 6; i++)
	{
		UImage* EquipTileBack = CreateWidget<UImage>(GetWorld(), "EquipTileBack");
		EquipTileBack->AddToViewPort(1);
		EquipTileBack->SetSprite("EquipedTile.png",0);
		EquipTileBack->SetScale(FVector(28.f, 28.f));
		EquipTileBack->SetPosition(FVector(-620.f + 32.f*i, 310.f));
		EquipTileBack->SetMulColor({ 1.f,1.f,1.f,0.7f });
		WeaponTilesBack.push_back(EquipTileBack);

		UImage* EquipTile = CreateWidget<UImage>(GetWorld(), "EquipTile");
		EquipTile->AddToViewPort(2);
		EquipTile->SetAutoSize(2.f,true);
		EquipTile->SetPosition(FVector(-620.f + 32.f * i, 310.f));
		EquipTile->SetActive(false);
		WeaponTiles.push_back(EquipTile);
	}

	for (int i = 0; i < 6; i++)
	{
		UImage* EquipTileBack = CreateWidget<UImage>(GetWorld(), "EquipTileBack");
		EquipTileBack->AddToViewPort(1);
		EquipTileBack->SetSprite("EquipedTile.png", 1);
		EquipTileBack->SetScale(FVector(28.f, 28.f));
		EquipTileBack->SetPosition(FVector(-620.f + 32.f * i, 278.f));
		EquipTileBack->SetMulColor({ 1.f,1.f,1.f,0.7f });
		AccessoryTilesBack.push_back(EquipTileBack);

		UImage* EquipTile = CreateWidget<UImage>(GetWorld(), "EquipTile");
		EquipTile->AddToViewPort(2);
		EquipTile->SetScale(FVector(28.f, 28.f));
		EquipTile->SetPosition(FVector(-620.f + 32.f * i, 278.f));
		EquipTile->SetActive(false);
		AccessoryTiles.push_back(EquipTile);
	}


	Gold = CreateWidget<UImage>(GetWorld(), "Gold");
	Gold->AddToViewPort(1);
	Gold->SetSprite("Gold.png");
	Gold->SetScale(FVector(18.f, 18.f));
	Gold->SetPosition(FVector(620.f, 315.f));
	Gold->SetPlusColor({ 0.2f,0.2f,0.2f });

	KillCount = CreateWidget<UImage>(GetWorld(), "KillCount");
	KillCount->AddToViewPort(1);
	KillCount->SetSprite("KillCount.png");
	KillCount->SetScale(FVector(12.f, 12.f));
	KillCount->SetPosition(FVector(400.f, 315.f));


	LevelVal = CreateWidget<UImage>(GetWorld(), "LevelVal");
}

void APlayGameMode::UIUpdate()
{
	UIHPUpdate();
	UILevelUpdate();
	WeaponTilesUpdate();
	AccessoryTilesUpdate();

}

void APlayGameMode::UIHPUpdate()
{
	FPlayerData PlayerData = UContentsValue::Player->GetPlayerDataCopy();
	float Ratio = PlayerData.Hp / PlayerData.MaxHealth;
	float Origin = 54.f;

	float Scale = Origin * Ratio;
	HPBar->SetScale({ Scale, HPBar->GetLocalScale().Y });

	float LeftX = (Origin - Scale) / 2.f;
	HPBar->SetPosition({ -LeftX ,-30.f });
}

void APlayGameMode::UILevelUpdate()
{
	FPlayerData PlayerData = UContentsValue::Player->GetPlayerDataCopy();
	float Ratio = PlayerData.CurExp / PlayerData.TargetExp;
	float Origin = 1270.f;

	float Scale = Origin * Ratio;
	LevelBar->SetScale({ Scale, LevelBar->GetLocalScale().Y });

	float LeftX = (Origin - Scale) / 2.f;
	LevelBar->SetPosition({ -LeftX ,344.f });
}

void APlayGameMode::WeaponTilesUpdate()
{
	int i = 0;
	for (std::pair<EWeapon, std::shared_ptr<UWeapon>> _Weapon : UEquipManager::Weapons)
	{
		WeaponTiles[i]->SetActive(true);

		switch (_Weapon.first)
		{
		case EWeapon::Axe:
			WeaponTiles[i]->SetSprite("AxeSprite.png");
			break;
		case EWeapon::Cross:
			WeaponTiles[i]->SetSprite("CrossSprite.png");
			break;
		case EWeapon::FireWand:
			WeaponTiles[i]->SetSprite("FireWandSprite.png");
			break;
		case EWeapon::Garlic:
			WeaponTiles[i]->SetSprite("GarlicSprite.png");
			break;
		case EWeapon::KingBible:
			WeaponTiles[i]->SetSprite("KingBibleSprite.png");
			break;
		case EWeapon::Knife:
			WeaponTiles[i]->SetSprite("KnifeSprite.png");
			break;
		case EWeapon::LightingRing:
			WeaponTiles[i]->SetSprite("LightingRingSprite.png");
			break;
		case EWeapon::MagicWand:
			WeaponTiles[i]->SetSprite("MagicWandSprite.png");
			break;
		case EWeapon::RuneTracer:
			WeaponTiles[i]->SetSprite("RuneTracerSprite.png");
			break;
		case EWeapon::SantaWater:
			WeaponTiles[i]->SetSprite("SantaWaterSprite.png");
			break;
		case EWeapon::Whip:
			WeaponTiles[i]->SetSprite("WhipSprite.png");
			break;
		default:
			break;
		}
		i++;
	}
}

void APlayGameMode::AccessoryTilesUpdate()
{
}

void APlayGameMode::LevelUpEvent()
{
}
