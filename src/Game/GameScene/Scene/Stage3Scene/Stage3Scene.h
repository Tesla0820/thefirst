//
//		ƒtƒ@ƒCƒ‹–¼:Stage2Scene.h
//

#ifndef HEADER_STAGE3SCENE_H
#define HEADER_STAGE3SCENE_H

#include "../../../../GameEngine/GameEngine.h"

namespace Game { namespace GameScene { namespace Scene
{

	class Stage3Scene :public GameEngine::SceneBase
	{

	private:
		GameEngine::Sound::Sound* farre;
	public:
		Stage3Scene();
		~Stage3Scene();
		virtual bool Init() override;

	};

}
}
}
#endif