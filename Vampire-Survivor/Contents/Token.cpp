#include "PreCompile.h"
#include "Token.h"

Token::Token() 
{
}

Token::~Token() 
{
}

void Token::BeginPlay()
{
	Super::BeginPlay();

	Renderer->SetSprite("Token.png");
	Renderer->SetAutoSize(2.f, true);
	Renderer->SetOrder(ERenderOrder::Item);

	Collider->SetCollisionGroup(ECollisionOrder::Exp);
	Collider->SetCollisionType(ECollisionType::CirCle);
	Collider->SetScale(FVector(32.f, 28.f, 0.f));
}

void Token::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}

void Token::ColLogic()
{
	Collider->CollisionEnter(ECollisionOrder::Player, [=](std::shared_ptr<UCollision> _Collision)
		{
			UContentsValue::Gold += 10;

			Destroy();
		}
	);
}
