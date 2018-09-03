//
//		ファイル名:TitleScene.cpp
//

#include "../../GameEngine/GameEngine.h"
#include "../Common/Pipeline/Echo.h"
#include "../Common/Fade.h"
#include "../GameScene/GameFactory.h"
#include "TitleScene.h"
#include "TitleManager.h"

namespace Game
{

TitleScene::TitleScene()
{

}

TitleScene::~TitleScene()
{
	SAFE_DELETE(farre);
}

bool TitleScene::Init()
{

	using Texture = GameEngine::Resource::Texture;
	using ResourceManager	= GameEngine::Resource::ResourceManager;

	
	// 背景の描画
	GameEngine::GameObject* BackgroundObject = GameEngine::GameObject::Instantiate();
	BackgroundObject->GetTransform()->SetPosition(&D3DXVECTOR3(400.0f, 300.0f, 0.0f));
	BackgroundObject->GetTransform()->SetScale(&D3DXVECTOR3(800.0f, 600.0f, 50.0f));
	auto backGroundRenderer = new GameEngine::Behaviour::UIRenderer(ResourceManager::Get<Texture>("./data/texture/titlebackground.png"));
	backGroundRenderer->SetColor(D3DCOLOR_ARGB(255, 255, 255, 255));
	BackgroundObject->AddBehaviour(backGroundRenderer);


	GameEngine::GameObject* titleManagerObject = GameEngine::GameObject::Instantiate();
	titleManagerObject->GetTransform()->SetPosition(&D3DXVECTOR3(300.0f, 400.0f, 0.0f));
	titleManagerObject->GetTransform()->SetScale(&D3DXVECTOR3(50.0f, 50.0f, 50.0f));
	auto titleManager = new Game::TitleManager();
	auto titleManagerRenderer = new GameEngine::Behaviour::UIRenderer(ResourceManager::Get<Texture>("./data/texture/select.png"));
	auto titleManagerSoundPlay = new GameEngine::Behaviour::SoundPlay();
	auto titleManagerSoundPlay2 = new GameEngine::Behaviour::SoundPlay();
	auto titleManagerSoundPlay3 = new GameEngine::Behaviour::SoundPlay();
	titleManagerRenderer->SetColor(D3DCOLOR_ARGB(255, 255, 255, 255));
	titleManagerSoundPlay->SetSound(GameEngine::Sound::Sound::CreateFromWaveFile("./data/sound/title.wav",XAUDIO2_LOOP_INFINITE));
	titleManagerSoundPlay2->SetSound(GameEngine::Sound::Sound::CreateFromWaveFile("./data/sound/title.wav", XAUDIO2_LOOP_INFINITE));
	titleManagerSoundPlay3->SetSound(GameEngine::Sound::Sound::CreateFromWaveFile("./data/sound/title.wav", XAUDIO2_LOOP_INFINITE));

	titleManagerObject->AddBehaviour(titleManagerRenderer);
	titleManagerObject->AddBehaviour(titleManager);
	titleManagerObject->AddBehaviour(titleManagerSoundPlay);
	titleManagerObject->AddBehaviour(titleManagerSoundPlay2);
	titleManagerObject->AddBehaviour(titleManagerSoundPlay3);
	titleManagerSoundPlay->Play();

	// タイトルの描画
	GameEngine::GameObject* titleObject = GameEngine::GameObject::Instantiate();
	titleObject->GetTransform()->SetPosition(&D3DXVECTOR3(400.0f, 300.0f, 0.0f));
	titleObject->GetTransform()->SetScale(&D3DXVECTOR3(600.0f, 150.0f, 50.0f));
	auto titleRenderer = new GameEngine::Behaviour::UIRenderer(GameEngine::Resource::ResourceManager::Get<Texture>("./data/texture/title.png"));
	titleRenderer->SetColor(D3DCOLOR_ARGB(255, 255, 255, 255));
	titleObject->AddBehaviour(titleRenderer);

	// チュートリアルの文字の表示
	GameEngine::GameObject* stageObject = GameEngine::GameObject::Instantiate();
	stageObject->GetTransform()->SetPosition(&D3DXVECTOR3(400.0f, 400.0f, 0.0f));
	stageObject->GetTransform()->SetScale(&D3DXVECTOR3(250.0f, 70.0f, 50.0f));
	auto stageRenderer = new GameEngine::Behaviour::UIRenderer(GameEngine::Resource::ResourceManager::Get<Texture>("./data/texture/tutorial.png"));
	stageRenderer->SetColor(D3DCOLOR_ARGB(255, 255, 255, 255));
	stageObject->AddBehaviour(stageRenderer);

	// ステージ１の文字の表示
	GameEngine::GameObject* stageObject2 = GameEngine::GameObject::Instantiate();
	stageObject2->GetTransform()->SetPosition(&D3DXVECTOR3(400.0f, 450.0f, 0.0f));
	stageObject2->GetTransform()->SetScale(&D3DXVECTOR3(250.0f, 70.0f, 50.0f));
	auto stageRenderer2 = new GameEngine::Behaviour::UIRenderer(GameEngine::Resource::ResourceManager::Get<Texture>("./data/texture/stage1.png"));
	stageRenderer2->SetColor(D3DCOLOR_ARGB(255, 255, 255, 255));
	stageObject2->AddBehaviour(stageRenderer2);

	// ステージ２の文字の表示
	GameEngine::GameObject* stageObject3 = GameEngine::GameObject::Instantiate();
	stageObject3->GetTransform()->SetPosition(&D3DXVECTOR3(400.0f, 500.0f, 0.0f));
	stageObject3->GetTransform()->SetScale(&D3DXVECTOR3(250.0f, 70.0f, 50.0f));
	auto stageRenderer3 = new GameEngine::Behaviour::UIRenderer(GameEngine::Resource::ResourceManager::Get<Texture>("./data/texture/stage2.png"));
	stageRenderer3->SetColor(D3DCOLOR_ARGB(255, 255, 255, 255));
	stageObject3->AddBehaviour(stageRenderer3);

	// ステージ３の文字の表示
	GameEngine::GameObject* stageObject4 = GameEngine::GameObject::Instantiate();
	stageObject4->GetTransform()->SetPosition(&D3DXVECTOR3(400.0f, 550.0f, 0.0f));
	stageObject4->GetTransform()->SetScale(&D3DXVECTOR3(250.0f, 70.0f, 50.0f));
	auto stageRenderer4 = new GameEngine::Behaviour::UIRenderer(GameEngine::Resource::ResourceManager::Get<Texture>("./data/texture/stage3.png"));
	stageRenderer4->SetColor(D3DCOLOR_ARGB(255, 255, 255, 255));
	stageObject4->AddBehaviour(stageRenderer4);

	//フェード
	Game::GameScene::GameFactory::CreateFade();
	return false;
}


}