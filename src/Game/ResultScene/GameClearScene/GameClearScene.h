//
//		ƒtƒ@ƒCƒ‹–¼:GameClearScene.h
//

#ifndef HEADER_GAMECLEARSCENE_H
#define HEADER_GAMECLEARSCENE_H

#include "../../../GameEngine/GameEngine.h"

namespace Game { namespace ResultScene
{
	class GameClearScene :public GameEngine::SceneBase
	{
	public:
		GameClearScene() = default;
		virtual bool Init() override;

	};
}
}
#endif