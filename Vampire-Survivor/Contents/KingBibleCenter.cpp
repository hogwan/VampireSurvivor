#include "PreCompile.h"
#include "KingBibleCenter.h"
#include "KingBible.h"

AKingBibleCenter::AKingBibleCenter()
{
	SetData(UKingBible::Data);
	PushInfo();
}

AKingBibleCenter::~AKingBibleCenter()
{
}

void AKingBibleCenter::BeginPlay()
{
	Super::BeginPlay();

	PushBible();
	UnitSpawnLogic();
	DelayCallBack(Data.Duration, [=] {
		DestroyBible();
		});
}

void AKingBibleCenter::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	RotateBible(_DeltaTime);
}

void AKingBibleCenter::BiblePosUpdate()
{
	for (int i = 0; i < Data.Amount; i++)
	{
		FVector Pos = PositionInfo[i]->GetWorldPosition();
		Bibles[i]->SetActorLocation(Pos);
	}
}

void AKingBibleCenter::RotateBible(float _DeltaTime)
{
	AddActorRotation(FVector(0.f, 0.f, Data.Speed * _DeltaTime));
	BiblePosUpdate();
}

void AKingBibleCenter::PosInit()
{
	for (int i = 0; i < Data.Amount; i++)
	{
		FVector Dir = FVector(0.f, -1.f, 0.f);
		Dir.RotationZToDeg((360.f / static_cast<float>(Data.Amount)) * static_cast<float>(i));
		PositionInfo[i]->SetPosition(Dir * Data.Area);
		int a = 0;
	}
}


void AKingBibleCenter::PushInfo()
{
	for (int i = 0; i < Data.Amount; i++)
	{
		UDefaultSceneComponent* Pos = CreateDefaultSubObject<UDefaultSceneComponent>("PosObject");
		Pos->SetupAttachment(Root);
		PositionInfo.push_back(Pos);
	}
}

void AKingBibleCenter::PushBible()
{
	for (int i = 0; i < Data.Amount; i++)
	{
		std::shared_ptr<AKingBibleUnit> Bible = GetWorld()->SpawnActor<AKingBibleUnit>("Bible");
		Bibles.push_back(Bible);
	}
}

void AKingBibleCenter::UnitSpawnLogic()
{
	UEngineSound::SoundPlay("book_01.wav");
	PosInit();
	BiblePosUpdate();
}

void AKingBibleCenter::DestroyBible()
{
	for (std::shared_ptr<AKingBibleUnit> Bible : Bibles)
	{
		Bible->Destroy();
	}

	Destroy();

}
