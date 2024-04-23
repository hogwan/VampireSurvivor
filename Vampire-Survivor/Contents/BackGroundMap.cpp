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


	// 내부에서 샘플러도 같이 찾을
	Renderer->SetSprite("BG_1.png");
	Renderer->SetAutoSize(1.5f, true);
	Renderer->SetOrder(ERenderOrder::Back);
}

void ABackGroundMap::Tick(float _DeltaTime)
{
	// 위에 뭔가를 쳐야할때도 있다.
	Super::Tick(_DeltaTime);
}