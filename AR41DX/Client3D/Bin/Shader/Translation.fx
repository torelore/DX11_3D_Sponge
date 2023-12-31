#include "Share.fx"

struct VS_INPUT_UV
{
    float3 Pos : POSITION;
    float2 UV : TEXCOORD;
};

struct VS_OUTPUT_UV
{
    float4 Pos : SV_POSITION;
    float2 UV : TEXCOORD;
};

cbuffer TranslationCBuffer : register(b6)
{
    float g_TextureTranslation;
    float3  g_TextureTranslationEmpty;
}

VS_OUTPUT_UV TranslationVS(VS_INPUT_UV input)
{
    VS_OUTPUT_UV output;

    output.Pos = mul(float4(input.Pos, 1.f), g_matWVP);

    output.UV = input.UV;

    return output;
}

float4 TranslationPS(VS_OUTPUT_UV input) : SV_TARGET
{
    float2 UV = input.UV + float2(g_TextureTranslation, 0.f);
    input.UV.x += g_TextureTranslation;

    return g_BaseTexture.Sample(g_LinearSmp, UV);
}
