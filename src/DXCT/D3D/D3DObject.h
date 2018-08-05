//
//		�t�@�C����:D3DObject.h
//

#ifndef HEADER_D3D_OBJECT_H
#define HEADER_D3D_OBJECT_H

#include <list>
#include <algorithm>
#include <memory>

#include "../dxct_inner.h"
#include "../DXObject.h"
#include "IRecoverable.h"

namespace DXCT { namespace D3D
{	
	template <class T>
	class D3DObject : public DXObject<T>,public IRecoverable
	{
		private:
			D3DObject() = delete;
			
			std::list<std::weak_ptr<IRecoverable>> _createdObjects;
		
		protected:
			D3DObject(T* object);
			void RegisterCreatedObject(std::shared_ptr<IRecoverable> & object);
			void ClearReleasedObject();
			virtual void Recovery(IRecoverable * origin) override;
			virtual void BackUp() override;
		public:
	};

	template <class T>
	D3DObject<T>::D3DObject(T* object) : DXObject(object)
	{
	}

	template <class T>
	void D3DObject<T>::RegisterCreatedObject(std::shared_ptr<IRecoverable> & object)
	{
		std::weak_ptr<IRecoverable> p(object);
		_createdObjects.push_back(std::move(p));
	}

	template <class T>
	void D3DObject<T>::ClearReleasedObject()
	{
		_createdObjects.erase(
			std::remove_if(
				_createdObjects.begin(),
				_createdObjects.end(),
				[](std::weak_ptr<IRecoverable> const& ptr) {return ptr.expired(); }
			)
		);
	}

	template <class T>
	void D3DObject<T>::Recovery(IRecoverable * origin)
	{
		ClearReleasedObject();
		for (auto itr : _createdObjects)
		{
			auto ptr = itr.lock();
			ptr->Recovery(this);
		}
	}

	template <class T>
	void D3DObject<T>::BackUp()
	{
		ClearReleasedObject();
		for (auto itr :_createdObjects)
		{
			auto ptr = itr.lock();
			ptr->BackUp();
		}
	}

}
}

#endif