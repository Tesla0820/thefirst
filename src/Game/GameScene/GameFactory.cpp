#include "GameFactory.h"
#include "../../GameEngine/GameEngine.h"
#include "Sonar.h"
#include "player.h"

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

}
}