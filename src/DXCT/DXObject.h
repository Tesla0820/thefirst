//
//		�t�@�C����:DXObject.h
//

#ifndef HEADER_DX_OBJECT_H
#define HEADER_DX_OBJECT_H

#include "IReleasable.h"
namespace DXCT
{

//DirectX�֌W��COM�I�u�W�F�N�g���Ǘ�������N���X�ł��B
template<class T>
class DXObject:public IReleasable
{
	private:
		DXObject() = delete;
		DXObject(DXObject<T> const&) = delete;
		DXObject<T>& operator=(DXObject<T> const&) = delete;

	protected:
		T* _object; //�Ǘ��I�u�W�F�N�g

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
//�Ǘ��I�u�W�F�N�g�̃A�h���X���擾���܂��B
template<class T>
T* DXObject<T>::GetPtr() const
{
	return _object;
}
	
//�Ǘ��I�u�W�F�N�g��������܂��B
template<class T>
void DXObject<T>::Release()
{
	if (_object)
	{
		_object->Release();
		_object = nullptr;
	}
}

//�Ǘ��I�u�W�F�N�g������ς݂����擾���܂��B
template<class T>
bool DXObject<T>::IsReleased()
{
	return _object != nullptr;
}

}
#endif