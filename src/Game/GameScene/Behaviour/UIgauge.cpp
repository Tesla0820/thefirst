//
//		�t�@�C����:UIgauge.cpp
//

#include "UIgauge.h"
#include "../../../GameEngine/GameEngine.h"
#include "../../../GameEngine/Input.h"
#include "../../../GameEngine/Scene/SceneManager.h"

namespace Game { namespace GameScene { namespace Behaviour
{

UIgauge::UIgauge(bool isHoverGauge)
{
	_isHoverGauge = isHoverGauge;
}

//===============================================
// ����������
//===============================================
void UIgauge::Start()
{
	_len = 0.0f;
	_transform = this->GetAttachedObject()->GetTransform();
	origin=_transform->GetPosition();
}

//=================================================
// �X�V����
//=================================================
void UIgauge::Update()
{
	if (!_player) return;
	if (_isHoverGauge)
	{
		_len = MaxGauge * _player->GetHoverRate();
	}
	else
	{
		_len = MaxGauge * _player->GetSonarRate();
	}

	_transform->SetPosition(&D3DXVECTOR3(origin.x - (MaxGauge - _len / 2.0f),origin.y, 0.0f));
	_transform->SetScale(&D3DXVECTOR3(_len, 28.5f, 0.0f));
}

Player* UIgauge::GetPlayer()
{
	return _player;
}

void  UIgauge::SetPlayer(Player* player)
{
	_player = player;
}

}
}
}