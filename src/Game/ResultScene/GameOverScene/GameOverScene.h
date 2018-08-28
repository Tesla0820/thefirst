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

	private:
		GameEngine::Sound::Sound* farre;
	public:
		GameOverScene();
		~GameOverScene();
		virtual bool Init() override;

	};
}
}
#endif