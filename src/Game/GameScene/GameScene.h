//
//		ƒtƒ@ƒCƒ‹–¼:GameScene.h
//

#ifndef HEADER_GAMESCENE_H
#define HEADER_GAMESCENE_H

#include "../../GameEngine/GameEngine.h"

namespace Game
{
	class GameScene :public GameEngine::SceneBase
	{

	private:
		GameEngine::Sound::Sound* farre;
	public:
		GameScene();
		~GameScene();
		virtual bool Init() override;

	};
}
#endif