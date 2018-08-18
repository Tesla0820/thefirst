
float4 position;                  // World matrix for object
float range;
float weight;


struct PS_INPUT
{
	float4 WorldPosition	: TEXCOORD0;	// vertex texture coords 
	float4 Normal			: NORMAL0;		// vertex normal
	float4 color			: COLOR0;		// Pixel color    
};

struct PS_OUTPUT
{
	float4 color : COLOR0;  // Pixel color    
};

PS_OUTPUT pixel(PS_INPUT i)
{
	PS_OUTPUT o;
	float distSqr = distance(position, i.WorldPosition) - range;
	distSqr = distSqr * distSqr;
	o.color = lerp(float4(1.0, 0.0, 0.7, 1.0), float4(0.0, 0.0, 0.0, 1.0), (distSqr-weight) / weight);
	return o;
}