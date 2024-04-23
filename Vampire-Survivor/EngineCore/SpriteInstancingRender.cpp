#include "PreCompile.h"
#include "SpriteInstancingRender.h"
#include "SpriteRenderer.h"
#include "EngineStructuredBuffer.h"

USpriteInstancingRender::USpriteInstancingRender() 
{
	SetMesh("Rect");
	SetMaterial("2DImageInstancing");
}

USpriteInstancingRender::~USpriteInstancingRender() 
{
}

void USpriteInstancingRender::InstancingDataCheck(URenderUnit* _Renderer, int _Count)
{
	USpriteRenderer* SpriteRenderer = dynamic_cast<USpriteRenderer*>(_Renderer);

	if (nullptr == SpriteRenderer)
	{
		MsgBoxAssert("��������Ʈ �������� �ƴ� ���縦 �ν��Ͻ� �Ҽ��� �����ϴ�.");
		return;
	}

	FTransform& Transform = SpriteRenderer->Transform;
	FCuttingData& CuttingData = SpriteRenderer->CuttingDataValue;
	FResultColorValue& ColorData = SpriteRenderer->ColorData;

	// ��Ʈ��ó�� ���ۿ� �׾��ַ���
	// �׷� �� ��Ʈ��ó�� ���� ���� �־�� 

	UEngineStructuredBufferSetter* TransInstancing = Resources->GetStructuredBuffer("TransInstancing");
	UEngineStructuredBufferSetter* CuttingDataInstancing = Resources->GetStructuredBuffer("CuttingDataInstancing");
	UEngineStructuredBufferSetter* ResultColorValueInstancing = Resources->GetStructuredBuffer("ResultColorValueInstancing");

	std::shared_ptr<UEngineStructuredBuffer> TransInstancingBuffer = TransInstancing->Res;
	std::shared_ptr<UEngineStructuredBuffer> CuttingDataInstancingBuffer = CuttingDataInstancing->Res;
	std::shared_ptr<UEngineStructuredBuffer> ResultColorValueInstancingBuffer = ResultColorValueInstancing->Res;

	//TransInstancingBuffer->PushData(Transform);
	//CuttingDataInstancingBuffer->PushData(CuttingData);
	//ResultColorValueInstancingBuffer->PushData(ColorData);
}