//
//		ƒtƒ@ƒCƒ‹–¼:Stage3Scene.h
//

#ifndef HEADER_STAGE3SCENE_H
#define HEADER_STAGE3SCENE_H

#include "../../../../GameEngine/GameEngine.h"

namespace Game { namespace GameScene { namespace Scene
{

	class Stage3Scene :public GameEngine::SceneBase
	{
	public:
		Stage3Scene() = default;
		virtual bool Init() override;

	};

}
}
}
#endif