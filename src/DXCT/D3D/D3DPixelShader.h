//
//		ƒtƒ@ƒCƒ‹–¼:D3DPixelShader.h
//

#ifndef HEADER_D3DPIXEL_SHADER_H
#define HEADER_D3DPIXEL_SHADER_H

#include "../dxct_inner.h"
#include "D3DObject.h"
#include "../D3DX/D3DXConstantTable.h"

namespace DXCT { namespace D3D
{

class D3DPixelShader:public D3DObject<IDirect3DPixelShader9>
{
	private:
		D3DPixelShader() = delete;
		std::unique_ptr<D3DX::D3DXConstantTable> _constantTable;
	public:
		D3DPixelShader(IDirect3DPixelShader9 * shader, std::unique_ptr<D3DX::D3DXConstantTable> && constantTable);
		void SetFloat(std::shared_ptr<D3D::D3DDevice> device, char* name, float value);
		void SetFloatArray(std::shared_ptr<D3D::D3DDevice> device, char* name, float const* value, unsigned int count);
		void SetMatrix(std::shared_ptr<D3D::D3DDevice> device, char * name, D3DXMATRIX const* matrix);
};

}
}
#endif