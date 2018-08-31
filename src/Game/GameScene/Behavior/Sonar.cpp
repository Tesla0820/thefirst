//
//		ƒtƒ@ƒCƒ‹–¼:Sonar.cpp
//

#include "Sonar.h"
#include "../../Common/Pipeline/Echo.h"

namespace Game { namespace GameScene
{

void Sonar::Start()
{
	_time = 0;
	_isUsing = false;
}

void Sonar::Update()
{
	if (!_isUsing) return;

	_time++;
	_collider->SetRadius(_time);
	_collider->HitAll();
	auto pipeline = dynamic_cast<Pipeline::Echo*>(GameEngine::Environment::Get()->GetCurrentPipeline());
	pipeline->SetRange(_time/2.0f);
	if (_time < maxTime) return;
	SonarDisable();
}

void Sonar::SonarEnable()
{
	_collider->SetBehaviourEnable(true);
	_isUsing = true;
	_time = 0;
}

void Sonar::SonarDisable()
{
	_time = 0;
	_isUsing = false;
	_collider->SetBehaviourEnable(false);
	_collider->SetRadius(_time);
	auto pipeline = dynamic_cast<Pipeline::Echo*>(GameEngine::Environment::Get()->GetCurrentPipeline());
	pipeline->SetRange(-100);
}


bool Sonar::Ping()
{
	if (_isUsing)
	{
		return false;
	}
	D3DXVECTOR3 front(0.0f, 0.0f, -1.0f);
	auto transform = GetAttachedObject()->GetTransform();
	_position = transform->GetWorldPosition();
	_direction = transform->Front();
	
	//SonarEnable();
	auto pipeline = dynamic_cast<Pipeline::Echo*>(GameEngine::Environment::Get()->GetCurrentPipeline());
	pipeline->SetSonar(_position, _direction);
	pipeline->SetRange((float)_time);
	SonarEnable();
	return true;
}

void Sonar::SetCollider(GameEngine::Behaviour::SphereCollider * collider)
{
	_collider = collider;
	_collider->SetBehaviourEnable(false);
}

}
}