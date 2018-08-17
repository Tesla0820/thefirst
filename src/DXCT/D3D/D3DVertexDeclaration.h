//
//		ƒtƒ@ƒCƒ‹–¼:D3DVertexDeclaration.h
//

#ifndef HEADER_D3DVERTEX_DECLARATION_H
#define HEADER_D3DVERTEX_DECLARATION_H

#include "../dxct_inner.h"
#include "D3DObject.h"

namespace DXCT { namespace D3D
{

class D3DVertexDeclaration:public D3DObject<IDirect3DVertexDeclaration9>
{
	private:
		D3DVertexDeclaration() = delete;


	public:
		D3DVertexDeclaration(IDirect3DVertexDeclaration9* vertexDeclaration);
};

}
}
#endif