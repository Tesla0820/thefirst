//
//		�t�@�C����:BehaviourBinder.cpp
//

#include "../Scene/SceneManager.h"
#include "../GameObject.h"
#include "../Behaviour/Behaviour.h"

namespace GameEngine { namespace Binder 
{
	void BindBehaviourToGameObject(GameObject* object,GameEngine::Behaviour::Behaviour *behaviour)
	{
		bool isAttached = static_cast<bool>(behaviour->_attached);
		bool hasValue	= static_cast<bool>(object);
		if (!behaviour)return;
		if (behaviour->_isDestroyed)return; //�f�X�g���C�ς݂̃r�w�C�r�A�̓A�^�b�`�s�\
		if (isAttached == hasValue) return; //�A�^�b�`�ς݂��A�^�b�`�Ώۂ�����ꍇ�A�Ȃ����A�^�b�`����Ă��Ȃ���Ԃ��A�^�b�`�Ώۂ��Ȃ��ꍇ�͉������Ȃ�
		if (hasValue)
		{
			
			//�A�^�b�`��L�����C�x���g���s
			behaviour->_attached = object;
			object->_behaviours.push_back(behaviour);
			if (!behaviour->_isStarted)
			{
				//Initialize����OnEnabled���Ă΂�邽�߁A�����ł͌Ă΂Ȃ�
				GameEngine::Scene::SceneManager::RegisterUnstartedBehaviour(behaviour);
			}
			else
			{
				behaviour->OnEnabled();
			}
		}
		else 
		{
			//�������C�x���g���s��f�^�b�`
			behaviour->OnDisabled();
			behaviour->_attached = object;
		}
	}
}
}