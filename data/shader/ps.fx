float4 position;
float range;
float weight;

struct PS_INPUT
{
	float4 WorldPosition	: TEXCOORD0;	// vertex texture coords
	float4 color			: COLOR0;		// Pixel color    
};

struct PS_OUTPUT
{
	float4 color : COLOR0;  // Pixel color    
};

PS_OUTPUT pixel(PS_INPUT i)
{
	PS_OUTPUT o;
	float alpha;
	float distSqr = distance(position, i.WorldPosition) - range;
	distSqr = distSqr * distSqr;
	alpha = saturate(-(distSqr - weight) / weight);
	o.color = i.color * (1 - alpha) + float4(1.0, 0.0, 0.7, 1.0) * alpha;
	return o;
}