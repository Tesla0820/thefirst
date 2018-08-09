//
//		ファイル名:BehaviourBinder.h
//

#ifndef HEADER_BEHAVIOUR_BINDER_H
#define HEADER_BEHAVIOUR_BINDER_H



namespace GameEngine
{
	//先行宣言
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