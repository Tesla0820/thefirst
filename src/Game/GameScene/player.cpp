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
	D3DXVECTOR3 vec = {0.0f,0.0f,0.0f};
	D3DXMATRIX matrix = _transform->GetMatrix();
	D3DXVECTOR3 up
	{
		-matrix._32,
		-matrix._22,
		-matrix._12,
	};
	D3DXVECTOR3 front =
	{ 
		-matrix._31,
		-matrix._21,
		-matrix._11,

	};
	D3DXVECTOR3 left =
	{
		matrix._33,
		matrix._23,
		matrix._13,
	};

	D3DXVec3Normalize(&front,&front);

	D3DXVec3Normalize(&left, &left);
	// �ړ��iW,A,S,D�j
	if (GameEngine::Input::GetKey(DIKEYBOARD_A, HOLD))
	{
		vec -= left;
	}
	else if (GameEngine::Input::GetKey(DIKEYBOARD_D, HOLD))
	{
		vec += left;
	}
	if (GameEngine::Input::GetKey(DIKEYBOARD_W, HOLD))
	{
		vec -= front;
	}
	else if (GameEngine::Input::GetKey(DIKEYBOARD_S, HOLD))
	{
		vec += front;
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