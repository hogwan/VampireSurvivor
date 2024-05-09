#include "PreCompile.h"
#include "FireItem.h"
#include "FireCenter.h"

FireItem::FireItem()
{
}

FireItem::~FireItem()
{
}

void FireItem::BeginPlay()
{
	Super::BeginPlay();

	Renderer->CreateAnimation("Idle", "FireItem", 0.1f, true);
	Renderer->SetAutoSize(2.f, true);
	Renderer->SetOrder(ERenderOrder::Exp);

	Collider->SetCollisionGroup(ECollisionOrder::Exp);
	Collider->SetCollisionType(ECollisionType::CirCle);
	Collider->SetScale(FVector(32.f, 32.f, 0.f));

	Renderer->ChangeAnimation("Idle");
}

void FireItem::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	ColLogic();
}

void FireItem::ColLogic()
{
	Collider->CollisionEnter(ECollisionOrder::Player, [=](std::shared_ptr<UCollision> _Collision)
		{
			GetWorld()->SpawnActor<FireCenter>("FireCenter");
			Destroy();
		}
	);
}
