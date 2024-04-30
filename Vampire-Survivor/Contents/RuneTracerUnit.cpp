#include "PreCompile.h"
#include "RuneTracerUnit.h"
#include "RuneTracer.h"
#include "RuneTracerCenter.h"
#include "Enemy.h"
#include "Player.h"

ARuneTracerUnit::ARuneTracerUnit()
{
}

ARuneTracerUnit::~ARuneTracerUnit()
{
}

void ARuneTracerUnit::BeginPlay()
{
	Super::BeginPlay();
	Renderer->SetSprite("RunTracer_0.png");
	Renderer->SetAutoSize(2.f, true);
	Renderer->SetOrder(ERenderOrder::PlayerWeapon);

	Collider->SetCollisionGroup(ECollisionOrder::PlayerWeapon);
	Collider->SetCollisionType(ECollisionType::CirCle);
	Collider->SetScale(FVector(30.f, 30.f, 10.f));

	LiveTime = URuneTracer::Data.Duration;
}

void ARuneTracerUnit::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	
	LiveTime -= _DeltaTime;
	if (LiveTime <= 0)
	{
		Destroy();
	}

	ColLogic();
	ReflectLogic();
	AddActorLocation(MoveVector * _DeltaTime);
}

void ARuneTracerUnit::ColLogic()
{
	Collider->CollisionEnter(ECollisionOrder::Monster, [=](std::shared_ptr<UCollision> _Collision)
		{
			AEnemy* Opponent = dynamic_cast<AEnemy*>(_Collision->GetActor());

			Opponent->GetEnemyData().Hp -= URuneTracer::Data.Damage;
			Opponent->SetKnockBack(MoveVector.Normalize3DReturn() * URuneTracer::Data.KnockbackPower);
			Opponent->State.ChangeState("KnockBack");
		}
	);
}

void ARuneTracerUnit::ReflectLogic()
{
	FVector PlayerPos = UContentsValue::Player->GetActorLocation();
	FVector ScreenScale = GEngine->EngineWindow.GetWindowScale();

	float RightPos = PlayerPos.X + ScreenScale.X / 2.f;
	float LeftPos = PlayerPos.X - ScreenScale.X / 2.f;
	float TopPos = PlayerPos.Y + ScreenScale.Y / 2.f;
	float BottomPos = PlayerPos.Y - ScreenScale.Y / 2.f;

	FVector CurPos = GetActorLocation();

	if (CurPos.X > RightPos || CurPos.X < LeftPos)
	{
		MoveVector.X = -MoveVector.X;
		FVector Scale = Renderer->GetWorldScale();
	}

	if (CurPos.Y < BottomPos || CurPos.Y > TopPos)
	{
		MoveVector.Y = -MoveVector.Y;
		FVector Scale = Renderer->GetWorldScale();
	}

	FVector DirVector = MoveVector.Normalize3DReturn();
	if (MoveVector.X >= 0)
	{
		SetActorRotation(FVector(0.f, 0.f, DirVector.Y * 90.f));
	}
	else
	{
		SetActorRotation(FVector(0.f, 0.f, 180 - (DirVector.Y * 90.f)));
	}
}
