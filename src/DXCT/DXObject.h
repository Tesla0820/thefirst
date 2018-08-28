//
//		ファイル名:DXObject.h
//

#ifndef HEADER_DX_OBJECT_H
#define HEADER_DX_OBJECT_H

#include "IReleasable.h"
#include "DXObjectRelease.h"
namespace DXCT
{

//DirectX関係のCOMオブジェクトを管理する基底クラスです。
template<class T,class release=DXObjectRelease<IUnknown>>
class DXObject:public IReleasable
{
	private:
		DXObject() = delete;
		DXObject(DXObject<T,release> const&) = delete;
		DXObject<T,release>& operator=(DXObject<T,release> const&) = delete;

	protected:
		T* _object; //管理オブジェクト

	public:

		DXObject(T* object);
		DXObject(DXObject<T,release> &&) noexcept = default;	
		virtual ~DXObject();
		DXObject<T,release>& operator=(DXObject<T,release> && object);
		T* GetPtr() const;
		virtual void Release() override;
		virtual bool IsReleased() override;

};
	
template<class T,class release>
DXObject<T,release>& DXObject<T,release>::operator=(DXObject<T,release>&& object)
{
	_object = object._object;
	object._object = nullptr;
}
	
	
template<class T,class release>
DXObject<T,release>::DXObject(T * object)
{
	_object = object;
}

template<class T,class release>
DXObject<T,release>::~DXObject()
{
	Release();
}
//管理オブジェクトのアドレスを取得します。
template<class T,class release>
T* DXObject<T,release>::GetPtr() const
{
	return _object;
}
	
//管理オブジェクトを解放します。
template<class T,class release>
void DXObject<T,release>::Release()
{
	if (_object)
	{
		release releaser;
		releaser(_object);
		_object = nullptr;
	}
}

//管理オブジェクトが解放済みかを取得します。
template<class T,class release>
bool DXObject<T,release>::IsReleased()
{
	return _object != nullptr;
}

}
#endif