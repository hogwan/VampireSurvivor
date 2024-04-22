#include "PreCompile.h"
#include "VSCore.h"
#include "PlayGameMode.h"
#include <EngineCore/EngineSprite.h>

UVSCore::UVSCore()
{
}

UVSCore::~UVSCore()
{
}

void UVSCore::Initialize()
{
	{
		UEngineDirectory Dir;
		Dir.MoveToSearchChild("ContentsResources");
		Dir.Move("Image");
		std::vector<UEngineFile> Files = Dir.GetAllFile({ ".png" }, true);
		for (UEngineFile& File : Files)
		{
			UEngineSprite::Load(File.GetFullPath());
		}
		UEngineSprite::CreateCutting("Player.png", 4, 1);
		UEngineSprite::CreateCutting("BatIDLE.png", 4, 1);
	}


	{
		UEngineDirectory Dir;
		Dir.MoveToSearchChild("ContentsResources");
		Dir.Move("Sound");
		std::vector<UEngineFile> Files = Dir.GetAllFile({ ".wav" });
		for (UEngineFile& File : Files)
		{
			UEngineSound::Load(File.GetFullPath());
		}
	}

	GEngine->CreateLevel<APlayGameMode>("PlayLevel");
	GEngine->ChangeLevel("PlayLevel");

	
}