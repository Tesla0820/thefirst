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

	private:
		GameEngine::Sound::Sound* farre;
	public:
		GameClearScene();
		~GameClearScene();
		virtual bool Init() override;

	};
}
}
#endif