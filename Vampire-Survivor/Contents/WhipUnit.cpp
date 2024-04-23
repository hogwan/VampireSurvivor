#include "PreCompile.h"
#include "WhipUnit.h"
#include "Player.h"

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

	EEngineDir PlayerDir = UContentsValue::Player->GetSpriteDir();
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


}

void AWhipUnit::Reposition()
{
	Renderer->SetPosition(FVector(Renderer->GetLocalScale().X / 2.f, 0.f, 0.f));

	if (Dir == EEngineDir::Left)
	{
		SetActorRotation(FVector(0.f, 0.f, 180.f));
	}
}

