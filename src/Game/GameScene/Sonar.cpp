//
//		ƒtƒ@ƒCƒ‹–¼:Sonar.cpp
//

#include "Sonar.h"

namespace Game { namespace GameScene
{

void Sonar::Start()
{
	_collider = GetAttachedObject()->FindBehaviour<GameEngine::Behaviour::SphereCollider>();
	SonarDisable();
}

void Sonar::Update()
{
	if (!_isUsing) return;

	_time++;
	_collider->SetRadius(_time);
	_collider->HitAll();
	if (_time < maxTime) return;
	SonarDisable();
}

void Sonar::SonarEnable()
{
	_collider->SetBehaviourEnable(true);
	_isUsing = true;
}

void Sonar::SonarDisable()
{
	_time = 0;
	_collider->SetBehaviourEnable(false);
	_isUsing = false;
	_collider->SetRadius(_time);
}


bool Sonar::Ping(GameEngine::GameObject * origin)
{
	if (_isUsing)
	{
		return false;
	}
	D3DXVECTOR3 front(0.0f, 0.0f, -1.0f);
	auto transform = origin->GetTransform();
	_position = transform->GetWorldPosition();
	_direction = transform->Front();

	float halfAngle = D3DXVec3Dot(&_direction, &front) / 2.0f;

	D3DXVECTOR3 axis;
	D3DXVec3Cross(&axis, &front, &_direction);
	D3DXVec3Normalize(&axis, &axis);

	float s = std::sinf(halfAngle);
	float c = std::cosf(halfAngle);
	D3DXQUATERNION rot;
	rot.x = axis.x*s;
	rot.y = axis.y*s;
	rot.z = axis.z*s;
	rot.w = c;

	auto me = GetAttachedObject()->GetTransform();
	me->Offset(&(transform->GetWorldPosition() - me->GetWorldPosition()));
	me->SetRotation(&rot);

	SonarEnable();
	auto pipeline = GameEngine::Environment::Get()->GetCurrentPipeline();
	pipeline->SetSonar(_position, _direction);
	pipeline->setRange((float)_time);
	return true;
}

}
}