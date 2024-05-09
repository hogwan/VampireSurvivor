#include "PreCompile.h"
#include "AttractItem.h"
#include "Player.h"

AttractItem::AttractItem() 
{
}

AttractItem::~AttractItem() 
{
}

void AttractItem::BeginPlay()
{
	Super::BeginPlay();
}

void AttractItem::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	if (AttractOn)
	{
		ChasePlayerLogic(_DeltaTime);
	}
	else
	{
		AttactCheckLogic();
	}
}

void AttractItem::ColLogic()
{
}

void AttractItem::AttactCheckLogic()
{
	FPlayerData PlayerData = UContentsValue::Player->GetPlayerDataCopy();

	FVector PlayerPos = UContentsValue::Player->GetActorLocation();
	FVector CurPos = GetActorLocation();
	PlayerPos.Z = 0.f;
	CurPos.Z = 0.f;

	float Distance = (PlayerPos - CurPos).Size3D();

	float Reach = 30.f + PlayerData.Magnet;

	if (Distance < Reach)
	{
		AttractOn = true;
	}
}

void AttractItem::ChasePlayerLogic(float _DeltaTime)
{
	FVector PlayerPos = UContentsValue::Player->GetActorLocation();
	FVector CurPos = GetActorLocation();
	PlayerPos.Z = 0.f;
	CurPos.Z = 0.f;

	FVector MoveDir = (PlayerPos - CurPos).Normalize3DReturn();

	Speed += Accel * _DeltaTime;
	MoveVector = MoveDir * Speed;

	AddActorLocation(MoveVector * _DeltaTime);
}
