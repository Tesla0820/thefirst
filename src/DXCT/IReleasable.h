//
//		ƒtƒ@ƒCƒ‹–¼:IReleasable.h
//

#ifndef HEADER_IRELEASABLE_H
#define HEADER_IRELEASABLE_H

#include "dxct_inner.h"

namespace DXCT
{
	DXCT_INTERFACE IReleasable
	{
		virtual void Release() = 0;
		virtual bool IsReleased() = 0;
		virtual ~IReleasable() {}
	};
}
#endif