//
//		ファイル名:D3DFactory.cpp
//

#include "D3DFactory.h"

namespace DXCT { namespace D3D 
{

D3DFactory::D3DFactory():D3DObject(Direct3DCreate9(DxctD3DSDKVersion))
{
}

//復帰準備をします。
void DXCT::D3D::D3DFactory::BackUp()
{
	D3DObject::BackUp();
}

//デバイスロストから復帰します。
void D3DFactory::Recovery()
{
	Recovery(nullptr);
}

void D3DFactory::Recovery(IRecoverable * origin)
{
	D3DObject::Recovery(origin);
}

//指定したアダプタでデバイスを作成します。
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

//指定したアダプタのデバイスタイプを使用可能か確認します。
HRESULT D3DFactory::CheckDeviceType(UINT adapter, D3DDEVTYPE deviceType, D3DFORMAT displayFormat, D3DFORMAT backBufferFormat,BOOL isWindowed)
{
	return _object->CheckDeviceType(adapter, deviceType, displayFormat, backBufferFormat, isWindowed);
}

//指定したアダプタのディスプレイモードを取得します。
HRESULT D3DFactory::GetAdapterDisplayMode(UINT adapter, D3DDISPLAYMODE * mode)
{
	return _object->GetAdapterDisplayMode(adapter, mode);
}

}
}