//
//		ƒtƒ@ƒCƒ‹–¼:D3DSurface.h
//		ì¬“ú:2018/08/10 14:26:58
//

#ifndef HEADER_D3DSURFACE_H
#define HEADER_D3DSURFACE_H

#include "../dxct_inner.h"
#include "D3DObject.h"

namespace DXCT { namespace D3D
{

class D3DSurface:public D3DObject<IDirect3DSurface9>
{
	private:
		D3DSurface() = delete;


	public:
		D3DSurface(IDirect3DSurface9 *surface);
};

}
}
#endif