#include "PreCompile.h"
#include "Chest.h"
#include "Player.h"
#include "ChestUI.h"
#include "UIManager.h"

Chest::Chest() 
{
}

Chest::~Chest() 
{
}

void Chest::BeginPlay()
{
	Super::BeginPlay();

	Renderer->SetSprite("ChestDrop.png");
	Renderer->SetAutoSize(2.f, true);
	Renderer->SetOrder(ERenderOrder::Item);

	Collider->SetCollisionGroup(ECollisionOrder::Exp);
	Collider->SetCollisionType(ECollisionType::CirCle);
	Collider->SetScale(FVector(36.f, 32.f, 0.f));
}

void Chest::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	ColLogic();
}

void Chest::ColLogic()
{
	Collider->CollisionEnter(ECollisionOrder::Player, [=](std::shared_ptr<UCollision> _Collision)
		{
			UIManager::ChestUI->EventStart();
			Destroy();
		}
	);
}
