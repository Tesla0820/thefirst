//
//		ファイル名:IRecoveryable.h
//

#ifndef HEADER_IRECOVERABLE_H
#define HEADER_IRECOVERABLE_H

#include "../dxct_inner.h"

namespace DXCT { namespace D3D 
{

//Direct3D9で発生するデバイスロストの復帰メカニズムを提供します。
DXCT_INTERFACE IRecoverable
{
	virtual void Recovery(IRecoverable * origin) = 0;	//デバイスロストから復帰します。
	virtual void BackUp() = 0;							//復帰のための準備処理を行います。
};

}
}
#endif