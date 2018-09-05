//
//		ファイル名:BehaviourBinder.cpp
//

#include "../Scene/SceneManager.h"
#include "../GameObject.h"
#include "../Behaviour/Behaviour.h"

namespace GameEngine { namespace Binder 
{
	void BindBehaviourToGameObject(GameObject* object,GameEngine::Behaviour::Behaviour *behaviour)
	{
		bool isAttached = behaviour->_attached !=nullptr;
		bool hasValue	= object != nullptr;
		if (!behaviour)return;
		if (behaviour->_isDestroyed)return; //デストロイ済みのビヘイビアはアタッチ不可能
		if (isAttached == hasValue) return; //アタッチ済みかつアタッチ対象がある場合、ないしアタッチされていない状態かつアタッチ対象もない場合は何もしない
		if (hasValue)
		{
			//アタッチ後有効化イベント実行
			behaviour->_attached = object;
			object->_behaviours.push_back(behaviour);
			if (!behaviour->_isStarted)
			{
				//Initialize内でOnEnabledが呼ばれるため、ここでは呼ばない
				GameEngine::Scene::SceneManager::RegisterUnstartedBehaviour(behaviour);
			}
			else
			{
				behaviour->OnEnabled();
			}
		}
		else 
		{
			//無効化イベント実行後デタッチ
			behaviour->OnDisabled();
			behaviour->_attached = object;
		}
	}
}
}