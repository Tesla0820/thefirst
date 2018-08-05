//
//		ƒtƒ@ƒCƒ‹–¼:Transform.cpp
//

#include "Transform.h"

namespace GameEngine { namespace Behaviour
{

Transform::Transform()
{

	_position = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	_scale = D3DXVECTOR3(1.0f, 1.0f, 1.0f);
	_rotation = D3DXQUATERNION(0.0f, 0.0f, 0.0f, 1.0f);
}

Transform::~Transform()
{
}

void GameEngine::Behaviour::Transform::SetPosition(D3DXVECTOR3 const* position)
{
	_position = *position;
}

void Transform::SetScale(D3DXVECTOR3 const* scale)
{
	_scale = *scale;
}

void Transform::SetRotation(D3DXQUATERNION const* rotation)
{
	_rotation = *rotation;
}

D3DXVECTOR3 Transform::GetPosition()
{
	return _position;
}

D3DXVECTOR3 Transform::GetScale()
{
	return _scale;
}

D3DXQUATERNION Transform::GetRotation()
{
	return _rotation;
}

D3DXMATRIX Transform::GetMatrix()
{
	D3DXMATRIX rotationMatrix, current;
	D3DXMatrixRotationQuaternion(&rotationMatrix, &_rotation);
	current._11 = _scale.x * rotationMatrix._11;
	current._12 = _scale.x * rotationMatrix._12;
	current._13 = _scale.x * rotationMatrix._13;

	current._21 = _scale.y * rotationMatrix._21;
	current._22 = _scale.y * rotationMatrix._22;
	current._23 = _scale.y * rotationMatrix._23;

	current._31 = _scale.z * rotationMatrix._31;
	current._32 = _scale.z * rotationMatrix._32;
	current._33 = _scale.z * rotationMatrix._33;

	current._41 = _position.x;
	current._42 = _position.y;
	current._43 = _position.z;

	current._14 = current._24 = current._34 = 0.0f;
	current._44 = 1.0f;
	return current;
}

}
}