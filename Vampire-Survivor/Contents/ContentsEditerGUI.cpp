#include "PreCompile.h"
#include "ContentsEditerGUI.h"
#include "PlayGameMode.h"
#include "UIManager.h"
#include "Player.h"

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
	if (true == ImGui::Button("LevelUp"))
	{
		APlayGameMode::PlayUIManager->LevelUpEventStart();
		UContentsValue::Player->GetPlayerDataReference()->Level++;
	}

}

