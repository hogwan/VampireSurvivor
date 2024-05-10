#include "PreCompile.h"
#include "PlayGameMode.h"
#include "BackGroundMap.h"
#include "Player.h"
#include "SpawnerManager.h"
#include "EquipManager.h"
#include "ContentsEditerGUI.h"
#include <EngineCore/Image.h>
#include <EngineCore/Camera.h>
#include "UIManager.h"
#include "Chest.h"
#include "HealItem.h"
#include "AttractExpItem.h"
#include "FireItem.h"
#include <EngineCore/SpriteInstancingRender.h>

std::shared_ptr<UIManager> APlayGameMode::PlayUIManager;
std::shared_ptr<UEquipManager> APlayGameMode::EquipManager;

APlayGameMode::APlayGameMode()
{
}

APlayGameMode::~APlayGameMode()
{
}

void APlayGameMode::BeginPlay()
{
	Super::BeginPlay();
	
	GetWorld()->InstancingOn<USpriteInstancingRender>(ERenderOrder::Bat1);
	GetWorld()->InstancingOn<USpriteInstancingRender>(ERenderOrder::Bat2);
	GetWorld()->InstancingOn<USpriteInstancingRender>(ERenderOrder::Bat3);
	GetWorld()->InstancingOn<USpriteInstancingRender>(ERenderOrder::Flower);
	GetWorld()->InstancingOn<USpriteInstancingRender>(ERenderOrder::Ghost);
	GetWorld()->InstancingOn<USpriteInstancingRender>(ERenderOrder::Ghoul1);
	GetWorld()->InstancingOn<USpriteInstancingRender>(ERenderOrder::Ghoul2);
	GetWorld()->InstancingOn<USpriteInstancingRender>(ERenderOrder::Ghoul3);
	GetWorld()->InstancingOn<USpriteInstancingRender>(ERenderOrder::Mudman1);
	GetWorld()->InstancingOn<USpriteInstancingRender>(ERenderOrder::Mudman2);
	GetWorld()->InstancingOn<USpriteInstancingRender>(ERenderOrder::Mummy);
	GetWorld()->InstancingOn<USpriteInstancingRender>(ERenderOrder::Skeleton);
	GetWorld()->InstancingOn<USpriteInstancingRender>(ERenderOrder::SmallFlower);
	GetWorld()->InstancingOn<USpriteInstancingRender>(ERenderOrder::SmallMummy);
	GetWorld()->InstancingOn<USpriteInstancingRender>(ERenderOrder::Werewolf);
	GetWorld()->InstancingOn<USpriteInstancingRender>(ERenderOrder::XLBat);


	Camera = GetWorld()->GetMainCamera();

	std::shared_ptr<UEngineTexture> Tex = UEngineTexture::FindRes("BG_1.png");

	MapSpawn();

	Player = GetWorld()->SpawnActor<APlayer>("Player");
	UContentsValue::Player = Player;
	UContentsValue::StartPosition = Player->GetActorLocation();

	GetWorld()->SpawnActor<USpawnerManager>("SpawnerManager");
	EquipManager = GetWorld()->SpawnActor<UEquipManager>("EquipManager");
	PlayUIManager = GetWorld()->SpawnActor<UIManager>("UIManager");
	//EquipManager->EquipWeapon(EWeapon::Axe);
	//EquipManager->EquipWeapon(EWeapon::Cross);
	//EquipManager->EquipWeapon(EWeapon::FireWand);
	//EquipManager->EquipWeapon(EWeapon::Garlic);
	//EquipManager->EquipWeapon(EWeapon::KingBible);
	//EquipManager->EquipWeapon(EWeapon::Knife);
	//EquipManager->EquipWeapon(EWeapon::LightingRing);
	//EquipManager->EquipWeapon(EWeapon::MagicWand);
	//EquipManager->EquipWeapon(EWeapon::RuneTracer);
	//EquipManager->EquipWeapon(EWeapon::SantaWater);
	EquipManager->EquipWeapon(EWeapon::Whip);
	
	//EquipManager->EquipAccessory(EAccessory::Armor);
	//EquipManager->EquipAccessory(EAccessory::Attractorb);
	//EquipManager->EquipAccessory(EAccessory::Bracer);
	//EquipManager->EquipAccessory(EAccessory::Candelabrador);
	//EquipManager->EquipAccessory(EAccessory::Duplicator);
	//EquipManager->EquipAccessory(EAccessory::HollowHeart);
	//EquipManager->EquipAccessory(EAccessory::Clover);
	//EquipManager->EquipAccessory(EAccessory::EmptyTome);
	//EquipManager->EquipAccessory(EAccessory::Pummarola);
	//EquipManager->EquipAccessory(EAccessory::Wings);
	//EquipManager->EquipAccessory(EAccessory::Spinach);

	std::shared_ptr<Chest> Ch = GetWorld()->SpawnActor<Chest>("Chest");
	Ch->SetActorLocation(FVector(300.f, 0.f, 0.f));

	std::shared_ptr<HealItem> Heal = GetWorld()->SpawnActor<HealItem>("Heal");
	Heal->SetActorLocation(FVector(200.f, 0.f, 0.f));

	std::shared_ptr<AttractExpItem> Attract= GetWorld()->SpawnActor<AttractExpItem>("Attract");
	Attract->SetActorLocation(FVector(100.f, 0.f, 0.f));

	std::shared_ptr<FireItem> Fire = GetWorld()->SpawnActor<FireItem>("Attract");
	Fire->SetActorLocation(FVector(-100.f, 0.f, 0.f));
}

void APlayGameMode::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	Camera->SetActorLocation(Player->GetActorLocation() - FVector(0.f,0.f,1000.f));
	InfinityGroundCheck();
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


