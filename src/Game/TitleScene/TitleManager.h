//
//		ƒtƒ@ƒCƒ‹–¼:TitleManager.h
//

#ifndef HEADER_TITLEMANAGER_H
#define HEADER_TITLEMANAGER_H

#include "../../GameEngine/GameEngine.h"
#include "../../GameEngine/Behaviour/Behaviour.h"

namespace Game
{
	enum MODE {
		MODE_TUTORIAL = 0,
		MODE_STAGE1,
		MODE_STAGE2,
		MODE_STAGE3,

		MODE_MAX
	};

	class TitleManager :public GameEngine::Behaviour::Behaviour
	{

	private:
		int _mode;
		int _red;
		int _green;
		int _blue;
		int _alpha;
		bool _plus;
		GameEngine::Behaviour::Transform* _transform;
		GameEngine::Behaviour::UIRenderer* _render;
		std::vector<GameEngine::Behaviour::SoundPlay*> _soundPlays;
	public:
		TitleManager();
		~TitleManager();
		virtual void Start() override;
		virtual void Update() override;

	};
}
#endif