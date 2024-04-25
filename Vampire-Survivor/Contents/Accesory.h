#pragma once
#include <EngineCore/Actor.h>

struct FAccesoryData
{
	int Level = 1;

	float MaxHealth = 0.f;
	float Recovery = 0.f;
	float Armor = 0.f;
	float MoveSpeed = 0.f;
	float Might = 0.f;
	float Speed = 0.f;
	float Duration = 0.f;
	float Area = 0.f;
	float Cooldown = 0.f;
	float Magnet = 0.f;
	float Luck = 0.f;
	float Growth = 0.f;
	float Greed = 0.f;
	float Curse = 0.f;

	int Amount = 0;
};

// Ό³Έν :
class UAccesory : public AActor
{
	GENERATED_BODY(AActor)
public:
	// constructor destructor
	UAccesory();
	~UAccesory();

	// delete Function
	UAccesory(const UAccesory& _Other) = delete;
	UAccesory(UAccesory&& _Other) noexcept = delete;
	UAccesory& operator=(const UAccesory& _Other) = delete;
	UAccesory& operator=(UAccesory&& _Other) noexcept = delete;

	virtual FAccesoryData GetData() = 0;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	virtual void DataInit() = 0;
	virtual void LevelUp() = 0;
private:

};

