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
    
    Out.TEXCOORD.x = _Input.TEXCOORD.x + PlusUV.x / 10000.f;
    Out.TEXCOORD.y = _Input.TEXCOORD.y + PlusUV.y / 10000.f;

    
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

    float scala = abs(_Input.TEXCOORD.x - 0.5f);
    
    if(scala < 0.1f)
    {
        Out.COLOR.a = 0.1f;
    }
    else if(scala < 0.15f)
    {
        Out.COLOR.a = 0.05f;
    }
    else if (scala < 0.2f)
    {
        Out.COLOR.a = 0.00f;
    }
    else if (scala < 0.25f)
    {
        Out.COLOR.a = 0.05f;
    }
    else if (scala < 0.3f)
    {
        Out.COLOR.a = 0.00f;
    }
    else if (scala < 0.35f)
    {
        Out.COLOR.a = -0.05f;
    }
    else if (scala < 0.4f)
    {
        Out.COLOR.a = -0.1f;
    }
    else if (scala < 0.45f)
    {
        Out.COLOR.a = -0.15f;
    }
    else if (scala < 0.5f)
    {
        Out.COLOR.a = -0.2f;
    }

    
    Out.COLOR.xyzw += PlusColor.xyzw;
    Out.COLOR.xyzw *= MulColor.xyzw;
    
    if(Out.COLOR.a < 0.f)
    {
        Out.COLOR.a = 0.f;
    }
    
    return Out;
}