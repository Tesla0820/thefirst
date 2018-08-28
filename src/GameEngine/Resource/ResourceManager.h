//
//		ƒtƒ@ƒCƒ‹–¼:ResourceManager.h
//

#ifndef HEADER_RESOURCE_MANAGER_H
#define HEADER_RESOURCE_MANAGER_H

#include <unordered_map>
#include "IResource.h"

namespace GameEngine { namespace Resource
{

class ResourceManager
{
	private:
		static std::unordered_map<std::string, std::weak_ptr<IResourceBase>> _resources;

	public:
		template<class T>
		static std::shared_ptr<T> Get(std::string key);
		static void Create();
		static void ClearAllResources();
		static void Release();

};

template<class T>
std::shared_ptr<T> ResourceManager::Get(std::string key)
{
	if (_resources.count(key) != 0 && !_resources[key].expired())
	{
		auto ptr = _resources[key].lock();
		return std::dynamic_pointer_cast<T>(ptr);
	}
	else
	{
		std::shared_ptr<IResourceBase> base(new T(key));
		_resources[key] = std::weak_ptr<IResourceBase>(base);
		return  std::dynamic_pointer_cast<T>(base);
	}
}

}
}
#endif