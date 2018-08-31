//
//		ƒtƒ@ƒCƒ‹–¼: Gimmick.cpp
//
#include "Gimmick.h"
#include "../../Common/MeshRendererEx.h"

namespace Game { namespace Behaviour
{

void Gimmick::Start()
{
	GameEngine::GameObject* object;
	_collider = object->FindBehaviour<GameEngine::Behaviour::BoxCollider>();
	_renderer = object->FindBehaviour<MeshRendererEx>();
	_collider->SetHandler(this);
}

void Gimmick::Update()
{
	if (!_isShining) return;
	_duration++;
	_renderer->SetRate((maxDuration-_duration) / (float)maxDuration);
	if (_duration < maxDuration)return;
	_duration = 0;
	_isShining = false;

}

void Gimmick::OnCollision(GameEngine::Behaviour::Collider * from)
{
	if (_isShining)return;
	if (from->GetFlag() & 0xff00)
	{
		_isShining = true;
	}
}

}
}