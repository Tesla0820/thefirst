//
//		ƒtƒ@ƒCƒ‹–¼:ResultManager.h
//

#ifndef HEADER_RESULTMANAGER_H
#define HEADER_RESULTMANAGER_H

#include "../../GameEngine/GameEngine.h"
#include "../../GameEngine/Behaviour/Behaviour.h"

namespace Game
{

	class ResultManager :public GameEngine::Behaviour::Behaviour
	{

	private:
		int _mode;
		std::vector<GameEngine::Behaviour::SoundPlay*> _soundPlays;
	public:
		ResultManager();
		~ResultManager();
		virtual void Start() override;
		virtual void Update() override;

	};
}
#endif