#include "PreCompile.h"
#include "Torch.h"
#include "FireItem.h"
#include "AttractExpItem.h"
#include "HealItem.h"
#include "Token.h"
#include <EngineBase/EngineRandom.h>

Torch::Torch() 
{
}

Torch::~Torch() 
{
}

void Torch::BeginPlay()
{
	Super::BeginPlay();
	int min = static_cast<int>(EDropItemOrder::Attract);
	int max = static_cast<int>(EDropItemOrder::Coin);

	Random = static_cast<EDropItemOrder>(UEngineRandom::MainRandom.RandomInt(min, max));

	Renderer->CreateAnimation("Idle", "Torch", 0.1f, true);
	Renderer->SetAutoSize(2.f, true);
	Renderer->SetOrder(ERenderOrder::Item);

	Collider->SetCollisionGroup(ECollisionOrder::Exp);
	Collider->SetCollisionType(ECollisionType::CirCle);
	Collider->SetScale(FVector(32.f, 32.f, 0.f));

	Renderer->ChangeAnimation("Idle");

}

void Torch::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	ColLogic();
}

void Torch::ColLogic()
{
	Collider->CollisionEnter(ECollisionOrder::PlayerWeapon, [=](std::shared_ptr<UCollision> _Collision)
		{
			switch (Random)
			{
			case EDropItemOrder::Attract:
			{
				std::shared_ptr<AttractExpItem> AAttractItem = GetWorld()->SpawnActor<AttractExpItem>("AttractItem");
				AAttractItem->SetActorLocation(GetActorLocation());
				break;
			}
			case EDropItemOrder::Fire:
			{
				std::shared_ptr<FireItem> AFireItem = GetWorld()->SpawnActor<FireItem>("FireItem");
				AFireItem->SetActorLocation(GetActorLocation());
				break;
			}
			case EDropItemOrder::Heal:
			{
				std::shared_ptr<HealItem> AHealItem = GetWorld()->SpawnActor<HealItem>("Chicken");
				AHealItem->SetActorLocation(GetActorLocation());
				break;
			}
			case EDropItemOrder::Coin:
			{
				std::shared_ptr<Token> TokenItem = GetWorld()->SpawnActor<Token>("Token");
				TokenItem->SetActorLocation(GetActorLocation());
				break;
			}
			}
			Destroy();
		}
	);
}
