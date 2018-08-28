//
//		ƒtƒ@ƒCƒ‹–¼:MeshRenderer.cpp
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
	device->SetFVF(D3DFVF_XYZ | D3DFVF_NORMAL);
	device->SetTransform(D3DTS_WORLD, &matrix);
	_mesh->Setup();
	Environment::Get()->OnBeforeRenderer(matrix);
	_mesh->Draw();
}

}
}