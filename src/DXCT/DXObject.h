//
//		ファイル名:DXObject.h
//

#ifndef HEADER_DX_OBJECT_H
#define HEADER_DX_OBJECT_H

#include "IReleasable.h"
namespace DXCT
{

//DirectX関係のCOMオブジェクトを管理する基底クラスです。
template<class T>
class DXObject:public IReleasable
{
	private:
		DXObject() = delete;
		DXObject(DXObject<T> const&) = delete;
		DXObject<T>& operator=(DXObject<T> const&) = delete;

	protected:
		T* _object; //管理オブジェクト

	public:

		DXObject(T* object);
		DXObject(DXObject<T> &&) noexcept = default;	
		virtual ~DXObject();
		DXObject<T>& operator=(DXObject<T> && object);
		T* GetPtr() const;
		virtual void Release() override;
		virtual bool IsReleased() override;

};
	
template<class T>
DXObject<T>& DXObject<T>::operator=(DXObject<T>&& object)
{
	_object = object._object;
	object._object = nullptr;
}
	
	
template<class T>
DXObject<T>::DXObject(T * object)
{
	_object = object;
}

template<class T>
DXObject<T>::~DXObject()
{
	if (_object)
	{
		_object->Release();
	}
}
//管理オブジェクトのアドレスを取得します。
template<class T>
T* DXObject<T>::GetPtr() const
{
	return _object;
}
	
//管理オブジェクトを解放します。
template<class T>
void DXObject<T>::Release()
{
	if (_object)
	{
		_object->Release();
		_object = nullptr;
	}
}

//管理オブジェクトが解放済みかを取得します。
template<class T>
bool DXObject<T>::IsReleased()
{
	return _object != nullptr;
}

}
#endif