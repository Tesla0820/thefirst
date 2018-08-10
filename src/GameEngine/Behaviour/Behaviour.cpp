//
//		ƒtƒ@ƒCƒ‹–¼:Behaviour.cpp
//

#include "Behaviour.h"
#include "../Scene/SceneManager.h"

namespace GameEngine { namespace Behaviour
{

using GameEngine::Scene::SceneManager;

Behaviour::Behaviour()
{
	_isStarted = false;
	_attached = nullptr;
}

void Behaviour::SetAttachedObject(GameEngine::GameObject * target)
{
	Binder::BindBehaviourToGameObject(target, this);
}

GameEngine::GameObject * Behaviour::GetAttachedObject()
{
	return _attached;
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

Behaviour::~Behaviour()
{
}

}
}