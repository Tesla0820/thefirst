//
//		ファイル名:DXObjectRelease.h
//

#ifndef HEADER_DX_OBJECT_RELEASE_H
#define HEADER_DX_OBJECT_RELEASE_H
#include <type_traits>
#include "dxct_inner.h"

namespace DXCT 
{

template<class T>
class DXObjectRelease
{
	static_assert(std::is_convertible<T, IUnknown>::value, "IUnknownを継承しないクラスはDXObjectReleaseでは解放できません。");
	public:
	void operator()(T* pointer);
};

#endif

template<class T>
inline void DXObjectRelease<T>::operator()(T * pointer)
{
	pointer->Release();
}

}