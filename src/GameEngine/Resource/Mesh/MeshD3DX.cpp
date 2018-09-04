//
//		ファイル名:MeshD3DX.cpp
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
		throw(std::runtime_error("メッシュの生成に失敗しました。"));
	}
	if (!(Mesh->GetFVF() & D3DFVF_NORMAL))
	{
		//法線情報が存在しない
		ID3DXMesh* temp;
		Mesh->CloneMeshFVF(Mesh->GetOptions(), Mesh->GetFVF() | D3DFVF_NORMAL, device->GetPtr(), &temp);
		D3DXComputeNormals(temp, NULL);

		Mesh->Release();
		Mesh = temp;
	}

	materials.reset( new D3DMATERIAL9[NumMaterials]);
	D3DXMATERIAL* d3dxMaterials = (D3DXMATERIAL*)Materials->GetBufferPointer();

	for (int i = 0; i < NumMaterials; i++)
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

	//頂点フォーマットをセット
	device->SetFVF(Mesh->GetFVF());
}


void MeshD3DX::Draw()
{
	IDirect3DDevice9* device;
	Mesh->GetDevice(&device);
	for (int i = 0; i < NumMaterials; i++) {
		device->SetMaterial(&materials[i]);
		//device->SetTexture(0, Textures[i]);
		Mesh->DrawSubset(i);
	}
}

}
}
}