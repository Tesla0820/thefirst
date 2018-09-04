//
//		�t�@�C����:StageClearManager.h
//

#ifndef HEADER_STAGECLEARMANAGER_H
#define HEADER_STAGECLEARMANAGER_H

#include "../../../GameEngine/GameEngine.h"
#include "../../../GameEngine/Behaviour/Behaviour.h"
#include "../../GameScene/Scene/StageManager.h"

namespace Game { namespace ResultScene
{
	class StageManager;

	class StageClearManager :public GameEngine::Behaviour::Behaviour
	{

	private:
		int _Stage;
		std::vector<GameEngine::Behaviour::SoundPlay*> _soundPlays;
	public:
		StageClearManager();
		~StageClearManager();
		virtual void Start() override;
		virtual void Update() override;

	};
}
}
#endif