//
//		ƒtƒ@ƒCƒ‹–¼:TitleScene.h
//

#ifndef HEADER_TITLESCENE_H
#define HEADER_TITLESCENE_H

#include "../../GameEngine/GameEngine.h"

namespace Game
{
	class TitleScene:public GameEngine::SceneBase
	{
		
		private:
		GameEngine::Sound::Sound* farre;
		public:
		TitleScene();
		~TitleScene();
		virtual bool Init() override;

	};
}
#endif