#include "PreCompile.h"
#include "CircuitWeapon.h"

CircuitWeapon::CircuitWeapon() 
{
	
}

CircuitWeapon::~CircuitWeapon() 
{
}

void CircuitWeapon::BeginPlay()
{
	Super::BeginPlay();
	SetMaterial("CircuitShader");
	SetSprite("WeaponCircuit.png");
	SetAutoSize(2.1f, true);
	SetOrder(100);

}

void CircuitWeapon::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	UVVector += FVector::Up * 0.7f * _DeltaTime;

	SetVertexUVPlus(UVVector);
}



