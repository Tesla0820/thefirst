//
//		ファイル名:SceneManager.h
//

#ifndef HEADER_SCENE_MANAGER_H
#define HEADER_SCENE_MANAGER_H

#include <vector>
#include <list>
#include <memory>

#include "SceneBase.h"
#include "../GameObject.h"

namespace GameEngine { namespace Scene 
{
	//シーン情報を管理します。ユーザー側でこのクラスの一部の静的メソッドを呼び出さないでください。
	class SceneManager
	{
		private:
			std::vector <std::unique_ptr<GameEngine::SceneBase>> _scenes;
			std::vector<GameEngine::GameObject*> _objects;
			std::list<GameEngine::Behaviour::Behaviour*> _unstartedBehaviours;
			int _index;
			SceneManager();
			~SceneManager();

			static SceneManager* _manager;
			static void ClearObjects();
		public:
			static void AddObject(GameObject *object);
			static void RemoveObject(GameObject * object);
			static void RegisterUnstartedBehaviour(GameEngine::Behaviour::Behaviour  *unstarted);
			static void UnRegisterBehaviour(GameEngine::Behaviour::Behaviour *behaviour);
			static void RegisterScene(SceneBase *scene);
			static void LoadScene(int index);
			static void Update();
			static void Draw();
			
			static void Create();
			static void Release();

	};
}
}
#endif