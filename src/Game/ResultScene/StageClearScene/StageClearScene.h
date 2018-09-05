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
	public:
		StageClearScene() = default;
		virtual bool Init() override;

	};
}
}
#endif