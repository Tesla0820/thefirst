//
//		ファイル名: player.cpp
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
	// 更新処理
	//=======================================================
void Player::Update()
{
	D3DXVECTOR3 vec = {0.0f,0.0f,0.0f};
	// 移動（W,A,S,D）
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

	// 座標の更新
	_transform->Offset(&vec);

}

}
}