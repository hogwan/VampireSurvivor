#pragma once
#include "WeaponCenter.h"
class AFireWandCenter : public AWeaponCenter
{
	GENERATED_BODY(AWeaponCenter)
public:
	//constructer destructer
	AFireWandCenter();
	~AFireWandCenter();

	//delete Function
	AFireWandCenter(const AFireWandCenter& _Other) = delete;
	AFireWandCenter(AFireWandCenter&& _Other) noexcept = delete;
	AFireWandCenter& operator=(const AFireWandCenter& _Other) = delete;
	AFireWandCenter& operator=(AFireWandCenter&& _Other) noexcept = delete;
protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void UnitSpawnLogic() override;
private:

};