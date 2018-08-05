//
//		ファイル名:SceneManager.cpp
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
	while (!_objects.empty())
	{
		auto object = _objects.back();
		delete object;
		_objects.pop_back();
	}
}

void SceneManager::AddObject(GameObject * object)
{
	_objects.push_back(object);
}

void SceneManager::RegisterScene(SceneBase * scene)
{
	_scenes.push_back(std::unique_ptr<SceneBase>(scene));
}

void SceneManager::LoadScene(int index)
{
	ClearObjects();
	_index = index;
	if (_index >= _scenes.size())
	{
		PostQuitMessage(0);
		return;
	}
	if (_scenes[_index]->Init())
	{
		throw(std::runtime_error("シーンの初期化に失敗しました。"));
	}
}

void SceneManager::Update()
{
	for (auto object : _objects)
	{
		object->Update();
	}
}

void SceneManager::Draw()
{
	D3DXMATRIX matrix;
	D3DXMatrixIdentity(&matrix);
	for (auto object : _objects)
	{
		object->BeforeDraw(matrix);
	}
	for (auto object : _objects)
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

SceneManager * SceneManager::Get()
{
	return _manager;
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