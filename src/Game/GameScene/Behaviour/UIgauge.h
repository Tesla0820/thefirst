//
//		ƒtƒ@ƒCƒ‹–¼:UIgauge.h
//

#ifndef HEADER_UIGAUGE_H
#define HEADER_UIGAUGE_H

#include "../../../GameEngine/GameEngine.h"
#include "../../../GameEngine/Behaviour/Behaviour.h"
#include "../Behaviour/player.h"

namespace Game { namespace GameScene { namespace Behaviour
{
#define MAX_GAUGE (333.0f)

	class UIgauge :public GameEngine::Behaviour::Behaviour
	{

	private:
		float _len;
		Game::GameScene::Player* _player;
		GameEngine::Behaviour::Transform* _transform;
	public:
		UIgauge() = default;
		virtual void Start() override;
		virtual void Update() override;
		Player* GetPlayer();
		void SetPlayer(Game::GameScene::Player*);

	};
}
}
}
#endif