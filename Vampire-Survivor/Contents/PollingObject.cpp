#include "PreCompile.h"
#include "PollingObject.h"


APollingObject::APollingObject() 
{
}

APollingObject::~APollingObject() 
{
}

void APollingObject::ActiveOn()
{
	IsLive = true;
	Renderer->SetActive(true);
	Collider->SetActive(true);
	SetActive(true);
}

void APollingObject::ActiveOff()
{
	IsLive = false;
	Renderer->SetActive(false);
	Collider->SetActive(false);
	SetActive(false);
}

void APollingObject::BeginPlay()
{
	Super::BeginPlay();
}

void APollingObject::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}

