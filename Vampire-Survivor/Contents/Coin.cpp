#include "PreCompile.h"
#include "Coin.h"

ACoin::ACoin() 
{
}

ACoin::~ACoin() 
{
}

void ACoin::BeginPlay()
{
	Super::BeginPlay();

}

void ACoin::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	GravityCheck(_DeltaTime);
	ReflectCheck();

	AddPosition(MoveVector * _DeltaTime);
}

void ACoin::GravityCheck(float _DeltaTime)
{
	MoveVector += FVector::Down * Gravity * _DeltaTime;
}

void ACoin::ReflectCheck()
{
	FVector CurPos = GetLocalPosition();

	if (CurPos.X > 640.f)
	{
		AddPosition(FVector::Left * 10.f);
		MoveVector.X = -MoveVector.X;
	}

	if (CurPos.X < -640.f)
	{
		AddPosition(FVector::Right * 10.f);
		MoveVector.X = -MoveVector.X;
	}
}

