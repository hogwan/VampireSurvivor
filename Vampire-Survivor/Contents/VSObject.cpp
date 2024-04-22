#include "PreCompile.h"
#include "VSObject.h"

AVSObject::AVSObject() 
{
	Root = CreateDefaultSubObject<UDefaultSceneComponent>("Root");
	Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	Renderer->SetupAttachment(Root);
	SetRoot(Root);
}

AVSObject::~AVSObject() 
{
}

void AVSObject::BeginPlay()
{
	Super::BeginPlay();
}

void AVSObject::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}

