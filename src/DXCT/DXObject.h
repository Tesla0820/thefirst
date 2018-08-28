//
//		�t�@�C����:DXObject.h
//

#ifndef HEADER_DX_OBJECT_H
#define HEADER_DX_OBJECT_H

#include "IReleasable.h"
#include "DXObjectRelease.h"
namespace DXCT
{

//DirectX�֌W��COM�I�u�W�F�N�g���Ǘ�������N���X�ł��B
template<class T,class release=DXObjectRelease<IUnknown>>
class DXObject:public IReleasable
{
	private:
		DXObject() = delete;
		DXObject(DXObject<T,release> const&) = delete;
		DXObject<T,release>& operator=(DXObject<T,release> const&) = delete;

	protected:
		T* _object; //�Ǘ��I�u�W�F�N�g

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
//�Ǘ��I�u�W�F�N�g�̃A�h���X���擾���܂��B
template<class T,class release>
T* DXObject<T,release>::GetPtr() const
{
	return _object;
}
	
//�Ǘ��I�u�W�F�N�g��������܂��B
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

//�Ǘ��I�u�W�F�N�g������ς݂����擾���܂��B
template<class T,class release>
bool DXObject<T,release>::IsReleased()
{
	return _object != nullptr;
}

}
#endif