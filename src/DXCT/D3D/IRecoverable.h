//
//		ƒtƒ@ƒCƒ‹–¼:IRecoveryable.h
//

#ifndef HEADER_IRECOVERABLE_H
#define HEADER_IRECOVERABLE_H

#include "../dxct_inner.h"

namespace DXCT { namespace D3D 
{
	DXCT_INTERFACE IRecoverable
	{
		virtual void Recovery(IRecoverable * origin) = 0;
		virtual void BackUp() = 0;
	};
}
}
#endif