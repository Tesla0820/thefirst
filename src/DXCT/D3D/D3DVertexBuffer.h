//
//		ファイル名:D3DVertexBuffer.h
//

#ifndef HEADER_D3DVERTEX_BUFFER_H
#define HEADER_D3DVERTEX_BUFFER_H

#include <memory>
#include "../dxct_inner.h"
#include "D3DObject.h"
namespace DXCT { namespace D3D
{

//IDirect3DDevice9のラッパークラスです。
class D3DVertexBuffer :public D3DObject<IDirect3DVertexBuffer9>
{
	private:
		D3DVertexBuffer() = delete;

	protected:
		virtual void Recovery(IRecoverable * origin) override;

	public:
		D3DVertexBuffer(IDirect3DVertexBuffer9* vertexBuffer);
};

}
}

#endif