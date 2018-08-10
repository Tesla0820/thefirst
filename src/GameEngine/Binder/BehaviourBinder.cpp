//
//		ƒtƒ@ƒCƒ‹–¼:BehaviourBinder.cpp
//

#include "../Scene/SceneManager.h"
#include "../GameObject.h"
#include "../Behaviour/Behaviour.h"

namespace GameEngine { namespace Binder 
{
	void BindBehaviourToGameObject(GameEngine::GameObject* object,GameEngine::Behaviour::Behaviour *behaviour)
	{
		if (!behaviour)return;
		if (behaviour->_attached) return;

		behaviour->_attached = object;
		if (object) 
		{
			object->_behaviours.push_back(behaviour);
			if (!behaviour->_isStarted)
			{
				GameEngine::Scene::SceneManager::RegisterUnstartedBehaviour(behaviour);
			}
		}
	}
}
}