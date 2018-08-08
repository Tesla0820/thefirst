//
//		ƒtƒ@ƒCƒ‹–¼:Behaviour.h
//

#ifndef HEADER_BEHAVIOUR_H
#define HEADER_BEHAVIOUR_H

#include "../GameEngine_inner.h"
#include "../BehaviourBinder.h"


namespace GameEngine { namespace Behaviour
{

class Behaviour
{
	friend void GameEngine::Binder::BindBehaviourToGameObject(GameEngine::GameObject* object,GameEngine::Behaviour::Behaviour* beaviour);

	private:
		GameEngine::GameObject* _target;
		bool _isStarted;
	protected:
		Behaviour();
	public:
		void SetTarget(GameEngine::GameObject* target);
		GameEngine::GameObject* GetTarget();
		virtual void Start();
		virtual void Update();
		virtual void BeforeDraw(D3DXMATRIX const& matrix);
		virtual void Draw(D3DXMATRIX const& matrix);
		virtual ~Behaviour();
};

}
}
#endif