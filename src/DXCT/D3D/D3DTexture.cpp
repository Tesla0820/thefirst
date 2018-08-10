//
//		ファイル名:D3DTexture.cpp
//
#include "D3DTexture.h"

namespace DXCT { namespace D3D 
{


D3DTexture::D3DTexture(IDirect3DTexture9 * texture)
	: D3DObject(texture)
{

}

std::shared_ptr<D3DSurface> D3DTexture::GetSurfaceFromLevel(UINT level)
{
	HRESULT hr;
	IDirect3DSurface9 *surface;
	hr = _object->GetSurfaceLevel(level, &surface);
	if (SUCCEEDED(hr))
	{
		return std::shared_ptr<D3DSurface>(new D3DSurface(surface));
	}
	return std::shared_ptr<D3DSurface>();
}

//デバイスロストから復帰します。
void D3DTexture::Recovery(IRecoverable * origin)
{
	D3DObject::Recovery(origin);
}

}
}