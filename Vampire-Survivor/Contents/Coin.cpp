#include "PreCompile.h"
#include "Coin.h"

Coin::Coin() 
{
}

Coin::~Coin() 
{
}

void Coin::BeginPlay()
{
	Super::BeginPlay();

}

void Coin::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	GravityCheck(_DeltaTime);
	ReflectCheck();

	AddPosition(MoveVector * _DeltaTime);
}

void Coin::GravityCheck(float _DeltaTime)
{
	MoveVector += FVector::Down * Gravity;
}

void Coin::ReflectCheck()
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

