//
//		�t�@�C����:UIgauge.cpp
//

#include "UIgauge.h"
#include "../../../GameEngine/GameEngine.h"
#include "../../../GameEngine/Input.h"
#include "../../../GameEngine/Scene/SceneManager.h"

namespace Game { namespace GameScene { namespace Behaviour
{
	//===============================================
	// ����������
	//===============================================
	void UIgauge::Start()
	{
		_len = 0.0f;
		_transform = this->GetAttachedObject()->GetTransform();
		_player = nullptr;
	}

	//=================================================
	// �X�V����
	//=================================================
	void UIgauge::Update()
	{
		//_player = 
		_len++;		// ������Get�ɕς���

		if (_len <= 0.0f)
		{
			_len = MAX_GAUGE;
		}

		if (_len >= MAX_GAUGE)
		{
			_len = 0.0f;
		}

		_transform->SetPosition(&D3DXVECTOR3(250.0f - (MAX_GAUGE - _len / 2.0f), 50.0f, 0.0f));
		_transform->SetScale(&D3DXVECTOR3(_len, 30.0f, 0.0f));
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