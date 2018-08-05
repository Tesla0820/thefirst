//
//		ƒtƒ@ƒCƒ‹–¼:D3DTexture.h
//

#ifndef HEADER_D3D_TEXTURE_H
#define HEADER_D3D_TEXTURE_H

#include "../dxct_inner.h"
#include "D3DObject.h"

namespace DXCT { namespace D3D
{

class D3DTexture :public D3DObject<IDirect3DTexture9>
{
	private:
	D3DTexture() = delete;
	protected:
	virtual void Recovery(IRecoverable * origin) override;

	public:
	D3DTexture(IDirect3DTexture9 *texture);
	~D3DTexture();


};

}
}
#endif