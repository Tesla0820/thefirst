//
//		�t�@�C����:SceneManager.cpp
//
#include "SceneManager.h"

namespace GameEngine { namespace Scene 
{
	SceneManager* SceneManager::_manager;

GameEngine::Scene::SceneManager::SceneManager()
{
	_index = 0;
}

GameEngine::Scene::SceneManager::~SceneManager()
{
	ClearObjects();
}

void SceneManager::ClearObjects()
{
	while (!_manager->_objects.empty())
	{
		auto object = _manager->_objects.back();
		delete object;
		_manager->_objects.pop_back();
	}
}

void SceneManager::AddObject(GameObject * object)
{
	_manager->_objects.push_back(object);
}

void SceneManager::RegisterUnstartedBehaviour(GameEngine::Behaviour::Behaviour * unstarted)
{
	_manager->_unstartedBehaviours.push_back(unstarted);
}

void SceneManager::UnRegisterBehaviour(GameEngine::Behaviour::Behaviour * behaviour)
{
	auto iterator = std::find(_manager->_unstartedBehaviours.begin(), _manager->_unstartedBehaviours.end(), behaviour);
	if (iterator == _manager->_unstartedBehaviours.end())return;//������Ȃ������ꍇ
	_manager->_unstartedBehaviours.erase(iterator);
}

void SceneManager::RegisterScene(SceneBase * scene)
{
	_manager->_scenes.push_back(std::unique_ptr<SceneBase>(scene));
}

void SceneManager::LoadScene(int index)
{
	ClearObjects();
	_manager->_index = index;
	if (_manager->_index >= _manager->_scenes.size())
	{
		PostQuitMessage(0);
		return;
	}
	if (_manager->_scenes[_manager->_index]->Init())
	{
		throw(std::runtime_error("�V�[���̏������Ɏ��s���܂����B"));
	}
}

void SceneManager::Update()
{
	for (auto object : _manager->_objects)
	{
		while (!_manager->_unstartedBehaviours.empty())
		{
			auto behaviour = _manager->_unstartedBehaviours.back();
			behaviour->Start();
			_manager->_unstartedBehaviours.pop_back();
		}
		object->Update();
	}
}

void SceneManager::Draw()
{
	D3DXMATRIX matrix;
	D3DXMatrixIdentity(&matrix);
	for (auto object : _manager->_objects)
	{
		object->BeforeDraw(matrix);
	}
	for (auto object : _manager->_objects)
	{
		object->Draw(matrix);
	}
}

void GameEngine::Scene::SceneManager::Create()
{
	if (!_manager)
	{
		_manager = new SceneManager();
	}
}

void SceneManager::Release()
{
	if (_manager)
	{
		delete _manager;
	}
}

}
}