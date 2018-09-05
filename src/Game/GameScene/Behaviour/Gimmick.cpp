//
//		ƒtƒ@ƒCƒ‹–¼: Gimmick.cpp
//
#include "Gimmick.h"
#include "../Behaviour/Sonar.h"
#include "../../Common/MeshRendererEx.h"

namespace Game { namespace Behaviour
{

Gimmick::Gimmick(int maxDuration)
{
    _maxDuration = maxDuration;
}

void Gimmick::Start()
{
    GameEngine::GameObject* object = GetAttachedObject();
	_colliders = object->FindBehaviours<GameEngine::Behaviour::BoxCollider>();
	_renderer = object->FindBehaviour<MeshRendererEx>();
    for (auto iterator = _colliders.begin(); iterator != _colliders.end(); iterator++)
    {
	    (*iterator)->SetHandler(this);
    }
    _duration = 0;
	_number = -1;
    _isShining = false;
}

void Gimmick::Update()
{
	if (!_isShining) return;
	_duration++;
	_renderer->SetRate((_maxDuration -_duration) / (float)_maxDuration);
	if (_duration < _maxDuration)return;
	_duration = 0;
	_isShining = false;

}

void Gimmick::OnCollision(GameEngine::Behaviour::Collider * from)
{
	if (_isShining)return;
	if (from->GetFlag() & 0xff00)
	{
		GameEngine::GameObject* me = GetAttachedObject();
		GameEngine::GameObject* target = from->GetAttachedObject();

		auto meTransform = me->GetTransform();
		auto targetTransform = target->GetTransform();
		D3DXVECTOR3 front = targetTransform->Front();
		D3DXVECTOR3 direction;
		D3DXVec3Subtract(&direction, &meTransform->GetWorldPosition(), &targetTransform->GetWorldPosition());
		D3DXVec3Normalize(&direction, &direction);
		float dot = D3DXVec3Dot(&front, &direction);
		if (dot <= 0.7071) return;

		auto* sonar = from->GetAttachedObject()->FindBehaviour<Game::GameScene::Behaviour::Sonar>();
		int current = sonar->GetCurrentNumber();
		if (_number != current)
		{
			_number = current;
			_isShining = true;
		}
	}
}

}
}