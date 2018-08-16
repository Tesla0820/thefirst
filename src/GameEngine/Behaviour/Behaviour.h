//
//		ƒtƒ@ƒCƒ‹–¼:Behaviour.h
//

#ifndef HEADER_BEHAVIOUR_H
#define HEADER_BEHAVIOUR_H

#include "../GameEngine_inner.h"
#include "../Binder/BehaviourBinder.h"


namespace GameEngine { namespace Behaviour
{

class Behaviour
{
	friend void GameEngine::Binder::BindBehaviourToGameObject(GameEngine::GameObject* object,GameEngine::Behaviour::Behaviour* beaviour);

	private:
		void OnEnabled();
		void OnDisabled();
		
		GameObject* _attached;
		bool _isDestroyed;
		bool _isStarted;
		bool _enable;
	protected:
		Behaviour();
	
	public:
		void Attach(GameEngine::GameObject* target);
		GameObject* GetAttachedObject();
		void SetBehaviourEnable(bool enable);
		bool GetBehaviourEnable();
		bool GetEnable();
		void Initialize();
		void Destroy();
		virtual void Enabled();
		virtual void Disabled();
		virtual void Start();
		virtual void Update();
		virtual void BeforeDraw(D3DXMATRIX const& matrix);
		virtual void Draw(D3DXMATRIX const& matrix);
		virtual ~Behaviour();
};

}
}
#endif