

float4x4 W;		// World matrix for object
float4x4 WVP;	// World * View * Projection matrix
float4 light;
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

	normal = normalize(mul(i.Normal, W).xyz);
	brightness = saturate(0.5 + dot(normal, (float3)light)*0.5-0.2);
	o.color = float4(1.0, 1.0, 1.0, 1.0)*brightness;//float4(brightness, brightness, brightness, 1.0);
	return o;
}
