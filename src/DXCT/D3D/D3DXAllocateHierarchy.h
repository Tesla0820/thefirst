//
//		ƒtƒ@ƒCƒ‹–¼:D3DXAllocateHierarchy.h
//

#ifndef HEADER_D3DXALLOCATE_HIERARCHY_H
#define HEADER_D3DXALLOCATE_HIERARCHY_H

#include "../dxct_inner.h"

namespace DXCT { namespace D3D
{

class D3DXAllocateHierarchy :ID3DXAllocateHierarchy
{
	private:
	void StringDeepCopy(LPSTR* dest,LPCSTR source);

	public:
	D3DXAllocateHierarchy();
	virtual ~D3DXAllocateHierarchy();
	virtual HRESULT __stdcall CreateFrame(LPCSTR pMesh, LPD3DXFRAME *ppNewFrame) override;
	virtual HRESULT __stdcall CreateMeshContainer(
		LPCSTR Name, D3DXMESHDATA const *pMeshData,
		D3DXMATERIAL const *pMaterials, D3DXEFFECTINSTANCE const *pEffectInstances,
		DWORD NumMaterials, DWORD const *pAdjacency,
		LPD3DXSKININFO pSkinInfo, LPD3DXMESHCONTAINER *ppNewMeshContainer) override;
	virtual HRESULT __stdcall DestroyFrame(LPD3DXFRAME pFrameToFree) override;
	virtual	HRESULT __stdcall DestroyMeshContainer(LPD3DXMESHCONTAINER pMeshContainerToFree);
};

}
}

#endif