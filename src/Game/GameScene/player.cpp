//
//		ファイル名: player.cpp
//

#include "player.h"
#include "../../GameEngine/Input.h"
#include "../../GameEngine/GameEngine.h"

namespace Game
{
#define PLAYER_SPEED (4.0f)

	Player* g_player;

	//===================================================
	// コンストラクタ
	//===================================================
	Player::Player()
	{
		this->_pos.x = 0.0f;
		this->_pos.y = 0.0f;
		this->_pos.z = 0.0f;

	}
	// 引数あり（プレイヤーの座標）
	Player::Player(D3DXVECTOR3(pos))
	{
		this->_pos.x = pos.x;
		this->_pos.y = pos.y;
		this->_pos.z = pos.z;
	}

	//====================================================
	// デストラクタ
	//====================================================
	Player::~Player()
	{
		delete g_player;
	}

	//======================================================
	// 初期化処理
	//======================================================
	void Player::Start()
	{
		g_player = new Player;
		this->GetAttachedObject()->AddBehaviour(this);
	}

	//=======================================================
	// 更新処理
	//=======================================================
	void Player::Update()
	{
		// 移動（W,A,S,D）
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
		
		// 座標の更新
		this->GetAttachedObject()->GetTransform()->SetPosition(&this->_pos);
		
	}

	//=========================================================
	// プレイヤー情報の受け渡し
	//=========================================================
	Player* Player::GetPlayer()
	{
		return this;
	}


}