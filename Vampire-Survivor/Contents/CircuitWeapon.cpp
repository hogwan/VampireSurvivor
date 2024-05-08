#include "PreCompile.h"
#include "CircuitWeapon.h"

CircuitWeapon::CircuitWeapon() 
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("Root");

	Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	Renderer->SetupAttachment(Root);


	SetRoot(Root);
}

CircuitWeapon::~CircuitWeapon() 
{
}

void CircuitWeapon::BeginPlay()
{
	Super::BeginPlay();
	//CircuitEffect = GetWorld()->GetLastTarget()->AddEffect<ACircuit>();
	Renderer->SetSprite("Chest.png");
	Renderer->SetAutoSize(1.f, true);
	Renderer->SetOrder(100);

	Renderer->SetMaterial("CircuitShader");
}

void CircuitWeapon::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	vec.X -= _DeltaTime * 0.015f;
	Renderer->SetVertexUVPlus(vec);
}



