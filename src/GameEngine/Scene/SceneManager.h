//
//		�t�@�C����:SceneManager.h
//

#ifndef HEADER_SCENE_MANAGER_H
#define HEADER_SCENE_MANAGER_H

#include <vector>
#include <list>
#include <memory>

#include "SceneBase.h"
#include "../GameObject.h"

namespace GameEngine {
	namespace Scene
	{
		//�V�[�������Ǘ����܂��B���[�U�[���ł��̃N���X�̈ꕔ�̐ÓI���\�b�h���Ăяo���Ȃ��ł��������B
		class SceneManager
		{
		private:
			SceneManager();
			~SceneManager();
			static void NextScene();
			static void ClearObjects();
			static void InitializeUnStartedBehaviours();
			static bool SceneChanged();

			std::vector <std::unique_ptr<GameEngine::SceneBase>> _scenes;
			std::vector<GameEngine::GameObject*> _objects;
			std::list<GameEngine::Behaviour::Behaviour*> _unstartedBehaviours;
			int _index;
			int _oldIndex;

			static SceneManager* _manager;
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