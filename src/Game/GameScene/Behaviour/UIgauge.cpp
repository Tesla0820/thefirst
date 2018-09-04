//
//		ファイル名:UIgauge.cpp
//

#include "UIgauge.h"
#include "../../../GameEngine/GameEngine.h"
#include "../../../GameEngine/Input.h"
#include "../../../GameEngine/Scene/SceneManager.h"

namespace Game { namespace GameScene { namespace Behaviour
{
	//===============================================
	// 初期化処理
	//===============================================
	void UIgauge::Start()
	{
		_len = 0.0f;
		_transform = this->GetAttachedObject()->GetTransform();
	}

	//=================================================
	// 更新処理
	//=================================================
	void UIgauge::Update()
	{
		if (!_player) return;

		_len = MAX_GAUGE * _player->GetSonarRate();

		_transform->SetPosition(&D3DXVECTOR3(394.0f - (MAX_GAUGE - _len / 2.0f), 98.0f, 0.0f));
		_transform->SetScale(&D3DXVECTOR3(_len, 28.5f, 0.0f));
	}

	Player* UIgauge::GetPlayer()
	{
		return _player;
	}

	void  UIgauge::SetPlayer(Game::GameScene::Player* player)
	{
		_player = player;
	}
}
}
}