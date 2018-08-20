//
//		�t�@�C����: player.cpp
//

#include "player.h"
#include "../../GameEngine/Input.h"
#include "../../GameEngine/GameEngine.h"

namespace Game
{
#define PLAYER_SPEED (4.0f)

	Player* g_player;

	//===================================================
	// �R���X�g���N�^
	//===================================================
	Player::Player()
	{
		this->_pos.x = 0.0f;
		this->_pos.y = 0.0f;
		this->_pos.z = 0.0f;

	}
	// ��������i�v���C���[�̍��W�j
	Player::Player(D3DXVECTOR3(pos))
	{
		this->_pos.x = pos.x;
		this->_pos.y = pos.y;
		this->_pos.z = pos.z;
	}

	//====================================================
	// �f�X�g���N�^
	//====================================================
	Player::~Player()
	{
		delete g_player;
	}

	//======================================================
	// ����������
	//======================================================
	void Player::Start()
	{
		g_player = new Player;
		this->GetAttachedObject()->AddBehaviour(this);
	}

	//=======================================================
	// �X�V����
	//=======================================================
	void Player::Update()
	{
		// �ړ��iW,A,S,D�j
		if (GameEngine::Input::GetKey(DIKEYBOARD_A, HOLD))
		{
			this->_pos.x -= PLAYER_SPEED;
		}
		if (GameEngine::Input::GetKey(DIKEYBOARD_D, HOLD))
		{
			this->_pos.x += PLAYER_SPEED;
		}

		if (GameEngine::Input::GetKey(DIKEYBOARD_W, HOLD))
		{
			this->_pos.z += PLAYER_SPEED;
		}
		if (GameEngine::Input::GetKey(DIKEYBOARD_S, HOLD))
		{
			this->_pos.z -= PLAYER_SPEED;
		}
		
		// ���W�̍X�V
		this->GetAttachedObject()->GetTransform()->SetPosition(&this->_pos);
		
	}

	//=========================================================
	// �v���C���[���̎󂯓n��
	//=========================================================
	Player* Player::GetPlayer()
	{
		return this;
	}


}