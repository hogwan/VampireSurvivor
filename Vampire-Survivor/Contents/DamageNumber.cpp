#include "PreCompile.h"
#include "DamageNumber.h"
#include "Number.h"

ADamageNumber::ADamageNumber() 
{
	Root = CreateDefaultSubObject<UDefaultSceneComponent>("Root");

	SetRoot(Root);
}

ADamageNumber::~ADamageNumber() 
{
}

void ADamageNumber::BeginPlay()
{
	Super::BeginPlay();

	DelayCallBack(DestroyTime, [=]
		{
			for (std::shared_ptr<ANumber> Num : Numbers)
			{
				Num->Destroy();
			}
			Destroy();
		});
}

void ADamageNumber::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

}

void ADamageNumber::SetDamage(float _Damage)
{
	Damage = static_cast<int>(_Damage);

	while (true)
	{
		int Number = Damage % 10;

		std::shared_ptr<ANumber> Num= GetWorld()->SpawnActor<ANumber>("Num");

		Num->GetRoot()->SetupAttachment(Root);
		Num->SetNum(Number);

		Numbers.push_back(Num);

		Damage /= 10;

		if (Damage == 0)
		{
			break;
		}
	}

	for (int i = Numbers.size()-1; i >= 0; i--)
	{
		Numbers[i]->GetRoot()->SetPosition(FVector(inter * static_cast<float>((Numbers.size() - 1 - i)), 0.f, 0.f));
	}
}



