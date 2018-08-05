//
//		ƒtƒ@ƒCƒ‹–¼:MeshRenderer.cpp
//

#include "MeshRenderer.h"
#include "../../Environment.h"

namespace GameEngine { namespace Behaviour
{

void MeshRenderer::Draw(D3DXMATRIX const & matrix)
{
	auto device = GameEngine::Environment::Get()->GetCurrentDevice();
	device->SetFVF(D3DFVF_XYZ | D3DFVF_NORMAL | D3DFVF_DIFFUSE);
	device->SetTransform(D3DTS_WORLD, &matrix);
	vertex[0] = { {    0.0f,  1.0f, 0.0f}	,{ 0.0f,0.0f,0.0f },D3DCOLOR_ARGB(255,255,255,255) };
	vertex[1] = { {  1.0f,   0.0f, 0.0f}	,{ 0.0f,0.0f,0.0f },D3DCOLOR_ARGB(255,255,255,255) };
	vertex[2] = { { -1.0f,   0.0f, 0.0f}	,{ 0.0f,0.0f,0.0f },D3DCOLOR_ARGB(255,255,255,255) };
	CalculateNormals();
	device->DrawPrimitiveUP(D3DPT_TRIANGLELIST, 1, vertex, sizeof(vertex[0]));
}

void MeshRenderer::CalculateNormals()
{
	D3DXVECTOR3 v1, v2,temp,normal;
	D3DXVec3Subtract(&v1, &D3DXVECTOR3(vertex[1].pos), &D3DXVECTOR3(vertex[0].pos));
	D3DXVec3Subtract(&v2, &D3DXVECTOR3(vertex[2].pos), &D3DXVECTOR3(vertex[0].pos));
	D3DXVec3Cross(&temp, &v1, &v2);
	D3DXVec3Normalize(&normal, &temp);
	for (int i = 0; i < 3; i++)
	{
		vertex[0].normal = normal;
	}
}

}
}