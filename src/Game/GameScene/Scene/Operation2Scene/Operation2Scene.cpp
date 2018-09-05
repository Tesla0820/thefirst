//
//		ファイル名:Operation2Scene.cpp
//

#include "Operation2Scene.h"
#include "../../../../GameEngine/GameEngine.h"
#include "../../../Common/Pipeline/Echo.h"
#include "Operation2Manager.h"
#include "../../../Common/Fade.h"
#include "../../../Common/Flash.h"

namespace Game { namespace GameScene { namespace Scene
{

bool Operation2Scene::Init()
{
	Fade::StartFadeIn();

	using Texture = GameEngine::Resource::Texture;
	using ResourceManager = GameEngine::Resource::ResourceManager;


	// 操作説明画面
	GameEngine::GameObject* operationObject = GameEngine::GameObject::Instantiate();
	operationObject->GetTransform()->SetPosition(&D3DXVECTOR3(800.0f, 600.0f, 0.0f));
	operationObject->GetTransform()->SetScale(&D3DXVECTOR3(1600.0f, 1200.0f, 50.0f));
	auto operationRenderer = new GameEngine::Behaviour::UIRenderer(GameEngine::Resource::ResourceManager::Get<Texture>("./data/texture/operation2.png"));
	operationRenderer->SetColor(D3DCOLOR_ARGB(255, 255, 255, 255));
	operationObject->AddBehaviour(operationRenderer);

	// マネージャー用
	GameEngine::GameObject* operationManagerObject = GameEngine::GameObject::Instantiate();
	operationManagerObject->GetTransform()->SetPosition(&D3DXVECTOR3(600.0f, 800.0f, 0.0f));
	operationManagerObject->GetTransform()->SetScale(&D3DXVECTOR3(100.0f, 100.0f, 50.0f));
	auto operationManager = new Game::GameScene::Scene::Operation2Manager();
	auto operationManagerSoundPlay = new GameEngine::Behaviour::SoundPlay();
	operationManagerSoundPlay->SetSound(GameEngine::Sound::Sound::CreateFromWaveFile("./data/sound/decision.wav", 0));
	operationManagerObject->AddBehaviour(operationManager);
	operationManagerObject->AddBehaviour(operationManagerSoundPlay);

	// PushEnter用
	GameEngine::GameObject* pushenterObject = GameEngine::GameObject::Instantiate();
	pushenterObject->GetTransform()->SetPosition(&D3DXVECTOR3(1200.0f, 1100.0f, 0.0f));
	pushenterObject->GetTransform()->SetScale(&D3DXVECTOR3(800.0f, 600.0f, 50.0f));
	auto flash = new Game::Flash();
	auto pushenterRenderer = new GameEngine::Behaviour::UIRenderer(GameEngine::Resource::ResourceManager::Get<Texture>("./data/texture/pushenterB.png"));
	pushenterObject->AddBehaviour(flash);
	pushenterRenderer->SetColor(D3DCOLOR_ARGB(255, 255, 255, 255));
	pushenterObject->AddBehaviour(pushenterRenderer);

	// フェード用
	GameEngine::GameObject* fadeObject = GameEngine::GameObject::Instantiate();
	fadeObject->GetTransform()->SetPosition(&D3DXVECTOR3(800.0f, 600.0f, 0.0f));
	fadeObject->GetTransform()->SetScale(&D3DXVECTOR3(1600.0f, 1200.0f, 50.0f));
	auto fade = new Game::Fade();
	auto fadeRenderer = new GameEngine::Behaviour::UIRenderer();
	fadeRenderer->SetColor(D3DCOLOR_ARGB(255, 0, 0, 0));
	fadeObject->AddBehaviour(fadeRenderer);
	fadeObject->AddBehaviour(fade);
	return false;
}

}
}
}