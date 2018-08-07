//
//		ファイル名:IReleasable.h
//

#ifndef HEADER_IRELEASABLE_H
#define HEADER_IRELEASABLE_H

#include "dxct_inner.h"

namespace DXCT
{
	//開放可能オブジェクトを解放するためのメカニズムを提供します。
	DXCT_INTERFACE IReleasable
	{
		virtual void Release() = 0;
		virtual bool IsReleased() = 0;
		virtual ~IReleasable() {}
	};
}
#endif