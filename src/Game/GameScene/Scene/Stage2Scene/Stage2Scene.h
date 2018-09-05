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
public:
	Stage2Scene() = default;
	virtual bool Init() override;

};

}
}
}
#endif