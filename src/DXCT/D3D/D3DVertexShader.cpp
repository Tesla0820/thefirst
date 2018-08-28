#include "D3DDevice.h"
#include "D3DVertexShader.h"
namespace DXCT {
namespace D3D
{

D3DVertexShader::D3DVertexShader(IDirect3DVertexShader9 * shader, std::unique_ptr<D3DX::D3DXConstantTable> && constantTable)
	:D3DObject(shader), _constantTable(std::move(constantTable))
{
}

void D3DVertexShader::SetFloat(std::shared_ptr<D3D::D3DDevice> device, char * name, float value)
{
	_constantTable->SetFloat(device, name, value);
}

void D3DVertexShader::SetFloatArray(std::shared_ptr<D3D::D3DDevice> device, char * name, float const * value, unsigned int count)
{
	_constantTable->SetFloatArray(device, name, value, count);
}

void D3DVertexShader::SetMatrix(std::shared_ptr<D3D::D3DDevice> device,char * name, D3DXMATRIX const* matrix)
{
	_constantTable->SetMatrix(device, name, matrix);
}

}
}