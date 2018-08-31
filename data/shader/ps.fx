float4 position;
float range;
float weight;
float4 angle;

struct PS_INPUT
{
	float4 world	: TEXCOORD0;	// vertex texture coords
	float4 color	: COLOR0;		// Pixel color    
};

struct PS_OUTPUT
{
	float4 color : COLOR0;  // Pixel color    
};

PS_OUTPUT pixel(PS_INPUT i)
{
	PS_OUTPUT o;
	float alpha;
	float dist = distance(position, i.world) - range;
	float2 direction = normalize(float2(i.world.x - position.x, i.world.z - position.z));
	float y = dot(float2(dist, (dist*dist - weight)), float2(-0.7071, -0.7071))/weight;
	alpha = step(0.7071,dot(angle.xz,direction))*saturate(y);
	o.color = i.color * (1 - alpha) + float4(1.0, 0.0, 0.7, 1.0) * alpha;
	return o;
}