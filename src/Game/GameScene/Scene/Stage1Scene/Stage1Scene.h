//
//		ƒtƒ@ƒCƒ‹–¼:Stage1Scene.h
//

#ifndef HEADER_STAGE1SCENE_H
#define HEADER_STAGE1SCENE_H

#include "../../../../GameEngine/GameEngine.h"

namespace Game { namespace GameScene { namespace Scene
{

class Stage1Scene :public GameEngine::SceneBase
{
public:
	Stage1Scene() = default;
	virtual bool Init() override;

};

}
}
}
#endif