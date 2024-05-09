#include "PreCompile.h"
#include "FireUnit.h"
#include "Player.h"
#include "Enemy.h"
#include "DamageNumber.h"

FireUnit::FireUnit()
{
}

FireUnit::~FireUnit()
{
}

void FireUnit::BeginPlay()
{
	Super::BeginPlay();

	Renderer->SetSprite("FireEffect.png");
	Renderer->SetScale(FVector(50.f,50.f,10.f));
	Renderer->SetOrder(ERenderOrder::Particle);
	Renderer->SetMulColor(FVector(0.8f, 1.f, 1.f, 0.7f));

	Collider->SetCollisionGroup(ECollisionOrder::Exp);
	Collider->SetCollisionType(ECollisionType::CirCle);
	Collider->SetScale(FVector(50.f, 50.f, 0.f));

	DelayCallBack(1.f, [=]
		{
			Destroy();
		});
}

void FireUnit::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	ColLogic();

	Renderer->AddScale(FVector(100.f, 100.f, 0.f) * _DeltaTime);
	Collider->AddScale(FVector(100.f, 100.f, 0.f) * _DeltaTime);
	AddActorLocation(MoveVector * _DeltaTime);
}

void FireUnit::ColLogic()
{

	Collider->CollisionEnter(ECollisionOrder::Monster, [=](std::shared_ptr<UCollision> _Collision)
		{
			AEnemy* Opponent = dynamic_cast<AEnemy*>(_Collision->GetActor());

			Opponent->GetEnemyData().Hp -= DamageAmount;

			FVector EnemyPos = Opponent->GetActorLocation();
			std::shared_ptr<ADamageNumber> Damage = GetWorld()->SpawnActor<ADamageNumber>("Damage");
			Damage->SetDamage(DamageAmount);
			Damage->SetActorLocation(EnemyPos + FVector::Up * 10.f);
		}
	);
}
