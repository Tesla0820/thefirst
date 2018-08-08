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
	_target = nullptr;
}

void Behaviour::SetTarget(GameEngine::GameObject * target)
{
	Binder::BindBehaviourToGameObject(target, this);
}

GameEngine::GameObject * Behaviour::GetTarget()
{
	return _target;
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