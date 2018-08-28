//
//		ƒtƒ@ƒCƒ‹–¼:ResourceManager.cpp
//
#include "ResourceManager.h"

namespace GameEngine { namespace Resource
{
std::unordered_map<std::string, std::weak_ptr<IResourceBase>> ResourceManager::_resources;
	

void GameEngine::Resource::ResourceManager::Create()
{

}

void ResourceManager::ClearAllResources()
{
	_resources.clear();
}

void ResourceManager::Release()
{
	ClearAllResources();
}

}
}