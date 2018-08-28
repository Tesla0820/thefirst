//
//		ƒtƒ@ƒCƒ‹–¼:Stage2Scene.h
//

#ifndef HEADER_STAGE2SCENE_H
#define HEADER_STAGE2SCENE_H

#include "../../../../GameEngine/GameEngine.h"

namespace Game { namespace GameScene { namespace Scene
{

	class Stage2Scene :public GameEngine::SceneBase
	{

	private:
		GameEngine::Sound::Sound* farre;
	public:
		Stage2Scene();
		~Stage2Scene();
		virtual bool Init() override;

	};

}
}
}
#endif