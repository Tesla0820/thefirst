//
//		ファイル名:TitleScene.cpp
//

#include "OperationScene.h"
#include "../../../../GameEngine/GameEngine.h"
#include "../../../Common/Pipeline/Echo.h"
#include "OperationManager.h"
#include "../../../Common/Fade.h"
#include "../../../Common/Flash.h"

namespace Game { namespace GameScene { namespace Scene
{

OperationScene::OperationScene()
{

}

OperationScene::~OperationScene()
{
	SAFE_DELETE(farre);
}

bool OperationScene::Init()
{
	Fade::StartFadeIn();

	using Texture = GameEngine::Resource::Texture;
	using ResourceManager = GameEngine::Resource::ResourceManager;

	// 操作説明画面の背景
	GameEngine::GameObject* backgrounsObject = GameEngine::GameObject::Instantiate();
	backgrounsObject->GetTransform()->SetPosition(&D3DXVECTOR3(400.0f, 300.0f, 0.0f));
	backgrounsObject->GetTransform()->SetScale(&D3DXVECTOR3(800.0f, 600.0f, 50.0f));
	auto backgrounsRenderer = new GameEngine::Behaviour::UIRenderer(/*GameEngine::Resource::ResourceManager::Get<Texture>("./data/texture/test.png")*/);
	backgrounsRenderer->SetColor(D3DCOLOR_ARGB(255, 255, 255, 255));
	backgrounsObject->AddBehaviour(backgrounsRenderer);

	// 操作説明画面
	GameEngine::GameObject* operationObject = GameEngine::GameObject::Instantiate();
	operationObject->GetTransform()->SetPosition(&D3DXVECTOR3(400.0f, 200.0f, 0.0f));
	operationObject->GetTransform()->SetScale(&D3DXVECTOR3(800.0f, 400.0f, 50.0f));
	auto operationRenderer = new GameEngine::Behaviour::UIRenderer(GameEngine::Resource::ResourceManager::Get<Texture>("./data/texture/operation.png"));
	operationRenderer->SetColor(D3DCOLOR_ARGB(255, 0, 0, 0));
	operationObject->AddBehaviour(operationRenderer);

	// マネージャー用
	GameEngine::GameObject* operationManagerObject = GameEngine::GameObject::Instantiate();
	operationManagerObject->GetTransform()->SetPosition(&D3DXVECTOR3(300.0f, 400.0f, 0.0f));
	operationManagerObject->GetTransform()->SetScale(&D3DXVECTOR3(50.0f, 50.0f, 50.0f));
	auto operationManager = new Game::GameScene::Scene::OperationManager();
	auto operationManagerSoundPlay = new GameEngine::Behaviour::SoundPlay();
	auto operationManagerSoundPlay2 = new GameEngine::Behaviour::SoundPlay();
	operationManagerSoundPlay->SetSound(GameEngine::Sound::Sound::CreateFromWaveFile("./data/sound/title.wav", XAUDIO2_LOOP_INFINITE));
	operationManagerSoundPlay2->SetSound(GameEngine::Sound::Sound::CreateFromWaveFile("./data/sound/decision.wav", XAUDIO2_NO_LOOP_REGION));
	operationManagerObject->AddBehaviour(operationManager);
	operationManagerObject->AddBehaviour(operationManagerSoundPlay);
	operationManagerObject->AddBehaviour(operationManagerSoundPlay2);
	operationManagerSoundPlay->Play();


	// PushEnter用
	GameEngine::GameObject* pushenterObject = GameEngine::GameObject::Instantiate();
	pushenterObject->GetTransform()->SetPosition(&D3DXVECTOR3(400.0f, 450.0f, 0.0f));
	pushenterObject->GetTransform()->SetScale(&D3DXVECTOR3(400.0f, 300.0f, 50.0f));
	auto flash = new Game::Flash();
	auto pushenterRenderer = new GameEngine::Behaviour::UIRenderer(GameEngine::Resource::ResourceManager::Get<Texture>("./data/texture/pushenter.png"));
	pushenterObject->AddBehaviour(flash);
	pushenterRenderer->SetColor(D3DCOLOR_ARGB(255, 255, 255, 255));
	pushenterObject->AddBehaviour(pushenterRenderer);

	// フェード用
	GameEngine::GameObject* fadeObject = GameEngine::GameObject::Instantiate();
	fadeObject->GetTransform()->SetPosition(&D3DXVECTOR3(400.0f, 300.0f, 0.0f));
	fadeObject->GetTransform()->SetScale(&D3DXVECTOR3(800.0f, 600.0f, 50.0f));
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