//
//		�t�@�C����:MeshD3DX.cpp
//
#include "MeshD3DX.h"
#include "../../Environment.h"
namespace GameEngine { namespace Resource { namespace Mesh
{

MeshD3DX::MeshD3DX(LPCTSTR pFilename)
{
	HRESULT hr;
	ID3DXBuffer* Materials;
	ID3DXBuffer* EffectInstances;

	auto device = GameEngine::Environment::Get()->GetCurrentDevice();
	hr = D3DXLoadMeshFromX(pFilename, D3DXMESH_VB_MANAGED, device->GetPtr(), NULL, &Materials, &EffectInstances, &NumMaterials, &Mesh);

	if (FAILED(hr))
	{
		throw(std::runtime_error("���b�V���̐����Ɏ��s���܂����B"));
	}

	if (!(Mesh->GetFVF() & D3DFVF_NORMAL))
	{
		//�@����񂪑��݂��Ȃ�
		ID3DXMesh* temp;
		Mesh->CloneMeshFVF(Mesh->GetOptions(), Mesh->GetFVF() | D3DFVF_NORMAL, device->GetPtr(), &temp);
		D3DXComputeNormals(temp, NULL);

		Mesh->Release();
		Mesh = temp;
	}

	materials.reset( new D3DMATERIAL9[NumMaterials]);
	D3DXMATERIAL* d3dxMaterials = (D3DXMATERIAL*)Materials->GetBufferPointer();

	for (DWORD i = 0; i < NumMaterials; i++)
	{
		materials[i] = d3dxMaterials[i].MatD3D;
	}

	Materials->Release();
	EffectInstances->Release();

}

MeshD3DX::~MeshD3DX()
{
	SAFE_RELEASE(Mesh);
	materials.reset();
}

void MeshD3DX::Setup()
{
	IDirect3DDevice9* device;
	Mesh->GetDevice(&device);

	//���_�t�H�[�}�b�g���Z�b�g
	device->SetFVF(Mesh->GetFVF());
}


void MeshD3DX::Draw()
{
	IDirect3DDevice9* device;
	Mesh->GetDevice(&device);
	for (DWORD i = 0; i < NumMaterials; i++)
	{
		device->SetMaterial(&materials[i]);
		Mesh->DrawSubset(i);
	}
}

}
}
}