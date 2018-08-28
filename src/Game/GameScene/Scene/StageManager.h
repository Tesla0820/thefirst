//
//		ƒtƒ@ƒCƒ‹–¼:StageManager.h
//

#ifndef HEADER_STAGEMANAGER_H
#define HEADER_STAGEMANAGER_H

#include "../../../GameEngine/GameEngine.h"
#include "../../../GameEngine/Behaviour/Behaviour.h"

namespace Game { namespace GameScene
{

	class StageManager
	{

	private:
		static int _stage;
		static constexpr int _maxStage = 4;
	public:
		static void SetStage(int stage);
		static void NextStage();
		static void LoadStage();
		
	};
		
}
}
#endif