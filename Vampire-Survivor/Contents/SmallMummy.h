#pragma once
#include "Enemy.h"

// Ό³Έν :
class ASmallMummy : public AEnemy
{
	GENERATED_BODY(AEnemy)
public:
	// constructor destructor
	ASmallMummy();
	~ASmallMummy();

	// delete Function
	ASmallMummy(const ASmallMummy& _Other) = delete;
	ASmallMummy(ASmallMummy&& _Other) noexcept = delete;
	ASmallMummy& operator=(const ASmallMummy& _Other) = delete;
	ASmallMummy& operator=(ASmallMummy&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
private:

};

