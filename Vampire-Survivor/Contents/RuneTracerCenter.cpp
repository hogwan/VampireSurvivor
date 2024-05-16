#include "PreCompile.h"
#include "RuneTracerCenter.h"
#include "RuneTracer.h"
#include "RuneTracerUnit.h"
#include "Player.h"
#include "Enemy.h"

ARuneTracerCenter::ARuneTracerCenter()
{
}

ARuneTracerCenter::~ARuneTracerCenter()
{
}

void ARuneTracerCenter::BeginPlay()
{
	Super::BeginPlay();
	SetData(URuneTracer::Data);
	RemainTime = ShootTerm;
}

void ARuneTracerCenter::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	if (ShootCount == Data.Amount)
	{
		Destroy();
	}

	RemainTime -= _DeltaTime;
	if (RemainTime < 0.f)
	{
		RemainTime = ShootTerm;
		ShootLogic();
	}
}

void ARuneTracerCenter::ShootLogic()
{
	Target = UContentsValue::Player->GetNearestEnemy();
	if (Target == nullptr)
	{
		++ShootCount;
		return;
	}

	UEngineSound::SoundPlay("Projectile.wav");
	FVector DirVector = Target->GetActorLocation() - GetActorLocation();
	DirVector.Z = 0.f;
	DirVector.Normalize3D();

	std::shared_ptr<ARuneTracerUnit> Projectile = GetWorld()->SpawnActor<ARuneTracerUnit>("Projectile");
	Projectile->SetActorLocation(GetActorLocation());
	Projectile->SetMoveVector(DirVector * Data.Speed);

	if (DirVector.X >= 0)
	{
		Projectile->SetActorRotation(FVector(0.f, 0.f, DirVector.Y * 90.f));
	}
	else
	{
		Projectile->SetActorRotation(FVector(0.f, 0.f, 180 - (DirVector.Y * 90.f)));
	}

	++ShootCount;
}
