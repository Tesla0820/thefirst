#include "D3DDevice.h"
#include "D3DPixelShader.h"

namespace DXCT { namespace D3D
{

D3DPixelShader::D3DPixelShader(IDirect3DPixelShader9 * shader, std::unique_ptr<D3DX::D3DXConstantTable> && constantTable)
	:D3DObject(shader),_constantTable(std::move(constantTable))
{
}

void D3DPixelShader::SetFloat(std::shared_ptr<D3D::D3DDevice> device, char * name, float value)
{
	_constantTable->SetFloat(device, name, value);
}

void D3DPixelShader::SetFloatArray(std::shared_ptr<D3D::D3DDevice> device, char * name, float const * value, unsigned int count)
{
	_constantTable->SetFloatArray(device, name, value, count);
}

void D3DPixelShader::SetMatrix(std::shared_ptr<D3D::D3DDevice> device, char * name, D3DXMATRIX const * matrix)
{
	_constantTable->SetMatrix(device, name, matrix);
}

}
}