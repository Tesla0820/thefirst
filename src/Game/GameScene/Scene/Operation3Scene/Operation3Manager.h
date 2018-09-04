//
//		ƒtƒ@ƒCƒ‹–¼:Operation3Manager.h
//

#ifndef HEADER_OPERATION3MANAGER_H
#define HEADER_OPERATION3MANAGER_H

#include "../../../../GameEngine/GameEngine.h"
#include "../../../../GameEngine/Behaviour/Behaviour.h"

namespace Game { namespace GameScene { namespace Scene
{


	class Operation3Manager :public GameEngine::Behaviour::Behaviour
	{

	private:
	public:
		Operation3Manager();
		~Operation3Manager();
		virtual void Start() override;
		virtual void Update() override;

	};
}
}
}
#endif