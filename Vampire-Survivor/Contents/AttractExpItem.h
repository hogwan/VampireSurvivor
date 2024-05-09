#pragma once
#include "AttractItem.h"

class AttractExpItem :public AttractItem
{
	GENERATED_BODY(AttractItem);
public:

	AttractExpItem();
	~AttractExpItem();

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void ColLogic() override;
private:
};

