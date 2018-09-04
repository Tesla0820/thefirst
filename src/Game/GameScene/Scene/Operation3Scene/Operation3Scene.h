//
//		ƒtƒ@ƒCƒ‹–¼:Oparation3Scene.h
//

#ifndef HEADER_OPERATION3SCENE_H
#define HEADER_OPERATION3SCENE_H

#include "../../../../GameEngine/GameEngine.h"

namespace Game { namespace GameScene { namespace Scene
{
	class Operation3Scene :public GameEngine::SceneBase
	{

	private:
		GameEngine::Sound::Sound* farre;
	public:
		Operation3Scene();
		~Operation3Scene();
		virtual bool Init() override;

	};
}
}
}
#endif