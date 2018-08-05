//
//		ƒtƒ@ƒCƒ‹–¼:D3DDevice.h
//

#ifndef HEADER_D3DDEVICE_H
#define HEADER_D3DDEVICE_H

#include <memory>
#include "../dxct_inner.h"
#include "D3DObject.h"
#include "D3DTexture.h"
namespace DXCT{ namespace D3D
{

class D3DDevice:public D3DObject<IDirect3DDevice9>
{
	private:
		D3DDevice() = delete;
	
	protected:
		virtual void Recovery(IRecoverable * origin) override;

	public:
		D3DDevice(IDirect3DDevice9 *device);

		D3DTexture* CreateTextureFromFile(LPCTSTR path);
		HRESULT SetRenderState(D3DRENDERSTATETYPE type, DWORD value);
		HRESULT SetSamplerState(DWORD sampler, D3DSAMPLERSTATETYPE type, DWORD value);
		HRESULT SetTextureStageState(DWORD stage, D3DTEXTURESTAGESTATETYPE type, DWORD value);
		HRESULT Clear(DWORD count, D3DRECT const* rects, DWORD flags, D3DCOLOR color, float z, DWORD stencil);
		HRESULT BeginScene();
		HRESULT EndScene();
		HRESULT Present(RECT const* sourceRect, RECT const* destRect, HWND destWindowOverride, RGNDATA const* dirtyRegion);
		HRESULT SetFVF(DWORD FVF);
		HRESULT SetTexture(DWORD stage, std::shared_ptr<D3DTexture> const &texture);
		HRESULT SetTransform(D3DTRANSFORMSTATETYPE state, D3DMATRIX const* pMatrix);
		HRESULT DrawPrimitiveUP(D3DPRIMITIVETYPE type, UINT primitiveCount, void* verticies, UINT vertexStride);
};

}
}

#endif