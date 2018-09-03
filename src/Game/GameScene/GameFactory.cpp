#include "GameFactory.h"
#include "../../GameEngine/GameEngine.h"
#include "Behaviour/Sonar.h"
#include "Behaviour/player.h"
#include "Behaviour/UIgauge.h"

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


GameEngine::GameObject* GameFactory::CreateUIgauge()
{
	// UIƒQ[ƒW—p
	GameEngine::GameObject* uiObject = GameEngine::GameObject::Instantiate();
	auto uigauge = new Game::GameScene::Behaviour::UIgauge();
	auto gaugeRenderer = new GameEngine::Behaviour::UIRenderer();
	uiObject->GetTransform()->SetPosition(&D3DXVECTOR3(150.0f, 10.0f, 0.0f));
	uiObject->GetTransform()->SetScale(&D3DXVECTOR3(200.0f, 50.0f, 0.0f));
	gaugeRenderer->SetColor(D3DCOLOR_ARGB(255, 0, 230, 0));
	uiObject->AddBehaviour(uigauge);
	uiObject->AddBehaviour(gaugeRenderer);

	return uiObject;
}

}
}