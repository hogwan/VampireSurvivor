#include "PreCompile.h"
#include "GarlicUnit.h"
#include "Garlic.h"
#include "Enemy.h"
#include "Player.h"

AGarlicUnit::AGarlicUnit()
{
}

AGarlicUnit::~AGarlicUnit()
{
}

void AGarlicUnit::BeginPlay()
{
	Super::BeginPlay();

	Renderer->SetSprite("Garlic_0.png");
	Renderer->SetAutoSize(4.f, true);
	Renderer->SetOrder(ERenderOrder::Garlic);

	Collider->SetCollisionGroup(ECollisionOrder::PlayerWeapon);
	Collider->SetCollisionType(ECollisionType::RotRect);
	Collider->SetScale(Renderer->GetLocalScale());

	RootScale = GetActorScale3D();
	RootScale *= UGarlic::Data.Area;

	DelayCallBack(UGarlic::Data.Cooldown, [=]
		{
			Destroy();
		});
}

void AGarlicUnit::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	ColLogic();
	SetActorScale3D(RootScale);

	SetActorLocation(UContentsValue::Player->GetActorLocation());
}

void AGarlicUnit::ColLogic()
{
	Collider->CollisionEnter(ECollisionOrder::Monster, [=](std::shared_ptr<UCollision> _Collision)
		{
			AEnemy* Opponent = dynamic_cast<AEnemy*>(_Collision->GetActor());

			Opponent->GetEnemyData().Hp -= UGarlic::Data.Damage;
		}
	);
}
