//
//		ƒtƒ@ƒCƒ‹–¼:GameOverScene.h
//

#ifndef HEADER_GAMEOVERSCENE_H
#define HEADER_GAMEOVERSCENE_H

#include "../../../GameEngine/GameEngine.h"

namespace Game { namespace ResultScene
{
	class GameOverScene :public GameEngine::SceneBase
	{
	public:
		GameOverScene() = default;
		virtual bool Init() override;

	};
}
}
#endif