

float4x4 W;		// World matrix for object
float4x4 WVP;	// World * View * Projection matrix

struct VS_IN
{
	float4 Position			: POSITION0;	// vertex position
	float4 Normal			: NORMAL0;		// vertex normal 
};

struct VS_OUTPUT
{
	float4 Position			: SV_POSITION0;	// vertex position
	float4 Normal			: NORMAL0;		// vertex normal
	float4 WorldPosition	: TEXCOORD0;	// vertex texture coords
	float4 color			: COLOR0;
};


VS_OUTPUT vertex(VS_IN i)
{
	VS_OUTPUT o;
	o.Position = mul(i.Position, WVP);
	o.WorldPosition = mul(i.Position, W);
	o.Normal = normalize(mul(i.Normal, W));
	o.color = float4(1.0, 1.0, 1.0, 1.0);
	return o;
}
