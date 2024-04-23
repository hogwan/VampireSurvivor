#include "PreCompile.h"
#include "WhipUnit.h"
#include "Player.h"
#include "Enemy.h"
#include "Whip.h"

AWhipUnit::AWhipUnit() 
{
}

AWhipUnit::~AWhipUnit() 
{
}

void AWhipUnit::BeginPlay()
{
	Super::BeginPlay();
	Renderer->SetSprite("Whip_0.png");
	Renderer->SetScale(InitialScale);
	Renderer->SetOrder(ERenderOrder::PlayerWeapon);
	Renderer->SetPosition(FVector(Renderer->GetLocalScale().X / 2.f, 0.f, 0.f));
	
	PlayerDir = UContentsValue::Player->GetSpriteDir();
	EEngineDir Dir = EEngineDir::MAX;
	if (PlayerDir == EEngineDir::Left)
	{
		Dir = EEngineDir::Right;
		Renderer->SetPosition(FVector(Renderer->GetLocalScale().X / 2.f, 0.f, 0.f));
	}
	else if (PlayerDir == EEngineDir::Right)
	{
		Dir = EEngineDir::Left;
		Renderer->SetPosition(FVector(-Renderer->GetLocalScale().X / 2.f, 0.f, 0.f));
	}
	Renderer->SetDir(Dir);

	Collider->SetCollisionGroup(ECollisionOrder::PlayerWeapon);
	Collider->SetCollisionType(ECollisionType::RotRect);

	DelayCallBack(DestroyTime, [=]
		{
			Destroy();
		});
}

void AWhipUnit::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	SetActorLocation(UContentsValue::Player->GetActorLocation());

	Collider->SetScale(Renderer->GetLocalScale());
	Collider->SetPosition(Renderer->GetLocalPosition());
	Collider->SetRotationDeg(Renderer->GetLocalRotation());

	ColLogic();
	IncreaseLogic(_DeltaTime);
}

void AWhipUnit::ColLogic()
{
	Collider->CollisionEnter(ECollisionOrder::Monster, [=](std::shared_ptr<UCollision> _Collision)
		{
			AEnemy* Opponent = dynamic_cast<AEnemy*>(_Collision->GetActor());

			Opponent->GetEnemyData().Hp -= UWhip::Data.Damage;
		}
	);
}

void AWhipUnit::IncreaseLogic(float _DeltaTime)
{
	FVector Gap = MaxScale - InitialScale;
	
	float XUp = (Gap.X / IncreaseTerm) * _DeltaTime;
	float YUp = (Gap.Y / IncreaseTerm) * _DeltaTime;

	if (PlayerDir == EEngineDir::Left)
	{
		Renderer->AddScale(FVector(XUp, YUp, 0.f));
	}
	else if (PlayerDir == EEngineDir::Right)
	{
		Renderer->AddScale(FVector(-XUp, YUp, 0.f));
	}


	
}


