//
//		ファイル名:SceneManager.cpp
//
#include "SceneManager.h"
#include "../Behaviour/Behaviour.h"

namespace GameEngine {
	namespace Scene
	{
		SceneManager* SceneManager::_manager;

		GameEngine::Scene::SceneManager::SceneManager()
		{
			_oldIndex = _index = -1;
		}

		GameEngine::Scene::SceneManager::~SceneManager()
		{
			ClearObjects();
		}

		void SceneManager::ClearObjects()
		{
			_manager->_unstartedBehaviours.clear();
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

		void SceneManager::RemoveObject(GameObject * object)
		{
			auto iterator = std::find(_manager->_objects.begin(), _manager->_objects.end(), object);
			if (iterator == _manager->_objects.end()) return; //一致する子オブジェクトが存在しなった。
			_manager->_objects.erase(iterator);
		}

		void SceneManager::RegisterUnstartedBehaviour(GameEngine::Behaviour::Behaviour * unstarted)
		{
			_manager->_unstartedBehaviours.push_back(unstarted);
		}

		void SceneManager::UnRegisterBehaviour(GameEngine::Behaviour::Behaviour * behaviour)
		{
			auto iterator = std::find(_manager->_unstartedBehaviours.begin(), _manager->_unstartedBehaviours.end(), behaviour);
			if (iterator == _manager->_unstartedBehaviours.end())return;//見つからなかった場合
			_manager->_unstartedBehaviours.erase(iterator);
		}

		void SceneManager::RegisterScene(SceneBase * scene)
		{
			_manager->_scenes.push_back(std::unique_ptr<SceneBase>(scene));
		}

		void SceneManager::NextScene()
		{
			_manager->_oldIndex = _manager->_index;
			ClearObjects();
			if (_manager->_index >= _manager->_scenes.size())
			{
				PostQuitMessage(0);
				return;
			}
			if (_manager->_scenes[_manager->_index]->Init())
			{
				throw(std::runtime_error("シーンの初期化に失敗しました。"));
			}
		}

		void SceneManager::LoadScene(int index)
		{
			_manager->_index = index;
		}

		void SceneManager::Update()
		{
			if (SceneChanged())
			{
				NextScene();
			}
			for (auto object = _manager->_objects.begin(); object != _manager->_objects.end() && SceneChanged(); object++)
			{
				static bool t = true;
				InitializeUnStartedBehaviours();
				if (SceneChanged())return;
				if (t)
				{
					t = false;
					LoadScene(1);
				}
				(*object)->Update();
			}

		}

		void SceneManager::InitializeUnStartedBehaviours()
		{
			if (SceneChanged()) return;
			while (!_manager->_unstartedBehaviours.empty())
			{
				auto behaviour = _manager->_unstartedBehaviours.back();
				behaviour->Initialize();
				_manager->_unstartedBehaviours.pop_back();
				if (SceneChanged()) break; //シーンの変更が行われた
			}
		}

		bool SceneManager::SceneChanged()
		{
			return _manager->_index != _manager->_oldIndex;
		}

		void SceneManager::Draw()
		{
			D3DXMATRIX matrix;
			D3DXMatrixIdentity(&matrix);
			if (SceneChanged())return;
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