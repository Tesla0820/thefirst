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

class UIgauge :public GameEngine::Behaviour::Behaviour
{

private:
	bool _isHoverGauge;
	float _len;
	Player* _player;
	GameEngine::Behaviour::Transform* _transform;
	D3DXVECTOR3 origin;

	static constexpr float MaxGauge = 333.0f;
public:
	UIgauge(bool isHoverGauge);
	virtual void Start() override;
	virtual void Update() override;
	Player* GetPlayer();
	void SetPlayer(Player* player);

};
}
}
}
#endif