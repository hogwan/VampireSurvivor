#include "PreCompile.h"
#include "ContentsEditerGUI.h"

ContentsEditerGUI::ContentsEditerGUI() 
{
}

ContentsEditerGUI::~ContentsEditerGUI() 
{
}

void ContentsEditerGUI::Init()
{
	Super::Init();
}

void ContentsEditerGUI::OnGui(ULevel* Level, float _Delta)
{
	Super::OnGui(Level, _Delta);

	if (true == ImGui::Button("DebugSwitch"))
	{
		GEngine->IsDebug = !GEngine->IsDebug;
	}

}

