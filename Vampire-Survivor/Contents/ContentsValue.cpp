#include "PreCompile.h"
#include "ContentsValue.h"

const float4 UContentsValue::GroundTileSize = { 1536.0f, 1536.0f };
std::shared_ptr<class APlayer> UContentsValue::Player;
FVector UContentsValue::StartPosition;
int UContentsValue::KillCount = 0;
int UContentsValue::Gold = 0;
int UContentsValue::MaxLevel = 75;
int UContentsValue::PlayerLevel = 1;
float UContentsValue::Time = 0.f;
float UContentsValue::MaxMagnet = 0.f;
UEngineSoundPlayer UContentsValue::MainBGM;