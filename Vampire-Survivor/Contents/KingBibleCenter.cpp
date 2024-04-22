#include "PreCompile.h"
#include "KingBibleCenter.h"

AKingBibleCenter::AKingBibleCenter()
{
}

AKingBibleCenter::~AKingBibleCenter()
{
}

void AKingBibleCenter::BeginPlay()
{
	Super::BeginPlay();
	DataInit();
	PushBible();
	SpawnBible();
}

void AKingBibleCenter::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	RotateBible(_DeltaTime);
}

void AKingBibleCenter::DataInit()
{
	Data.Level = 1;
	Data.Amount = 1;
	Data.Penetration = -1;
	Data.Damage = 10.f;
	Data.Speed = 100.f;
	Data.Duration = 3.f;
	Data.Area = 100.f;
	Data.Cooldown = 3.f;
	Data.KnockbackPower = 100.f;
}

void AKingBibleCenter::LevelUp()
{
	int Level = ++Data.Level;

	switch (Level)
	{
	case 1:
		Data.Level = 1;
		Data.Amount = 1;
		Data.Penetration = -1;
		Data.Damage = 10.f;
		Data.Speed = 100.f;
		Data.Duration = 3.f;
		Data.Area = 100.f;
		Data.Cooldown = 3.f;
		Data.KnockbackPower = 100.f;
		break;
	case 2:
		++Data.Amount;
		PushBible();
		break;
	case 3:
		Data.Speed = Data.Speed * 1.3f;
		Data.Area = Data.Area * 1.25f;
		break;
	case 4:
		Data.Duration += 0.5f;
		Data.Damage += 10.f;
		break;
	case 5:
		++Data.Amount;
		PushBible();
		break;
	case 6:
		Data.Speed = Data.Speed * 1.3f;
		Data.Area = Data.Area * 1.25f;
		break;
	case 7:
		Data.Duration += 0.5f;
		Data.Damage += 10.f;
		break;
	case 8:
		++Data.Amount;
		PushBible();
		break;
	}
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
	SetActorRotation(FVector::Zero);
	for (int i = 0; i < Data.Amount; i++)
	{
		FVector Dir = FVector(0.f, -1.f, 0.f);
		Dir.RotationZToDeg(360 / Data.Amount);
		PositionInfo[i]->SetPosition(Dir * Data.Area);
	}
}


void AKingBibleCenter::PushBible()
{
	
	std::shared_ptr<UDefaultSceneComponent> Pos = GetWorld()->SpawnActor<UDefaultSceneComponent>("Pos");
	Pos->SetupAttachment(Root);
	PositionInfo.push_back(Pos);
	std::shared_ptr<AKingBible> Bible = nullptr;
	Bibles.push_back(Bible);
}

void AKingBibleCenter::SpawnBible()
{
	PosInit();

	for (std::shared_ptr<AKingBible> Bible: Bibles)
	{
		Bible = GetWorld()->SpawnActor<AKingBible>("Bible");
	}

	BiblePosUpdate();

	DelayCallBack(Data.Duration, [=] {
		DestroyBible();
		});
}

void AKingBibleCenter::DestroyBible()
{
	for (std::shared_ptr<AKingBible> Bible : Bibles)
	{
		Bible->Destroy();
		Bible = nullptr;
	}

	DelayCallBack(Data.Cooldown, [=] {
		SpawnBible();
		});
}
