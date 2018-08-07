//
//		�t�@�C����:D3DFactory.cpp
//

#include "D3DFactory.h"

namespace DXCT { namespace D3D 
{

D3DFactory::D3DFactory():D3DObject(Direct3DCreate9(DxctD3DSDKVersion))
{
}

//���A���������܂��B
void DXCT::D3D::D3DFactory::BackUp()
{
	D3DObject::BackUp();
}

//�f�o�C�X���X�g���畜�A���܂��B
void D3DFactory::Recovery()
{
	Recovery(nullptr);
}

void D3DFactory::Recovery(IRecoverable * origin)
{
	D3DObject::Recovery(origin);
}

//�w�肵���A�_�v�^�Ńf�o�C�X���쐬���܂��B
std::shared_ptr<D3DDevice> D3DFactory::CreateDevice(UINT adapter,D3DDEVTYPE devType, DXCT::Window *window,DWORD behaviorType,D3DPRESENT_PARAMETERS  *pp)
{
	IDirect3DDevice9 *device = nullptr;
	_object->CreateDevice(adapter, devType, window->GetHandle(), behaviorType, pp, &device);
	if (!device)
	{
		return std::shared_ptr <D3DDevice>();
	}
	return std::make_shared<D3DDevice>(device);
}

//�w�肵���A�_�v�^�̃f�o�C�X�^�C�v���g�p�\���m�F���܂��B
HRESULT D3DFactory::CheckDeviceType(UINT adapter, D3DDEVTYPE deviceType, D3DFORMAT displayFormat, D3DFORMAT backBufferFormat,BOOL isWindowed)
{
	return _object->CheckDeviceType(adapter, deviceType, displayFormat, backBufferFormat, isWindowed);
}

//�w�肵���A�_�v�^�̃f�B�X�v���C���[�h���擾���܂��B
HRESULT D3DFactory::GetAdapterDisplayMode(UINT adapter, D3DDISPLAYMODE * mode)
{
	return _object->GetAdapterDisplayMode(adapter, mode);
}

}
}