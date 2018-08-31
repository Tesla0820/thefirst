//
//		ファイル名:MeshRenderer.cpp
//

#include "MeshRenderer.h"
#include "../../Environment.h"
#include "../../GameObject.h"
#include "../Transform.h"

namespace GameEngine { namespace Behaviour
{

void MeshRenderer::SetMesh(std::shared_ptr<Resource::Mesh::IMesh> mesh)
{
	_mesh = mesh;
}

void MeshRenderer::Draw(D3DXMATRIX const & matrix)
{
	auto device = GameEngine::Environment::Get()->GetCurrentDevice();
	device->SetRenderState(D3DRS_CULLMODE, D3DCULL_CCW);				// カリングする
	device->SetRenderState(D3DRS_ZENABLE, TRUE);						// Zバッファを使用する
	device->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);				// αブレンドを行う
	device->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);			// αソースカラーの指定
	device->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);		// αデスティネーションカラーの指定
	device->SetFVF(D3DFVF_XYZ | D3DFVF_NORMAL);
	device->SetTransform(D3DTS_WORLD, &matrix);
	_mesh->Setup();
	Environment::Get()->OnBeforeRenderer(matrix);
	_mesh->Draw();
}

}
}