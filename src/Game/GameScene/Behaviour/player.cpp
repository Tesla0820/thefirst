//
//		ファイル名: player.cpp
//

#include "player.h"
#include "../../Common/Fade.h"
#include "../../../GameEngine/Input.h"
#include "../../../GameEngine/GameEngine.h"

namespace Game { namespace GameScene
{

#define PLAYER_SPEED (1.0f)

void Player::Start()
{
	GameEngine::GameObject* object = GetAttachedObject();
	_transform = object->GetTransform();
	_sonar = object->FindBehaviour<Sonar>();
	_soundPlay = object->FindBehaviour<GameEngine::Behaviour::SoundPlay>();
	_sphere = object->FindBehaviour<GameEngine::Behaviour::SphereCollider>();
	_angle = 0.0f;
	_currentFuel= _maxFuel = 90;
	_delay = 0;
	_state = 0;
}

//=======================================================
	// 更新処理
	//=======================================================
void Player::Update()
{
	switch (_state)
	{
		case 0:
			UpdatePlayer();
			break;

		case 1:
			UpdateOver();
			break;

		case 2:
			UpdateClear();
			break;
	}
}

void Player::UpdatePlayer()
{
	D3DXVECTOR3 vec = { 0.0f,0.0f,0.0f };
	D3DXVECTOR3 up = _transform->Up();
	D3DXVECTOR3 front = _transform->Front();
	D3DXVECTOR3 left = _transform->Left();
	// 移動（W,A,S,D）
	if (GameEngine::Input::GetKey(DIKEYBOARD_A, HOLD))
	{
		vec += left;
	}
	else if (GameEngine::Input::GetKey(DIKEYBOARD_D, HOLD))
	{
		vec -= left;
	}
	if (GameEngine::Input::GetKey(DIKEYBOARD_W, HOLD))
	{
		vec += front;
	}
	else if (GameEngine::Input::GetKey(DIKEYBOARD_S, HOLD))
	{
		vec -= front;
	}

	if (_delay)
	{
		_delay--;
	}
	else if (_currentFuel < _maxFuel)
	{
		_currentFuel++;
	}

	if (GameEngine::Input::GetKey(DIKEYBOARD_SPACE, HOLD) && _currentFuel)
	{
		_delay = 30;
		_currentFuel--;
		vec -= up;
	}
	else
	{
		vec += up;
	}

	if (GameEngine::Input::GetKey(DIKEYBOARD_Z, TRIGGER))
	{
		if (_sonar->Ping())
		{
			_soundPlay->Play();
		}
	}

	// 座標の更新
	_transform->Offset(&vec);

	if (GameEngine::Input::GetKey(DIKEYBOARD_LEFT, HOLD))
	{
		_angle -= 0.05f;
	}
	else if (GameEngine::Input::GetKey(DIKEYBOARD_RIGHT, HOLD))
	{
		_angle += 0.05f;
	}


	D3DXQUATERNION rot;
	D3DXQuaternionRotationYawPitchRoll(&rot, _angle, 0.0f, 0.0f);
	_transform->SetRotation(&rot);
	_sphere->HitAll();
}

void Player::UpdateClear()
{
	if (Fade::EndFadeOut())
	{
		GameEngine::Scene::SceneManager::LoadScene(6);
	}
}

void Player::UpdateOver()
{
	if (Fade::EndFadeOut())
	{
		GameEngine::Scene::SceneManager::LoadScene(7);
	}
}


void Player::OnCollision(GameEngine::Behaviour::Collider * from)
{
	if (_state != 0)return;
	int flag = from->GetFlag();
	if (flag & 0x0002)
	{
		//ゲームオーバー
		_state = 1;
		Fade::StartFadeOut();
	}
	else if (flag & 0x0008)
	{
		_state = 2;
		Fade::StartFadeOut();
	}
}

}
}