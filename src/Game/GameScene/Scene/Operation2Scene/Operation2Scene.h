//
//		ƒtƒ@ƒCƒ‹–¼:Oparation2Scene.h
//

#ifndef HEADER_OPERATION2SCENE_H
#define HEADER_OPERATION2SCENE_H

#include "../../../../GameEngine/GameEngine.h"

namespace Game { namespace GameScene { namespace Scene
{
	class Operation2Scene :public GameEngine::SceneBase
	{

	private:
		GameEngine::Sound::Sound* farre;
	public:
		Operation2Scene();
		~Operation2Scene();
		virtual bool Init() override;

	};
}
}
}
#endif