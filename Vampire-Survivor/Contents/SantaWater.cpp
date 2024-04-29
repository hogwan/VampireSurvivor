#include "PreCompile.h"
#include "SantaWater.h"
#include "SantaWaterCenter.h"
#include "Player.h"

FWeaponData USantaWater::Data = { "���� ������ �����մϴ�.",};

USantaWater::USantaWater() 
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("Root");
	TargetPoint = CreateDefaultSubObject<UDefaultSceneComponent>("TargetPoint");
	TargetPoint->SetupAttachment(Root);

	SetRoot(Root);
}

USantaWater::~USantaWater() 
{
}

void USantaWater::BeginPlay()
{
	Super::BeginPlay();
}

void USantaWater::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	SetActorLocation(UContentsValue::Player->GetActorLocation());
	TargetPoint->SetPosition(FVector::Right * 300.f);

	RotAround(_DeltaTime);

	if (IsLoop == false)
	{
		RemainTime -= _DeltaTime;
		if (RemainTime < 0.f)
		{
			RemainTime = Data.Cooldown;
			IsLoop = true;
		}
	}

	SpawnLoop(_DeltaTime);
}

void USantaWater::DataInit()
{
	Type = EWeapon::SantaWater;

	Data.Level = 1;
	OriginalData.Amount = 1;
	OriginalData.Penetration = 0;
	OriginalData.Damage = 10.f;
	OriginalData.Speed = 0.f;
	OriginalData.Duration = 2.f;
	OriginalData.Area = 1.f;
	OriginalData.Cooldown = 2.f;
	OriginalData.KnockbackPower = 100.f;
	OriginalData.ExplainText = "����ü �� 1 ����, ���ݹ��� 20% ����";

	RemainTime = OriginalData.Cooldown;
	RemainCount = OriginalData.Amount;
}

void USantaWater::LevelUp()
{
	int Level = ++Data.Level;
	switch (Level)
	{
	case 1:
		Data.Level = 1;
		OriginalData.Amount = 1;
		OriginalData.Penetration = 0;
		OriginalData.Damage = 10.f;
		OriginalData.Speed = 0.f;
		OriginalData.Duration = 2.f;
		OriginalData.Area = 1.f;
		OriginalData.Cooldown = 2.f;
		OriginalData.KnockbackPower = 100.f;
		OriginalData.ExplainText = "����ü �� 1 ����, ���ݹ��� 20% ����";
		break;
	case 2:
		++OriginalData.Amount;
		OriginalData.Area *= 1.2f;
		OriginalData.ExplainText = "���ݷ� 10����, ���ӽð� 0.5�� ����";
		break;
	case 3:
		OriginalData.Damage += 10.f;
		OriginalData.Duration += 0.5f;
		OriginalData.ExplainText = "����ü �� 1 ����, ���ݹ��� 20% ����";
		break;
	case 4:
		++OriginalData.Amount;
		OriginalData.Area *= 1.2f;
		OriginalData.ExplainText = "���ݷ� 10 ����, ���ӽð� 0.3�� ����";
		break;
	case 5:
		OriginalData.Damage += 10.f;
		OriginalData.Duration += 0.3f;
		OriginalData.ExplainText = "����ü �� 1 ����, ���ݹ��� 20% ����";
		break;
	case 6:
		++OriginalData.Amount;
		OriginalData.Area *= 1.2f;
		OriginalData.ExplainText = "���ݷ� 10 ����, ���ӽð� 0.3�� ����";
		break;
	case 7:
		OriginalData.Damage += 10.f;
		OriginalData.Duration += 0.3f;
		OriginalData.ExplainText = "���ݷ� 5 ����, ���ݹ��� 20% ����";
		break;
	case 8:
		OriginalData.Damage += 5.f;
		OriginalData.Duration += 0.3f;
		OriginalData.ExplainText = "�ִ� ���� ����";
		break;
	default:
		break;
	}
}

void USantaWater::RotAround(float _DeltaTime)
{
	AddActorRotation(FVector(0.f,0.f,RotSpeed * _DeltaTime));
} 

void USantaWater::SpawnCenter()
{
	std::shared_ptr<ASantaWaterCenter> SantaWaterCenter = GetWorld()->SpawnActor<ASantaWaterCenter>("Center");
	FVector TargetPos = TargetPoint->GetWorldPosition();
	SantaWaterCenter->SetTargetPos(TargetPoint->GetWorldPosition());
	--RemainCount;
}

void USantaWater::ApplyStatus(FPlayerData _Data)
{
	FWeaponData TempData;

	TempData.Amount = OriginalData.Amount + _Data.Amount;
	TempData.Damage = OriginalData.Damage * _Data.Might;
	TempData.Speed = OriginalData.Speed * _Data.Speed;
	TempData.Duration = OriginalData.Duration * _Data.Duration;
	TempData.Area = OriginalData.Area * _Data.Area;
	TempData.Cooldown = OriginalData.Cooldown * _Data.Cooldown;
	TempData.Penetration = OriginalData.Penetration;

	Data.Amount = TempData.Amount;
	Data.Damage = TempData.Damage;
	Data.Speed = TempData.Speed;
	Data.Duration = TempData.Duration;
	Data.Area = TempData.Area;
	Data.Cooldown = TempData.Cooldown;
	Data.Penetration = TempData.Penetration;
	RemainTime = Data.Cooldown;
}

void USantaWater::SpawnLoop(float _DeltaTime)
{
	if (IsLoop)
	{
		LoopRemainTime -= _DeltaTime;
		if (LoopRemainTime < 0.f)
		{
			LoopRemainTime = LoopTime;
			SpawnCenter();
		}

		if (RemainCount <= 0)
		{
			RemainCount = Data.Amount;
			IsLoop = false;
		}
	}

}
