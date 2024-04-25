#pragma once
#include <EngineCore/EngineDebugMsgWindow.h>

// Ό³Έν :
class ContentsEditerGUI : public UEngineDebugMsgWindow
{
	GENERATED_BODY(UEngineDebugMsgWindow)
public:
	// constructor destructor
	ContentsEditerGUI();
	~ContentsEditerGUI();

	// delete Function
	ContentsEditerGUI(const ContentsEditerGUI& _Other) = delete;
	ContentsEditerGUI(ContentsEditerGUI&& _Other) noexcept = delete;
	ContentsEditerGUI& operator=(const ContentsEditerGUI& _Other) = delete;
	ContentsEditerGUI& operator=(ContentsEditerGUI&& _Other) noexcept = delete;

protected:
	void Init() override;
	void OnGui(ULevel* Level, float _Delta) override;
private:

};

