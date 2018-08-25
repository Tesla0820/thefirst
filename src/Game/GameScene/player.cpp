//
//		�t�@�C����: player.cpp
//

#include "player.h"
#include "../../GameEngine/Input.h"
#include "../../GameEngine/GameEngine.h"

namespace Game { namespace GameScene
{

#define PLAYER_SPEED (4.0f)

void Player::Start()
{
	_transform = this->GetAttachedObject()->GetTransform();
}

//=======================================================
	// �X�V����
	//=======================================================
void Player::Update()
{
	D3DXVECTOR3 vec = {0.0f,0.0f,0.0f};
	// �ړ��iW,A,S,D�j
	if (GameEngine::Input::GetKey(DIKEYBOARD_A, HOLD))
	{											
		vec.x -= PLAYER_SPEED;					
	}											
	if (GameEngine::Input::GetKey(DIKEYBOARD_D, HOLD))
	{											
		vec.x += PLAYER_SPEED;					
	}											
												
	if (GameEngine::Input::GetKey(DIKEYBOARD_W, HOLD))
	{
		vec.z += PLAYER_SPEED;
	}
	if (GameEngine::Input::GetKey(DIKEYBOARD_S, HOLD))
	{
		vec.z -= PLAYER_SPEED;
	}

	// ���W�̍X�V
	_transform->Offset(&vec);

}

}
}