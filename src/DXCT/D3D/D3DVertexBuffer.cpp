#include "D3DVertexBuffer.h"

namespace DXCT { namespace D3D
{

D3DVertexBuffer::D3DVertexBuffer(IDirect3DVertexBuffer9 * vertexBuffer)
	:D3DObject(vertexBuffer)
{
}

void D3DVertexBuffer::Recovery(IRecoverable * origin)
{
}


}
}