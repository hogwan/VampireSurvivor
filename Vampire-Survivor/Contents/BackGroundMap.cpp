#include "PreCompile.h"
#include "BackGroundMap.h"

ABackGroundMap::ABackGroundMap()
{
	Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	SetRoot(Renderer);
}

ABackGroundMap::~ABackGroundMap()
{
}

void ABackGroundMap::BeginPlay()
{
	Super::BeginPlay();


	// ���ο��� ���÷��� ���� ã��
	Renderer->SetSprite("BG_1.png");
	Renderer->SetAutoSize(1.5f, true);
	Renderer->SetOrder(ERenderOrder::Back);
}

void ABackGroundMap::Tick(float _DeltaTime)
{
	// ���� ������ �ľ��Ҷ��� �ִ�.
	Super::Tick(_DeltaTime);
}