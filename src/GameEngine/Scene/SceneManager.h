//
//		ƒtƒ@ƒCƒ‹–¼:SceneManager.h
//

#ifndef HEADER_SCENE_MANAGER_H
#define HEADER_SCENE_MANAGER_H

#include <vector>
#include <memory>

#include "SceneBase.h"
#include "../GameObject.h"

namespace GameEngine { namespace Scene 
{
	class SceneManager
	{
		private:
			std::vector <std::unique_ptr<GameEngine::SceneBase>> _scenes;
			std::vector<GameEngine::GameObject*> _objects;
			int _index;
			SceneManager();
			~SceneManager();

			static SceneManager* _manager;
			void ClearObjects();
		public:
			void AddObject(GameObject* object);
			void RegisterScene(SceneBase* scene);
			void LoadScene(int index);
			void Update();
			void Draw();
			
			static void Create();
			static SceneManager* Get();
			static void Release();

	};
}
}
#endif