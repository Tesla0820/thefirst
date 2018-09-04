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

	auto sonarSoundPlay = new GameEngine::Behaviour::SoundPlay();
	auto landingSoundPlay = new GameEngine::Behaviour::SoundPlay();
	auto deadSoundPlay = new GameEngine::Behaviour::SoundPlay();
	auto hoverSoundPlay = new GameEngine::Behaviour::SoundPlay();
	sonarSoundPlay->SetSound(GameEngine::Sound::Sound::CreateFromWaveFile("./data/sound/sonar.wav", 0));
	landingSoundPlay->SetSound(GameEngine::Sound::Sound::CreateFromWaveFile("./data/sound/landing.wav", 0));
	deadSoundPlay->SetSound(GameEngine::Sound::Sound::CreateFromWaveFile("./data/sound/dead.wav", 0));
	hoverSoundPlay->SetSound(GameEngine::Sound::Sound::CreateFromWaveFile("./data/sound/decision.wav",0));
	object->AddBehaviour(sonarSoundPlay);
	object->AddBehaviour(landingSoundPlay);
	object->AddBehaviour(deadSoundPlay);
	object->AddBehaviour(hoverSoundPlay);


	return object;
}

GameEngine::GameObject* GameFactory::CreateFade()
{
	GameEngine::GameObject* FadeObject = GameEngine::GameObject::Instantiate();
	FadeObject->GetTransform()->SetPosition(&D3DXVECTOR3(400.0f, 300.0f, 0.0f));
	FadeObject->GetTransform()->SetScale(&D3DXVECTOR3(800.0f, 600.0f, 1.0f));
	auto fade = new Game::Fade();
	auto FadeRenderer = new GameEngine::Behaviour::UIRenderer();
	FadeRenderer->SetColor(D3DCOLOR_ARGB(255, 0, 0, 0));
	FadeObject->AddBehaviour(FadeRenderer);
	FadeObject->AddBehaviour(fade);
	return FadeObject;
}

GameEngine::GameObject* GameFactory::CreateUIgauge()
{
	// UIゲージ
	GameEngine::GameObject* uiObject = GameEngine::GameObject::Instantiate();
	auto uigauge = new Game::GameScene::Behaviour::UIgauge();
	auto gaugeRenderer = new GameEngine::Behaviour::UIRenderer();
	uiObject->GetTransform()->SetPosition(&D3DXVECTOR3(150.0f, 10.0f, 0.0f));
	uiObject->GetTransform()->SetScale(&D3DXVECTOR3(200.0f, 50.0f, 0.0f));
	gaugeRenderer->SetColor(D3DCOLOR_ARGB(255, 230, 0, 0));
	uiObject->AddBehaviour(uigauge);
	uiObject->AddBehaviour(gaugeRenderer);

	return uiObject;
}

GameEngine::GameObject* GameFactory::CreateUIgaugeEdge()
{
	GameEngine::GameObject* object = GameEngine::GameObject::Instantiate();
	object->GetTransform()->SetPosition(&D3DXVECTOR3(400.0f, 300.0f, 0.0f));
	object->GetTransform()->SetScale(&D3DXVECTOR3(800.0f, 600.0f, 50.0f));
	auto uiRenderer = new GameEngine::Behaviour::UIRenderer(GameEngine::Resource::ResourceManager::Get<GameEngine::Resource::Texture>("./data/texture/UIgauge.png"));
	uiRenderer->SetColor(D3DCOLOR_ARGB(255, 255, 255, 255));
	object->AddBehaviour(uiRenderer);
	return object;
}

}
}