//
//		�t�@�C����:TitleScene.h
//

#ifndef HEADER_TITLESCENE_H
#define HEADER_TITLESCENE_H

#include "../../GameEngine/GameEngine.h"

namespace Game
{
	class TitleScene:public GameEngine::SceneBase
	{
		public:
			TitleScene();
			~TitleScene();
			virtual bool Init() override;

	};
}
#endif