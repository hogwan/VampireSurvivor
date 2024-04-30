#include "PreCompile.h"
#include "CrossUnit.h"
#include "Cross.h"
#include "Enemy.h"
#include "Player.h"

ACrossUnit::ACrossUnit()
{
}

ACrossUnit::~ACrossUnit()
{
}

void ACrossUnit::BeginPlay()
{
	Super::BeginPlay();

	Renderer->SetSprite("Cross_0.png");
	Renderer->SetAutoSize(2.f, true);
	Renderer->SetOrder(ERenderOrder::PlayerWeapon);

	Collider->SetCollisionGroup(ECollisionOrder::PlayerWeapon);
	Collider->SetCollisionType(ECollisionType::RotRect);
	Collider->SetScale(FVector(32.f, 36.f, 10.f));
}

void ACrossUnit::Tick(float _DeltaTime)
{
	Super::BeginPlay();

	Release();

	ColLogic();

	if (MoveVector.X < 0)
	{
		AddActorRotation(FVector(0.f, 0.f, RotationSpeed * _DeltaTime));
	}
	else
	{
		AddActorRotation(FVector(0.f, 0.f, -RotationSpeed * _DeltaTime));
	}


	MoveVector += ReverseVector * ReverseVectorForce * _DeltaTime;

	AddActorLocation(MoveVector * _DeltaTime);
}

void ACrossUnit::ColLogic()
{
	Collider->CollisionEnter(ECollisionOrder::Monster, [=](std::shared_ptr<UCollision> _Collision)
		{
			AEnemy* Opponent = dynamic_cast<AEnemy*>(_Collision->GetActor());

			Opponent->GetEnemyData().Hp -= UCross::Data.Damage;
			Opponent->SetKnockBack(MoveVector.Normalize3DReturn() * UCross::Data.KnockbackPower);
			Opponent->State.ChangeState("KnockBack");
		}
	);
}

void ACrossUnit::Release()
{
	FVector PlayerPos = UContentsValue::Player->GetActorLocation();
	FVector CurPos = GetActorLocation();

	PlayerPos.Z = 0;
	CurPos.Z = 0;

	float Distance = (PlayerPos - CurPos).Size3D();
	if (Distance > 1500.f)
	{
		Destroy();
	}
}
