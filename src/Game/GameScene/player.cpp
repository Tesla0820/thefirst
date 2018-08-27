//
//		�t�@�C����: player.cpp
//

#include "player.h"
#include "../../GameEngine/Input.h"
#include "../../GameEngine/GameEngine.h"

namespace Game { namespace GameScene
{

#define PLAYER_SPEED (1.0f)

void Player::Start()
{
	GameEngine::GameObject* object = GetAttachedObject();
	angle = 0.0f;
	_transform = object->GetTransform();
	_sphere = object->FindBehaviour<GameEngine::Behaviour::SphereCollider>();
	currentFuel= maxFuel = 90;
	delay = 0;
}

//=======================================================
	// �X�V����
	//=======================================================
void Player::Update()
{
	D3DXVECTOR3 vec = { 0.0f,0.0f,0.0f };
	D3DXVECTOR3 up = _transform->Up();
	D3DXVECTOR3 front = _transform->Front();
	D3DXVECTOR3 left = _transform->Left();
	// �ړ��iW,A,S,D�j
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

	if (delay)
	{
		delay--;
	}
	else if (currentFuel < maxFuel)
	{
		currentFuel++;
	}

	if (GameEngine::Input::GetKey(DIKEYBOARD_SPACE, HOLD) && currentFuel)
	{
		delay = 30;
		currentFuel--;
		vec -= up;
	}
	else
	{
		vec += up;
	}

	// ���W�̍X�V
	_transform->Offset(&vec);

	if (GameEngine::Input::GetKey(DIKEYBOARD_LEFT, HOLD))
	{
		angle -= 0.05;
	}
	else if (GameEngine::Input::GetKey(DIKEYBOARD_RIGHT, HOLD))
	{
		angle += 0.05;
	}


	D3DXQUATERNION rot;
	D3DXQuaternionRotationYawPitchRoll(&rot, angle, 0.0f, 0.0f);
	_transform->SetRotation(&rot);
	_sphere->Hit();
}

}
}