//
//		ƒtƒ@ƒCƒ‹–¼:D3DVertexShader.h
//

#ifndef HEADER_D3DVERTEX_SHADER_H
#define HEADER_D3DVERTEX_SHADER_H

#include "../dxct_inner.h"
#include "D3DObject.h"
#include "../D3DX/D3DXConstantTable.h"

namespace DXCT { namespace D3D
{

class D3DVertexShader:public D3DObject<IDirect3DVertexShader9>
{
	private:
		D3DVertexShader() = delete;
		std::unique_ptr<D3DX::D3DXConstantTable> _constantTable;
	public:
		D3DVertexShader(IDirect3DVertexShader9 * shader, std::unique_ptr<D3DX::D3DXConstantTable> && constantTable);
		void SetFloat(std::shared_ptr<D3D::D3DDevice> device, char* name, float value);
		void SetFloatArray(std::shared_ptr<D3D::D3DDevice> device, char* name, float const* value, unsigned int count);
		void SetMatrix(std::shared_ptr<D3D::D3DDevice> device, char * name, D3DXMATRIX const* matrix);
};

}
}
#endif