//
//		ƒtƒ@ƒCƒ‹–¼:StageClearScene.h
//

#ifndef HEADER_STAGECLEARSCENE_H
#define HEADER_STAGECLEARSCENE_H

#include "../../../GameEngine/GameEngine.h"

namespace Game { namespace ResultScene
{
	class StageClearScene :public GameEngine::SceneBase
	{

	private:
		GameEngine::Sound::Sound* farre;
	public:
		StageClearScene();
		~StageClearScene();
		virtual bool Init() override;

	};
}
}
#endif