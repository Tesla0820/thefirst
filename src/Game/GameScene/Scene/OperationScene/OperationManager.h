//
//		ƒtƒ@ƒCƒ‹–¼:OperationManager.h
//

#ifndef HEADER_OPERATIONMANAGER_H
#define HEADER_OPERATIONMANAGER_H

#include "../../../../GameEngine/GameEngine.h"
#include "../../../../GameEngine/Behaviour/Behaviour.h"


namespace Game { namespace GameScene { namespace Scene
{


	class OperationManager :public GameEngine::Behaviour::Behaviour
	{

	private:
		GameEngine::Behaviour::SoundPlay* _soundPlay;

	public:
		OperationManager();
		~OperationManager();
		virtual void Start() override;
		virtual void Update() override;

	};
}
}
}
#endif