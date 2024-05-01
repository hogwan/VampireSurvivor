#include "PreCompile.h"
#include "ContentsValue.h"

const float4 UContentsValue::GroundTileSize = { 1536.0f, 1536.0f };
std::shared_ptr<class APlayer> UContentsValue::Player;
FVector UContentsValue::StartPosition;
int UContentsValue::KillCount = 0;
int UContentsValue::Gold = 0;
int UContentsValue::MaxLevel = 75;
float UContentsValue::Time = 0.f;