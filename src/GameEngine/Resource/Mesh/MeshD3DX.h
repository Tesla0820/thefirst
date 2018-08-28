//
//		�t�@�C����:MeshD3DX.h
//

#ifndef HEADER_MESH_D3DX_H
#define HEADER_MESH_D3DX_H

#include <vector>
#include "../../GameEngine_inner.h"
#include "IMesh.h"

namespace GameEngine { namespace Resource { namespace Mesh
{

class MeshD3DX :public IMesh
{
	private:
		std::unique_ptr<D3DMATERIAL9[]> materials;
		
		DWORD NumMaterials;
		ID3DXMesh* Mesh;
	public:
		MeshD3DX(LPCTSTR pFilename);
		~MeshD3DX();

		// IMesh ����Čp������܂���
		virtual void Setup() override;
		virtual void Draw() override;
};

}
}
}

#endif