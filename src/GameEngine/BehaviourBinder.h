//
//		�t�@�C����:BehaviourBinder.h
//

#ifndef HEADER_BEHAVIOUR_BINDER_H
#define HEADER_BEHAVIOUR_BINDER_H



namespace GameEngine
{
	//��s�錾
	class GameObject;

	namespace Behaviour
	{
		class Behaviour;
	}
	namespace Binder
	{

		void BindBehaviourToGameObject(GameEngine::GameObject* object, GameEngine::Behaviour::Behaviour *behaviour);

	}
}

#endif