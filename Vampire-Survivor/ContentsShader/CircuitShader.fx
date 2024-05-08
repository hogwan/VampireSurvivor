#include "ContentShaderBase.hlsli"

struct ImageVSOutPut
{
    float4 POSITION : SV_POSITION;
    float4 TEXCOORD : TEXCOORD;
};

cbuffer FCuttingData : register(b2)
{
    float4 CuttingPosition;
    float4 CuttingSize;
    float4x4 PivotMat;
};

cbuffer FVertexUV : register(b3)
{
    float4 PlusUV;
};


struct ImagePSOutPut
{
    float4 COLOR : SV_Target0;
};


ImageVSOutPut CircuitShader_VS(FEngineVertex _Input)
{
    ImageVSOutPut Out = (ImageVSOutPut) 0;

    float4x4 PivotWorld = mul(World, PivotMat);
    
    Out.POSITION = mul(_Input.POSITION, PivotWorld);
    Out.POSITION = mul(Out.POSITION, View);
    Out.POSITION = mul(Out.POSITION, Projection);
    
    Out.TEXCOORD.x = (_Input.TEXCOORD.x * CuttingSize.x) + CuttingPosition.x;
    Out.TEXCOORD.y = (_Input.TEXCOORD.y * CuttingSize.y) + CuttingPosition.y;
    
    Out.TEXCOORD.x += CuttingSize.x * PlusUV.x;
    Out.TEXCOORD.y += CuttingSize.y * PlusUV.y;

    return Out;
}

TextureSet(Image, 0)

cbuffer ResultColorValue : register(b10)
{
    float4 PlusColor;
    float4 MulColor;
    float4 AlphaColor;
};


ImagePSOutPut CircuitShader_PS(ImageVSOutPut _Input)
{

    ImagePSOutPut Out = (ImagePSOutPut) 0;

    Out.COLOR = Sampling(Image, _Input.TEXCOORD);
    Out.COLOR.xyz += PlusColor.xyz;
    Out.COLOR.xyzw *= MulColor.xyzw;

    return Out;
}