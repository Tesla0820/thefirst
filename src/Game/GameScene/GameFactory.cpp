#include "GameFactory.h"
#include "../../GameEngine/GameEngine.h"
#include "Behaviour/Sonar.h"
#include "Behaviour/player.h"
#include "../Common/Fade.h"

namespace Game { namespace GameScene
{

void GameFactory::CreateGround()
{
	GameEngine::GameObject* object = GameEngine::GameObject::Instantiate();
	auto collider = new GameEngine::Behaviour::BoxCollider(D3DXVECTOR3(0.0f,-1.0f,0.0f), D3DXVECTOR3(100.0f, 1.0f, 100.0f),0x0004);
	collider->EnableTrigger(false);
	collider->EnableFreeze(true);
	
	object->AddBehaviour(collider);
}
void GameFactory::CreatePlayer()
{
	GameEngine::GameObject* object = GameEngine::GameObject::Instantiate();
	auto camera = new GameEngine::Behaviour::Camera();
	object->AddBehaviour(camera);
	camera->SetCurrent();
	camera->EnablePerspectiveMode(true);
	object->GetTransform()->SetPosition(&D3DXVECTOR3(0.0f, 5.0f, 0.0f));
	object->AddBehaviour(new GameEngine::Behaviour::SoundPlay());
	auto player = new Player();
	object->AddBehaviour(player);
	auto hitCollider = new GameEngine::Behaviour::SphereCollider(0x00ff);
	hitCollider->EnableTrigger(false);
	hitCollider->EnableFreeze(false);
	hitCollider->SetRadius(5.0f);
	hitCollider->SetHandler(player);
	object->AddBehaviour(hitCollider);

	auto sonar = new Sonar();
	auto sonarCollider = new GameEngine::Behaviour::SphereCollider(0xff00);
	sonar->SetCollider(sonarCollider);
	sonarCollider->EnableFreeze(false);
	sonarCollider->EnableTrigger(true);
	object->AddBehaviour(sonarCollider);
	object->AddBehaviour(sonar);

}

void GameFactory::CreateFade()
{
	GameEngine::GameObject* FadeObject = GameEngine::GameObject::Instantiate();
	FadeObject->GetTransform()->SetPosition(&D3DXVECTOR3(400.0f, 300.0f, 0.0f));
	FadeObject->GetTransform()->SetScale(&D3DXVECTOR3(800.0f, 600.0f, 1.0f));
	auto fade = new Game::Fade();
	auto FadeRenderer = new GameEngine::Behaviour::UIRenderer();
	FadeRenderer->SetColor(D3DCOLOR_ARGB(255, 0, 0, 0));
	FadeObject->AddBehaviour(FadeRenderer);
	FadeObject->AddBehaviour(fade);
}

}
}