//
//		�t�@�C����:D3DXAllocateHierarchy.cpp
//

#include <string>
#include "D3DXAllocateHierarchy.h"

namespace DXCT { namespace D3D
{
D3DXAllocateHierarchy::D3DXAllocateHierarchy()
{
}

D3DXAllocateHierarchy::~D3DXAllocateHierarchy()
{
}

//�V���Ƀ��������m�ۂ��āA������̃f�B�[�v�R�s�[���s���܂��B
void D3DXAllocateHierarchy::StringDeepCopy(LPSTR * dest, LPCSTR source)
{
	*dest = new CHAR[std::strlen(source) + 1]; //���T�C�Y���̃��������m��
	std::strcpy(*dest, source);
}

//D3DXFRAME �p�̃������[���m�ۂ��A�f�B�[�v�R�s�[���s���܂��B
HRESULT D3DXAllocateHierarchy::CreateFrame(LPCSTR pMesh, LPD3DXFRAME * ppNewFrame)
{
	D3DXFRAME *p = new D3DXFRAME;
	ZeroMemory(p, sizeof(D3DXFRAME));
	StringDeepCopy(&p->Name, pMesh);
	*ppNewFrame = p;
	return S_OK;
}

//D3DXMESHCONTAINER �p�̃������[���m�ۂ��A�f�B�[�v�R�s�[���s���܂��B
HRESULT D3DXAllocateHierarchy::CreateMeshContainer(LPCSTR Name, D3DXMESHDATA const * pMeshData, D3DXMATERIAL const * pMaterials, D3DXEFFECTINSTANCE const * pEffectInstances, DWORD NumMaterials, DWORD const * pAdjacency, LPD3DXSKININFO pSkinInfo, LPD3DXMESHCONTAINER * ppNewMeshContainer)
{
	D3DXMESHCONTAINER *p;
	p = new D3DXMESHCONTAINER;
	ZeroMemory(p, sizeof(D3DXMESHCONTAINER));

	//���b�V���f�[�^�̐ݒ�
	//���b�V���^�C�v�ʂɎ擾�A�Q�ƃJ�E���^�𑝉�
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

	//�}�e���A���f�[�^�̐ݒ�
	p->NumMaterials = NumMaterials;
	p->pMaterials = new D3DXMATERIAL[NumMaterials];
	for (int i = 0; i<NumMaterials; i++) {
		p->pMaterials[i].MatD3D = pMaterials[i].MatD3D;
		StringDeepCopy(&p->Name, pMaterials[i].pTextureFilename);
	}

	//�G�t�F�N�g�f�[�^�̐ݒ�
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

	//�|���S���f�[�^�̐ݒ�
	DWORD primitives = pMeshData->pMesh->GetNumFaces();
	p->pAdjacency = new DWORD[primitives * 3];
	memcpy(p->pAdjacency, pAdjacency, primitives * 3 * sizeof(DWORD));
	
	//�X�L�����̐ݒ�
	p->pSkinInfo = pSkinInfo;
	p->pSkinInfo->AddRef();
	
	//���ʂ�Ԃ�
	*ppNewMeshContainer = p;
	return S_OK;
}

//�m�ۂ��� D3DXFRAME ��������܂��B
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
//�m�ۂ��� D3DXMESHCONTAINER ��������܂��B
HRESULT D3DXAllocateHierarchy::DestroyMeshContainer(LPD3DXMESHCONTAINER pMeshContainerToFree)
{
	LPD3DXMESHCONTAINER &pMeshContainer = pMeshContainerToFree;
	
	SAFE_DELETE_ARRAY(pMeshContainer->Name);
	
	//���b�V���f�[�^�̉��
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
	
	//�}�e���A���f�[�^�̉��
	for (int i = 0; i<pMeshContainer->NumMaterials; i++) {
		SAFE_DELETE_ARRAY(pMeshContainer->pMaterials[i].pTextureFilename);
	}
	SAFE_DELETE_ARRAY(pMeshContainer->pMaterials);
	
	//�G�t�F�N�g�f�[�^�̉��
	for (int i = 0; i<pMeshContainer->pEffects->NumDefaults; i++) {
		SAFE_DELETE_ARRAY(pMeshContainer->pEffects->pDefaults[i].pParamName);
		SAFE_DELETE_ARRAY(pMeshContainer->pEffects->pDefaults[i].pValue);
	}
	SAFE_DELETE_ARRAY(pMeshContainer->pEffects->pEffectFilename);
	SAFE_DELETE_ARRAY(pMeshContainer->pEffects->pDefaults);
	SAFE_DELETE(pMeshContainer->pEffects);
	
	//�|���S���f�[�^�̉��
	SAFE_DELETE_ARRAY(pMeshContainer->pAdjacency);
	
	//�X�L���������
	SAFE_RELEASE(pMeshContainer->pSkinInfo);
	
	SAFE_DELETE(pMeshContainer);
	return S_OK;
}

}
}