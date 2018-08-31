//
//		�t�@�C����:MeshRenderer.cpp
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
	device->SetRenderState(D3DRS_CULLMODE, D3DCULL_CCW);				// �J�����O����
	device->SetRenderState(D3DRS_ZENABLE, TRUE);						// Z�o�b�t�@���g�p����
	device->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);				// ���u�����h���s��
	device->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);			// ���\�[�X�J���[�̎w��
	device->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);		// ���f�X�e�B�l�[�V�����J���[�̎w��
	device->SetFVF(D3DFVF_XYZ | D3DFVF_NORMAL);
	device->SetTransform(D3DTS_WORLD, &matrix);
	_mesh->Setup();
	Environment::Get()->OnBeforeRenderer(matrix);
	_mesh->Draw();
}

}
}