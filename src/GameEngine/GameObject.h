//
//		ƒtƒ@ƒCƒ‹–¼:GameObject.h
//

#ifndef HEADER_GAMEOBJECT_H
#define HEADER_GAMEOBJECT_H

#include <memory>
#include <vector>
#include <string>

#include "GameEngine_inner.h"
#include "BehaviourBinder.h"
#include "Behaviour/Behaviour.h"
#include "Behaviour/Transform.h"


namespace GameEngine
{
	class GameObject
	{
		friend void GameEngine::Binder::BindBehaviourToGameObject(GameEngine::GameObject* object, GameEngine::Behaviour::Behaviour* beaviour);

		private:	
			GameObject(GameObject const&) = delete;
			GameObject& operator=(GameObject const&) = delete;

			GameObject* _parent;
			std::vector<GameObject*> _children;
			std::vector<Behaviour::Behaviour*> _behaviours;
			std::string _name;

			bool _enable;

		protected:
			GameObject();

		public:
			GameObject(GameObject&&) = default;
			GameObject& operator=(GameObject&&) = default;
			virtual ~GameObject();
			GameObject* GetParent();
			GameObject* GetChild(int index);
			void AddBehaviour(Behaviour::Behaviour* behaviour);
			template <class T> T* FindBehaviour();
			Behaviour::Transform* GetTransform();
			std::vector<GameObject*> GetChildren();
			void Update();
			void BeforeDraw(D3DXMATRIX const& mtx);
			void Draw(D3DXMATRIX const& mtx); 
			void End();
			void Destroy();
			static GameObject* Instantiate();
	};

	template <class T>
	T* GameObject::FindBehaviour()
	{
		for (auto behaviour : _behaviours)
		{
			T* target = dynamic_cast<T*>(behaviour);
			if (target != nullptr)
			{
				return target;
			}
		}
		return nullptr;
	}

}
#endif