#include "PreCompile.h"
#include "AttractExpItem.h"

AttractExpItem::AttractExpItem()
{
}

AttractExpItem::~AttractExpItem()
{
}

void AttractExpItem::BeginPlay()
{
	Super::BeginPlay();

	Renderer->CreateAnimation("Idle", "AttractItem", 0.1f, true);
	Renderer->SetAutoSize(2.f, true);
	Renderer->SetOrder(ERenderOrder::Exp);

	Collider->SetCollisionGroup(ECollisionOrder::Exp);
	Collider->SetCollisionType(ECollisionType::CirCle);
	Collider->SetScale(FVector(32.f, 32.f, 0.f));

	Renderer->ChangeAnimation("Idle");
}

void AttractExpItem::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	ColLogic();
}

void AttractExpItem::ColLogic()
{
	Collider->CollisionEnter(ECollisionOrder::Player, [=](std::shared_ptr<UCollision> _Collision)
		{
			UContentsValue::MaxMagnet = 100000.f;
			DelayCallBack(0.1f, [=]
				{
					UContentsValue::MaxMagnet = 0.f;
					Destroy();
				});
		}
	);
}
