//
//		ƒtƒ@ƒCƒ‹–¼:TutorialManager.h
//

#ifndef HEADER_TUTORIALMANAGER_H
#define HEADER_TUTORIALMANAGER_H

#include "../../../../GameEngine/GameEngine.h"
#include "../../../../GameEngine/Behaviour/Behaviour.h"
#include "../StageManager.h"

namespace Game { namespace GameScene { namespace Scene
{
	class StageManager;

	class TutorialManager :public GameEngine::Behaviour::Behaviour
	{

	private:
		Game::GameScene::StageManager* _stagemanager;
	public:
		TutorialManager();
		~TutorialManager();
		virtual void Start() override;
		virtual void Update() override;

	};
}
}
}
#endif