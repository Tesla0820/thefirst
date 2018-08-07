//
//		ファイル名:D3DFactory.h
//

#ifndef HEADER_D3DFACTORY_H
#define HEADER_D3DFACTORY_H

#include "../dxct_inner.h"
#include "D3DDevice.h"
#include "../Window.h"

namespace DXCT { namespace D3D 
{

constexpr UINT DxctD3DSDKVersion = D3D_SDK_VERSION;

//IDirect3D9のラッパークラスです。
class D3DFactory : public D3DObject<IDirect3D9>
{
	private:
	
	protected:
		virtual void Recovery(IRecoverable * origin) override;
	public:
		D3DFactory();
		void BackUp();
		void Recovery();
		std::shared_ptr<D3DDevice> CreateDevice(UINT adapter, D3DDEVTYPE devType, DXCT::Window *window, DWORD behaviorType, D3DPRESENT_PARAMETERS *pp);
		HRESULT CheckDeviceType(UINT adapter, D3DDEVTYPE deviceType, D3DFORMAT displayFormat, D3DFORMAT backBufferFormat, BOOL isWindowed);
		HRESULT GetAdapterDisplayMode(UINT adapter, D3DDISPLAYMODE *mode);
};

}
}

#endif