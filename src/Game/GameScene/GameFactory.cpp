#include "GameFactory.h"
#include "../../GameEngine/GameEngine.h"
#include "../Common/Fade.h"
#include "Behaviour/Sonar.h"
#include "Behaviour/player.h"
#include "Behaviour/UIgauge.h"

namespace Game { namespace GameScene
{

GameEngine::GameObject* GameFactory::CreateGround()
{
	GameEngine::GameObject* object = GameEngine::GameObject::Instantiate();
	auto collider = new GameEngine::Behaviour::BoxCollider(D3DXVECTOR3(0.0f,-1.0f,0.0f), D3DXVECTOR3(100.0f, 1.0f, 100.0f),0x0004);
	collider->EnableTrigger(false);
	collider->EnableFreeze(true);
	object->AddBehaviour(collider);
	return object;
}
GameEngine::GameObject* GameFactory::CreatePlayer()
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
	return object;
}

GameEngine::GameObject* GameFactory::CreateFade()
{
	GameEngine::GameObject* FadeObject = GameEngine::GameObject::Instantiate();
	FadeObject->GetTransform()->SetPosition(&D3DXVECTOR3(800.0f, 600.0f, 0.0f));
	FadeObject->GetTransform()->SetScale(&D3DXVECTOR3(1600.0f, 1200.0f, 1.0f));
	auto fade = new Game::Fade();
	auto FadeRenderer = new GameEngine::Behaviour::UIRenderer();
	FadeRenderer->SetColor(D3DCOLOR_ARGB(255, 0, 0, 0));
	FadeObject->AddBehaviour(FadeRenderer);
	FadeObject->AddBehaviour(fade);
	return FadeObject;
}

GameEngine::GameObject * GameFactory::CreateHoverGauge()
{
	// UIゲージ
	GameEngine::GameObject* uiObject = GameEngine::GameObject::Instantiate();
	auto uigauge = new Game::GameScene::Behaviour::UIgauge(true);
	auto gaugeRenderer = new GameEngine::Behaviour::UIRenderer();
	uiObject->GetTransform()->SetPosition(&D3DXVECTOR3(788.0f, 126.0f, 0.0f));
	uiObject->GetTransform()->SetScale(&D3DXVECTOR3(400.0f, 100.0f, 0.0f));
	gaugeRenderer->SetColor(D3DCOLOR_ARGB(255, 0, 230, 0));
	uiObject->AddBehaviour(uigauge);
	uiObject->AddBehaviour(gaugeRenderer);

	return uiObject;
}

GameEngine::GameObject* GameFactory::CreateSonarGauge()
{
	// UIゲージ
	GameEngine::GameObject* uiObject = GameEngine::GameObject::Instantiate();
	auto uigauge = new Game::GameScene::Behaviour::UIgauge(false);
	auto gaugeRenderer = new GameEngine::Behaviour::UIRenderer();
	uiObject->GetTransform()->SetPosition(&D3DXVECTOR3(788.0f, 196.0f, 0.0f));
	uiObject->GetTransform()->SetScale(&D3DXVECTOR3(400.0f, 100.0f, 0.0f));
	gaugeRenderer->SetColor(D3DCOLOR_ARGB(255, 230, 0, 0));
	uiObject->AddBehaviour(uigauge);
	uiObject->AddBehaviour(gaugeRenderer);

	return uiObject;
}

GameEngine::GameObject* GameFactory::CreateUIgaugeEdge()
{
	GameEngine::GameObject* object = GameEngine::GameObject::Instantiate();
	object->GetTransform()->SetPosition(&D3DXVECTOR3(800.0f, 600.0f, 0.0f));
	object->GetTransform()->SetScale(&D3DXVECTOR3(1600.0f, 1200.0f, 50.0f));
	auto uiRenderer = new GameEngine::Behaviour::UIRenderer(GameEngine::Resource::ResourceManager::Get<GameEngine::Resource::Texture>("./data/texture/UIgauge.png"));
	uiRenderer->SetColor(D3DCOLOR_ARGB(255, 255, 255, 255));
	object->AddBehaviour(uiRenderer);
	return object;
}

}
}