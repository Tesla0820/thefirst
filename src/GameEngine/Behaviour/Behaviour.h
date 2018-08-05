//
//		ƒtƒ@ƒCƒ‹–¼:Behaviour.h
//

#ifndef HEADER_BEHAVIOUR_H
#define HEADER_BEHAVIOUR_H

#include "../GameEngine_inner.h"

namespace GameEngine 
{ 

class GameObject;

namespace Behaviour
{

struct Behaviour
{
	private:
		GameEngine::GameObject* _target;
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