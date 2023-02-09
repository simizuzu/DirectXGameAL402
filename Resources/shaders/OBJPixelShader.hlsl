#include "OBJShaderHeader.hlsli"

Texture2D<float4> tex : register(t0); // 0番スロットに設定されたテクスチャ
SamplerState smp : register(s0); // 0番スロットに設定されたサンプラー

float4 main(VSOutput input) : SV_TARGET
{
	//float3 DirectionalLight = normalize(float3(1,-1,1)); // 右下奥　向きのライト
	//float DirectionalLight_diffuse = saturate(dot(-DirectionalLight, input.normal));
	//float3 shade_color;
	//shade_color = m_ambient; // アンビエント項
	//shade_color += m_diffuse * DirectionalLight_diffuse;	// ディフューズ項
	//float4 texcolor = tex.Sample(smp, input.uv);
	//return float4(texcolor.rgb * shade_color, texcolor.a * m_alpha);

	//float4 texcolor = tex.Sample(smp,input.uv);
	//return input.color * texcolor;
	
	// テクスチャマッピング
    float4 texcolor = tex.Sample(smp, input.uv);
	
	// シェーディングによる色
    float4 shadecolor;
	// 光沢度
    const float shininess = 4.0f;
	// 頂点から視点への方向ベクトル
    float3 eyedir = normalize(cameraPos - input.worldpos.xyz);
	// ライトに部下うベクトルと法線の内積
    float3 dotDirectionalLightnormal = dot(DirectionalLightv, input.normal);
	// 反射光ベクトル
    float3 reflect = normalize(-DirectionalLightv + 2 * dotDirectionalLightnormal * input.normal);
	// 環境反射光
    float3 ambient = m_ambient;
	// 拡散反射光
    float3 diffuse = dotDirectionalLightnormal * m_diffuse;
	// 鏡面反射光
    float3 specular = pow(saturate(dot(reflect, eyedir)), shininess) * m_specular;
	//　全て加算する
    shadecolor.rgb = (ambient + diffuse + specular) * DirectionalLightcolor;
    shadecolor.a = m_alpha;
	
	// シェーディングによる色で描画
    return shadecolor * texcolor;
}