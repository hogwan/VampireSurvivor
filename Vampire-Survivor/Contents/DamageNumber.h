#pragma once
#include <EngineCore/Actor.h>

// Ό³Έν :
class ADamageNumber : public AActor
{
	GENERATED_BODY(AActor)
public:
	// constructor destructor
	ADamageNumber();
	~ADamageNumber();

	// delete Function
	ADamageNumber(const ADamageNumber& _Other) = delete;
	ADamageNumber(ADamageNumber&& _Other) noexcept = delete;
	ADamageNumber& operator=(const ADamageNumber& _Other) = delete;
	ADamageNumber& operator=(ADamageNumber&& _Other) noexcept = delete;

	void SetDamage(float _Damage);

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	int Damage = 0;
	float inter = 20.f;
	float DestroyTime = 1.f;

	std::vector<std::shared_ptr<class ANumber>> Numbers;
	UDefaultSceneComponent* Root = nullptr;
private:

};

