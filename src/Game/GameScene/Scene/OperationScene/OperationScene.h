//
//		ƒtƒ@ƒCƒ‹–¼:OparationScene.h
//

#ifndef HEADER_OPERATIONSCENE_H
#define HEADER_OPERATIONSCENE_H

#include "../../../../GameEngine/GameEngine.h"

namespace Game { namespace GameScene { namespace Scene
{
	class OperationScene :public GameEngine::SceneBase
	{

	private:
		GameEngine::Sound::Sound* farre;
	public:
		OperationScene();
		~OperationScene();
		virtual bool Init() override;

	};
}
}
}
#endif