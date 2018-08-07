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

D3DTexture::~D3DTexture()
{

}

//デバイスロストから復帰します。
void D3DTexture::Recovery(IRecoverable * origin)
{
	D3DObject::Recovery(origin);
}

}
}