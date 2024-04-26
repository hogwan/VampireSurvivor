#include "PreCompile.h"
#include "Exp.h"
#include "Player.h"

AExp::AExp() 
{
}

AExp::~AExp() 
{
}

void AExp::BeginPlay()
{
	Super::BeginPlay();
	Renderer->SetScale(FVector(18.f, 24.f, 0.f));
	Renderer->SetOrder(ERenderOrder::Exp);

	Collider->SetCollisionGroup(ECollisionOrder::Exp);
	Collider->SetCollisionType(ECollisionType::CirCle);
	Collider->SetScale(FVector(18.f, 24.f, 0.f));
}

void AExp::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	SpriteUpdate();
	ColLogic();
	if (AttractOn)
	{
		ChasePlayerLogic(_DeltaTime);
	}
	else
	{
		AttactCheckLogic();
	}
}

void AExp::AttactCheckLogic()
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

void AExp::ChasePlayerLogic(float _DeltaTime)
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

void AExp::ColLogic()
{
	Collider->CollisionEnter(ECollisionOrder::Player, [=](std::shared_ptr<UCollision> _Collision)
		{
			FPlayerData* Data = UContentsValue::Player->GetPlayerDataReference();

			Data->CurExp += ExpAmount;
			Destroy();
		}
	);
}

void AExp::SpriteUpdate()
{
	if (ExpAmount > 50.f)
	{
		Renderer->SetSprite("Exp.png", 2);
	}
	else if (ExpAmount > 5.f)
	{
		Renderer->SetSprite("Exp.png", 1);
	}
	else
	{
		Renderer->SetSprite("Exp.png", 0);
	}
}

