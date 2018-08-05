//
//		ƒtƒ@ƒCƒ‹–¼:Behaviour.cpp
//

#include "Behaviour.h"

namespace GameEngine { namespace Behaviour
{

Behaviour::Behaviour()
{
	_target = nullptr;
}

void Behaviour::SetTarget(GameEngine::GameObject * target)
{
	_target = target;
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