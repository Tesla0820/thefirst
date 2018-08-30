

float4x4 W;		// World matrix for object
float4x4 WVP;	// World * View * Projection matrix
float3 light;
float rate;
struct VS_IN
{
	float4 Position			: POSITION0;	// vertex position
	float4 Normal			: NORMAL0;		// vertex normal 
};

struct VS_OUTPUT
{
	float4 Position			: SV_POSITION0;	// vertex position
	float4 WorldPosition	: TEXCOORD0;	// vertex texture coords
	float4 color			: COLOR0;
};


VS_OUTPUT vertex(VS_IN i)
{
	float3 normal;
	float brightness;
	VS_OUTPUT o;
	o.Position = mul(i.Position, WVP);
	o.WorldPosition = mul(i.Position, W);

	normal = normalize(mul(i.Normal.xyz, (float3x3)W));
	brightness = saturate(0.5 + dot(normal, light)*0.5-0.2);
	o.color = lerp(float4(brightness, brightness, brightness, 1.0),float4(1.0, 0.0, 0.7, 1.0),rate);//float4(brightness, brightness, brightness, 1.0);
	return o;
}
