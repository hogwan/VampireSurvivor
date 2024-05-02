#pragma once
#include "Enemy.h"

// Ό³Έν :
class ASmallFlower : public AEnemy
{
	GENERATED_BODY(AEnemy)
public:
	// constructor destructor
	ASmallFlower();
	~ASmallFlower();

	// delete Function
	ASmallFlower(const ASmallFlower& _Other) = delete;
	ASmallFlower(ASmallFlower&& _Other) noexcept = delete;
	ASmallFlower& operator=(const ASmallFlower& _Other) = delete;
	ASmallFlower& operator=(ASmallFlower&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
private:

};

