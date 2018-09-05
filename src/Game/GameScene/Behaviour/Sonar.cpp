//
//		ƒtƒ@ƒCƒ‹–¼:Sonar.cpp
//

#include "Sonar.h"
#include "../../Common/Pipeline/Echo.h"

namespace Game { namespace GameScene { namespace Behaviour
{

void Sonar::Start()
{
	_time = maxTime;
	_isUsing = false;
	_number = 0;
}

void Sonar::Update()
{
	if (!_isUsing) return;

	_time++;
	_collider->SetRadius(_time);
	_collider->HitAll();
	auto pipeline = dynamic_cast<Pipeline::Echo*>(GameEngine::Environment::Get()->GetCurrentPipeline());
	pipeline->SetRange(_time);
	if (_time < maxTime) return;
	SonarDisable();
}

void Sonar::SonarEnable()
{
	_number++;
	_collider->SetBehaviourEnable(true);
	_isUsing = true;
	_time = 0;
}

void Sonar::SonarDisable()
{
	_time = maxTime;
	_isUsing = false;
	_collider->SetBehaviourEnable(false);
	_collider->SetRadius(0);
	auto pipeline = dynamic_cast<Pipeline::Echo*>(GameEngine::Environment::Get()->GetCurrentPipeline());
	pipeline->SetRange(-10000);
}


bool Sonar::Ping(D3DXVECTOR3 pos, D3DXQUATERNION rot)
{
	if (_isUsing)
	{
		return false;
	}
	D3DXVECTOR3 front(0.0f, 0.0f, -1.0f);
	auto transform = GetAttachedObject()->GetTransform();
	transform->SetPosition(&pos);
	transform->SetRotation(&rot);
	_position = pos;
	_direction = transform->Front();

	SonarEnable();
	auto pipeline = dynamic_cast<Pipeline::Echo*>(GameEngine::Environment::Get()->GetCurrentPipeline());
	pipeline->SetSonar(_position, _direction);
	pipeline->SetRange((float)_time);
	return true;
}

void Sonar::SetCollider(GameEngine::Behaviour::SphereCollider * collider)
{
	_collider = collider;
	_collider->SetBehaviourEnable(false);
}

float Sonar::GetSonarRate()
{
	return _time / (float)maxTime;
}

int Sonar::GetCurrentNumber()
{
	return _number;
}

}
}
}