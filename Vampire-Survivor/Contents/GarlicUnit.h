#pragma once
#include "VSObject.h"
class AGarlicUnit : public AVSObject
{
	GENERATED_BODY(AVSObject)
public:
	//constructer destructer
	AGarlicUnit();
	~AGarlicUnit();

	//delete Function
	AGarlicUnit(const AGarlicUnit& _Other) = delete;
	AGarlicUnit(AGarlicUnit&& _Other) noexcept = delete;
	AGarlicUnit& operator=(const AGarlicUnit& _Other) = delete;
	AGarlicUnit& operator=(AGarlicUnit&& _Other) noexcept = delete;
protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	FVector RootScale = FVector::Zero;

	void ColLogic();
private:

};