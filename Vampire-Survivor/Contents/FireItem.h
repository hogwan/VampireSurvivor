#pragma once
#include "AttractItem.h"
class FireItem : public AttractItem
{
	GENERATED_BODY(AttractItem)
public:
	FireItem();
	~FireItem();

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void ColLogic() override;

private:

};

