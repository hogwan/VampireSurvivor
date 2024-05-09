#include "PreCompile.h"
#include "HealItem.h"
#include "Player.h"

HealItem::HealItem() 
{
}

HealItem::~HealItem() 
{
}

void HealItem::BeginPlay()
{
	Super::BeginPlay();
}

void HealItem::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	ColLogic();
}

void HealItem::ColLogic()
{
	Collider->CollisionEnter(ECollisionOrder::Player, [=](std::shared_ptr<UCollision> _Collision)
		{
			FPlayerData* Data = UContentsValue::Player->GetPlayerDataReference();

			Data->Hp += 30.f;
			if (Data->Hp > Data->MaxHealth)
			{
				Data->Hp = Data->MaxHealth;
			}

			Destroy();
		}
	);
}

