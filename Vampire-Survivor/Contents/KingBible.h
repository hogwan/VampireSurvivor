#pragma once
#include "VSObject.h"
class AKingBible : public AVSObject
{
	GENERATED_BODY(AVSObject)
public:
	//constructer destructer
	AKingBible();
	~AKingBible();

	//delete Function
	AKingBible(const AKingBible& _Other) = delete;
	AKingBible(AKingBible&& _Other) noexcept = delete;
	AKingBible& operator=(const AKingBible& _Other) = delete;
	AKingBible& operator=(AKingBible&& _Other) noexcept = delete;
protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void ColLogic();

private:

};