//
//		�t�@�C����:D3DTexture.cpp
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

//�f�o�C�X���X�g���畜�A���܂��B
void D3DTexture::Recovery(IRecoverable * origin)
{
	D3DObject::Recovery(origin);
}

}
}