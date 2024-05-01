#include "PreCompile.h"
#include "VSObject.h"

AVSObject::AVSObject() 
{
	Root = CreateDefaultSubObject<UDefaultSceneComponent>("Root");
	
	Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	Renderer->SetupAttachment(Root);

	Collider = CreateDefaultSubObject<UCollision>("Collider");
	Collider->SetupAttachment(Root);

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
	DirCheck();
}

void AVSObject::DirCheck()
{
	FVector Scale = GetActorScale3D();
	float Scalar = fabs(Scale.X);
	if (SpriteDir == EEngineDir::Right)
	{
		Scale = FVector(-Scalar, Scale.Y, Scale.Z);
	}
	else
	{
		Scale = FVector(Scalar, Scale.Y, Scale.Z);
	}
	SetActorScale3D(Scale);
}

