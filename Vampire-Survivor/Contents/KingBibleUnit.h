#pragma once
#include "VSObject.h"
class AKingBibleUnit : public AVSObject
{
	GENERATED_BODY(AVSObject)
public:
	//constructer destructer
	AKingBibleUnit();
	~AKingBibleUnit();

	//delete Function
	AKingBibleUnit(const AKingBibleUnit& _Other) = delete;
	AKingBibleUnit(AKingBibleUnit&& _Other) noexcept = delete;
	AKingBibleUnit& operator=(const AKingBibleUnit& _Other) = delete;
	AKingBibleUnit& operator=(AKingBibleUnit&& _Other) noexcept = delete;
protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void ColLogic();

private:

};