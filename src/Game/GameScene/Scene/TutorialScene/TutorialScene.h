//
//		ƒtƒ@ƒCƒ‹–¼:TutorialScene.h
//

#ifndef HEADER_TUTORIALSCENE_H
#define HEADER_TUTORIALSCENE_H

#include "../../../../GameEngine/GameEngine.h"

namespace Game { namespace GameScene{ namespace Scene
{
	class TutorialScene :public GameEngine::SceneBase
	{

	private:
		GameEngine::Sound::Sound* farre;

	public:
		TutorialScene();
		~TutorialScene();
		virtual bool Init() override;

	};
}
}
}
#endif