//
//		ファイル名:Behaviour.cpp
//

#include "Behaviour.h"
#include "../Scene/SceneManager.h"
#include "../../Game/GameScene/player.h"

class Player;

namespace GameEngine { namespace Behaviour
{

using GameEngine::Scene::SceneManager;

Behaviour::Behaviour()
{
	_isDestroyed = false;
	_isStarted = false;
	_enable = true;
	_attached = nullptr;
}

void Behaviour::Attach(GameEngine::GameObject * target)
{
	Binder::BindBehaviourToGameObject(target, this);
}

GameEngine::GameObject * Behaviour::GetAttachedObject()
{
	return _attached;
}

void Behaviour::SetBehaviourEnable(bool enable)
{
	if (_enable == enable) return;
	_enable = enable;
	if (enable)
	{
		OnEnabled();
	}
	else 
	{
		OnDisabled();
	}
}

bool Behaviour::GetBehaviourEnable()
{
	return _enable;
}

bool Behaviour::GetEnable()
{
	bool result = _enable;
	if (_attached)
	{
		result &=_attached->GetEnable();
	}
	return result;
}

void Behaviour::Initialize()
{
	if (_isStarted) return;
	//開始
	Start();
	_isStarted = true;
	//有効化時
	OnEnabled();
}

void Behaviour::OnEnabled()
{
	if (!_isStarted) return;
	if (!_attached) return;
	if (!_enable) return;
	Enabled();
}

void Behaviour::OnDisabled()
{
	if (!_isStarted) return;
	if (!_attached) return;
	if (_enable) return;
	Disabled();
}

void Behaviour::Enabled()
{
}

void Behaviour::Disabled()
{
}


void Behaviour::Start()
{
	
}

void Behaviour::Update()
{

}

void Behaviour::BeforeDraw(D3DXMATRIX const& matrix)
{
}

void Behaviour::Draw(D3DXMATRIX const& matrix)
{
}

void Behaviour::Destroy()
{
	if (_isDestroyed) return;
	_enable = false;
	OnDisabled();
	Attach(nullptr);
	_isDestroyed = true;
}

Behaviour::~Behaviour()
{
	Destroy();
}

}
}