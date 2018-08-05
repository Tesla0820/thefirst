//
//		ƒtƒ@ƒCƒ‹–¼:DXObject.h
//

#ifndef HEADER_DX_OBJECT_H
#define HEADER_DX_OBJECT_H

#include "IReleasable.h"
namespace DXCT
{
	template<class T>
	class DXObject:public IReleasable
	{
		private:
			DXObject() = delete;
			DXObject(DXObject<T> const&) = delete;
			DXObject<T>& operator=(DXObject<T> const&) = delete;

		protected:
			T* _object;

		public:

			DXObject(T* object);
			DXObject(DXObject<T> &&) noexcept = default;	
			DXObject<T>& operator=(DXObject<T> && object);
			virtual ~DXObject();
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

	template<class T>
	T* DXObject<T>::GetPtr() const
	{
		return _object;
	}
	
	template<class T>
	void DXObject<T>::Release()
	{
		if (_object)
		{
			_object->Release();
			_object = nullptr;
		}
	}

	template<class T>
	bool DXObject<T>::IsReleased()
	{
		return _object != nullptr;
	}

}
#endif