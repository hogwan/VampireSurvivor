#pragma once
#include <EngineCore/EngineRenderTarget.h>
// Ό³Έν :
class USpriteRenderer;
class ACircuit : public UEffect
{
	GENERATED_BODY(UEffect)
public:
	// constructor destructor
	ACircuit();
	~ACircuit();

	// delete Function
	ACircuit(const ACircuit& _Other) = delete;
	ACircuit(ACircuit&& _Other) noexcept = delete;
	ACircuit& operator=(const ACircuit& _Other) = delete;
	ACircuit& operator=(ACircuit&& _Other) noexcept = delete;

	void Init() override;
	void Effect(std::shared_ptr<UEngineRenderTarget> EffectTarget) override;
protected:
private:
	std::shared_ptr<UEngineRenderTarget> CopyTarget;
	USpriteRenderer* Renderer = nullptr;
	bool set = false;
};

