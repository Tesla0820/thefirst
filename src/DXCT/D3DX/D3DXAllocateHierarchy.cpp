//
//		ファイル名:D3DXAllocateHierarchy.cpp
//

#include <string>
#include "D3DXAllocateHierarchy.h"

namespace DXCT { namespace D3DX
{
D3DXAllocateHierarchy::D3DXAllocateHierarchy()
{
}

D3DXAllocateHierarchy::~D3DXAllocateHierarchy()
{
}

//新たにメモリを確保して、文字列のディープコピーを行います。
void D3DXAllocateHierarchy::StringDeepCopy(LPSTR * dest, LPCSTR source)
{
	*dest = new CHAR[std::strlen(source) + 1]; //実サイズ分のメモリを確保
	std::strcpy(*dest, source);
}

//D3DXFRAME 用のメモリーを確保し、ディープコピーを行います。
HRESULT D3DXAllocateHierarchy::CreateFrame(LPCSTR pMesh, LPD3DXFRAME * ppNewFrame)
{
	D3DXFRAME *p = new D3DXFRAME;
	ZeroMemory(p, sizeof(D3DXFRAME));
	StringDeepCopy(&p->Name, pMesh);
	*ppNewFrame = p;
	return S_OK;
}

//D3DXMESHCONTAINER 用のメモリーを確保し、ディープコピーを行います。
HRESULT D3DXAllocateHierarchy::CreateMeshContainer(LPCSTR Name, D3DXMESHDATA const * pMeshData, D3DXMATERIAL const * pMaterials, D3DXEFFECTINSTANCE const * pEffectInstances, DWORD NumMaterials, DWORD const * pAdjacency, LPD3DXSKININFO pSkinInfo, LPD3DXMESHCONTAINER * ppNewMeshContainer)
{
	D3DXMESHCONTAINER *p;
	p = new D3DXMESHCONTAINER;
	ZeroMemory(p, sizeof(D3DXMESHCONTAINER));

	//メッシュデータの設定
	//メッシュタイプ別に取得、参照カウンタを増加
	p->MeshData.Type = pMeshData->Type;
	switch (pMeshData->Type)
	{
		case D3DXMESHTYPE_MESH:
			p->MeshData.pMesh = pMeshData->pMesh;
			pMeshData->pMesh->AddRef();
			break;
		case D3DXMESHTYPE_PMESH:
			p->MeshData.pPMesh = pMeshData->pPMesh;
			pMeshData->pPMesh->AddRef();
			break;
		case D3DXMESHTYPE_PATCHMESH:
			p->MeshData.pPatchMesh = pMeshData->pPatchMesh;
			pMeshData->pPatchMesh->AddRef();
		default:
			delete p;
			return E_FAIL;
	}
	StringDeepCopy(&p->Name, Name);

	//マテリアルデータの設定
	p->NumMaterials = NumMaterials;
	p->pMaterials = new D3DXMATERIAL[NumMaterials];
	for (int i = 0; i<NumMaterials; i++) {
		p->pMaterials[i].MatD3D = pMaterials[i].MatD3D;
		StringDeepCopy(&p->Name, pMaterials[i].pTextureFilename);
	}

	//エフェクトデータの設定
	p->pEffects = new D3DXEFFECTINSTANCE;
	StringDeepCopy(&p->pEffects->pEffectFilename, pEffectInstances->pEffectFilename);
	p->pEffects->NumDefaults = pEffectInstances->NumDefaults;
	p->pEffects->pDefaults = new D3DXEFFECTDEFAULT[pEffectInstances->NumDefaults];
	for (unsigned int i = 0; i < pEffectInstances->NumDefaults; i++)
	{
		DWORD bytes;
		bytes = p->pEffects->pDefaults[i].NumBytes = pEffectInstances->pDefaults[i].NumBytes;
		StringDeepCopy(&p->pEffects->pDefaults[i].pParamName, pEffectInstances->pDefaults[i].pParamName);
		p->pEffects->pDefaults[i].Type = pEffectInstances->pDefaults[i].Type;
		if (pEffectInstances->pDefaults[i].Type <= D3DXEDT_DWORD) {
			p->pEffects->pDefaults[i].pValue = new DWORD[bytes];
			memcpy(p->pEffects->pDefaults[i].pValue,pEffectInstances->pDefaults[i].pValue, bytes);
		}
	}

	//ポリゴンデータの設定
	DWORD primitives = pMeshData->pMesh->GetNumFaces();
	p->pAdjacency = new DWORD[primitives * 3];
	memcpy(p->pAdjacency, pAdjacency, primitives * 3 * sizeof(DWORD));
	
	//スキン情報の設定
	p->pSkinInfo = pSkinInfo;
	p->pSkinInfo->AddRef();
	
	//結果を返す
	*ppNewMeshContainer = p;
	return S_OK;
}

//確保した D3DXFRAME を解放します。
HRESULT D3DXAllocateHierarchy::DestroyFrame(LPD3DXFRAME pFrameToFree)
{
	LPD3DXFRAME &pFrame =pFrameToFree;
	SAFE_DELETE_ARRAY(pFrame->Name);
	
	if (pFrame->pMeshContainer)
	{
		DestroyMeshContainer(pFrame->pMeshContainer);
	}
	
	if (pFrame->pFrameSibling)
	{
		DestroyFrame(pFrame->pFrameSibling);
	}
	
	if (pFrame->pFrameFirstChild)
	{
		DestroyFrame(pFrame->pFrameFirstChild);
	}

	SAFE_DELETE(pFrame);

	return S_OK;
}

//確保した D3DXMESHCONTAINER を解放します。
HRESULT D3DXAllocateHierarchy::DestroyMeshContainer(LPD3DXMESHCONTAINER pMeshContainerToFree)
{
	LPD3DXMESHCONTAINER &pMeshContainer = pMeshContainerToFree;
	
	SAFE_DELETE_ARRAY(pMeshContainer->Name);
	
	//メッシュデータの解放
	switch (pMeshContainer->MeshData.Type)
	{
		case D3DXMESHTYPE_MESH:
			SAFE_RELEASE(pMeshContainer->MeshData.pMesh);
			break;
		case D3DXMESHTYPE_PMESH:
			SAFE_RELEASE(pMeshContainer->MeshData.pPMesh);
			break;
		case D3DXMESHTYPE_PATCHMESH:
			SAFE_RELEASE(pMeshContainer->MeshData.pPatchMesh);
	}
	
	//マテリアルデータの解放
	for (int i = 0; i<pMeshContainer->NumMaterials; i++) {
		SAFE_DELETE_ARRAY(pMeshContainer->pMaterials[i].pTextureFilename);
	}
	SAFE_DELETE_ARRAY(pMeshContainer->pMaterials);
	
	//エフェクトデータの解放
	for (int i = 0; i<pMeshContainer->pEffects->NumDefaults; i++) {
		SAFE_DELETE_ARRAY(pMeshContainer->pEffects->pDefaults[i].pParamName);
		SAFE_DELETE_ARRAY(pMeshContainer->pEffects->pDefaults[i].pValue);
	}
	SAFE_DELETE_ARRAY(pMeshContainer->pEffects->pEffectFilename);
	SAFE_DELETE_ARRAY(pMeshContainer->pEffects->pDefaults);
	SAFE_DELETE(pMeshContainer->pEffects);
	
	//ポリゴンデータの解放
	SAFE_DELETE_ARRAY(pMeshContainer->pAdjacency);
	
	//スキン情報を解放
	SAFE_RELEASE(pMeshContainer->pSkinInfo);
	
	SAFE_DELETE(pMeshContainer);
	return S_OK;
}

}
}