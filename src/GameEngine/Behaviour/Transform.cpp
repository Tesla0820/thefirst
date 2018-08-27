//
//		ƒtƒ@ƒCƒ‹–¼:Transform.cpp
//

#include "Transform.h"
#include "../GameObject.h"

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

D3DXVECTOR3 Transform::GetWorldPosition()
{
	D3DXMATRIX world=GetWorldMatrix();
	return D3DXVECTOR3(world._41, world._42, world._43);
}

D3DXVECTOR3 Transform::GetScale()
{
	return _scale;
}

D3DXVECTOR3 Transform::Up()
{
	D3DMATRIX world = GetWorldMatrix();
	D3DXVECTOR3 vec = D3DXVECTOR3(-world._32,-world._22, -world._12);
	D3DXVec3Normalize(&vec, &vec);
	return vec;
}

D3DXVECTOR3 Transform::Down()
{
	D3DMATRIX world = GetWorldMatrix();
	D3DXVECTOR3 vec = D3DXVECTOR3(world._32, world._22, world._12);
	D3DXVec3Normalize(&vec, &vec);
	return vec;
}

D3DXVECTOR3 Transform::Left()
{
	D3DMATRIX world = GetWorldMatrix();
	D3DXVECTOR3 vec = D3DXVECTOR3(-world._33, -world._23, -world._13);
	D3DXVec3Normalize(&vec, &vec);
	return vec;
}

D3DXVECTOR3 Transform::Right()
{
	D3DMATRIX world = GetWorldMatrix();
	D3DXVECTOR3 vec = D3DXVECTOR3(world._33, world._23, world._13);
	D3DXVec3Normalize(&vec, &vec);
	return vec;
}

D3DXVECTOR3 Transform::Front()
{
	D3DMATRIX world = GetWorldMatrix();
	D3DXVECTOR3 vec = D3DXVECTOR3(world._31, world._21, world._11);
	D3DXVec3Normalize(&vec, &vec);
	return vec;
}

D3DXVECTOR3 Transform::Back()
{
	D3DMATRIX world = GetWorldMatrix();
	D3DXVECTOR3 vec = D3DXVECTOR3(-world._31, -world._21, -world._11);
	D3DXVec3Normalize(&vec, &vec);
	return vec;
}

D3DXVECTOR3 Transform::CalcDirection(D3DXVECTOR3 const * direction)
{
	D3DXMATRIX world = GetWorldMatrix();
	D3DXVECTOR3 vec
	(
		world._11 * direction->x + world._12 * direction->y + world._13 * direction->z,
		world._21 * direction->x + world._22 * direction->y + world._23 * direction->z,
		world._31 * direction->x + world._32 * direction->y + world._33 * direction->z
	);
	D3DXVec3Normalize(&vec,&vec);
	return vec;
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

D3DXMATRIX Transform::GetWorldMatrix()
{
	D3DXMATRIX current = GetMatrix();
	GameObject* attached = GetAttachedObject();
	if (!attached) return current;
	GameObject* parent = attached->GetParent();
	if (!parent) return current;
	D3DXMATRIX world = parent->GetTransform()->GetWorldMatrix();
	D3DXMatrixMultiply(&current, &current, &world);
	return current;
	
}

void Transform::Offset(D3DXVECTOR3 const * position)
{
	_position += *position;
}

}
}