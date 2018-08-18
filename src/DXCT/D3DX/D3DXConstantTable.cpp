//
//		ƒtƒ@ƒCƒ‹–¼:D3DXConstantTable.cpp
//

#include "D3DXConstantTable.h"
#include "../D3D/D3DDevice.h"

namespace DXCT { namespace D3DX
{

D3DXConstantTable::D3DXConstantTable(ID3DXConstantTable * constantTable)
	:D3DObject(constantTable)
{

}

HRESULT D3DXConstantTable::SetFloat(std::shared_ptr<D3D::D3DDevice> device,char * name, float value)
{
	return _object->SetFloat(device->GetPtr(), name, value);
}

HRESULT D3DXConstantTable::SetFloatArray(std::shared_ptr<D3D::D3DDevice> device, char * name, float const * value, unsigned int count)
{
	return _object->SetFloatArray(device->GetPtr(), name, value, count);
}

HRESULT D3DXConstantTable::SetMatrix(std::shared_ptr<D3D::D3DDevice> device, char * name, D3DXMATRIX const * matrix)
{
	return _object->SetMatrix(device->GetPtr(), name, matrix);
}

}
}