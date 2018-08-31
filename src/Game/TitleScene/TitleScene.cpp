//
//		ファイル名:TitleScene.cpp
//

#include "TitleScene.h"
#include "../../GameEngine/GameEngine.h"
#include "../Common/Pipeline/Echo.h"
#include "TitleManager.h"
#include "../Common/Fade.h"

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
	Fade::StartFadeIn();

	using Texture = GameEngine::Resource::Texture;
	using ResourceManager	= GameEngine::Resource::ResourceManager;

	// 背景の描画
	GameEngine::GameObject* BackgroundObject = GameEngine::GameObject::Instantiate();
	BackgroundObject->GetTransform()->SetPosition(&D3DXVECTOR3(400.0f, 300.0f, 0.0f));
	BackgroundObject->GetTransform()->SetScale(&D3DXVECTOR3(800.0f, 600.0f, 50.0f));
	auto backGroundRenderer = new GameEngine::Behaviour::UIRenderer(GameEngine::Resource::ResourceManager::Get<Texture>("./data/texture/titlebackground.png"));
	backGroundRenderer->SetColor(D3DCOLOR_ARGB(255, 255, 255, 255));
	BackgroundObject->AddBehaviour(backGroundRenderer);


	GameEngine::GameObject* TitlemanagerObject = GameEngine::GameObject::Instantiate();
	TitlemanagerObject->GetTransform()->SetPosition(&D3DXVECTOR3(300.0f, 400.0f, 0.0f));
	TitlemanagerObject->GetTransform()->SetScale(&D3DXVECTOR3(50.0f, 50.0f, 50.0f));
	auto titlemanager = new Game::TitleManager();
	auto TitlemanagerRenderer = new GameEngine::Behaviour::UIRenderer(GameEngine::Resource::ResourceManager::Get<Texture>("./data/texture/test.png"));
	auto titleManagerSoundPlay = new GameEngine::Behaviour::SoundPlay();
	TitlemanagerRenderer->SetColor(D3DCOLOR_ARGB(255, 255, 255, 255));
	titleManagerSoundPlay->SetSound(GameEngine::Sound::Sound::CreateFromWaveFile("./data/sound/M_1.wav",XAUDIO2_LOOP_INFINITE));
	TitlemanagerObject->AddBehaviour(TitlemanagerRenderer);
	TitlemanagerObject->AddBehaviour(titlemanager);
	TitlemanagerObject->AddBehaviour(titleManagerSoundPlay);

	// タイトルの描画
	GameEngine::GameObject* TitleObject = GameEngine::GameObject::Instantiate();
	TitleObject->GetTransform()->SetPosition(&D3DXVECTOR3(400.0f, 300.0f, 0.0f));
	TitleObject->GetTransform()->SetScale(&D3DXVECTOR3(600.0f, 150.0f, 50.0f));
	auto TitleRenderer = new GameEngine::Behaviour::UIRenderer(GameEngine::Resource::ResourceManager::Get<Texture>("./data/texture/title.png"));
	TitleRenderer->SetColor(D3DCOLOR_ARGB(255, 255, 255, 255));
	TitleObject->AddBehaviour(TitleRenderer);

	// チュートリアルの文字の表示
	GameEngine::GameObject* StageObject = GameEngine::GameObject::Instantiate();
	StageObject->GetTransform()->SetPosition(&D3DXVECTOR3(400.0f, 400.0f, 0.0f));
	StageObject->GetTransform()->SetScale(&D3DXVECTOR3(250.0f, 50.0f, 50.0f));
	auto StageRenderer = new GameEngine::Behaviour::UIRenderer(GameEngine::Resource::ResourceManager::Get<Texture>("./data/texture/test.png"));
	StageRenderer->SetColor(D3DCOLOR_ARGB(128, 255, 255, 255));
	StageObject->AddBehaviour(StageRenderer);

	// ステージ１の文字の表示
	GameEngine::GameObject* StageObject2 = GameEngine::GameObject::Instantiate();
	StageObject2->GetTransform()->SetPosition(&D3DXVECTOR3(400.0f, 450.0f, 0.0f));
	StageObject2->GetTransform()->SetScale(&D3DXVECTOR3(250.0f, 50.0f, 50.0f));
	auto StageRenderer2 = new GameEngine::Behaviour::UIRenderer(GameEngine::Resource::ResourceManager::Get<Texture>("./data/texture/test.png"));
	StageRenderer2->SetColor(D3DCOLOR_ARGB(150, 255, 255, 255));
	StageObject2->AddBehaviour(StageRenderer2);

	// ステージ２の文字の表示
	GameEngine::GameObject* StageObject3 = GameEngine::GameObject::Instantiate();
	StageObject3->GetTransform()->SetPosition(&D3DXVECTOR3(400.0f, 500.0f, 0.0f));
	StageObject3->GetTransform()->SetScale(&D3DXVECTOR3(250.0f, 50.0f, 50.0f));
	auto StageRenderer3 = new GameEngine::Behaviour::UIRenderer(GameEngine::Resource::ResourceManager::Get<Texture>("./data/texture/test.png"));
	StageRenderer3->SetColor(D3DCOLOR_ARGB(200, 255, 255, 255));
	StageObject3->AddBehaviour(StageRenderer3);

	// ステージ３の文字の表示
	GameEngine::GameObject* StageObject4 = GameEngine::GameObject::Instantiate();
	StageObject4->GetTransform()->SetPosition(&D3DXVECTOR3(400.0f, 550.0f, 0.0f));
	StageObject4->GetTransform()->SetScale(&D3DXVECTOR3(250.0f, 50.0f, 50.0f));
	auto StageRenderer4 = new GameEngine::Behaviour::UIRenderer(GameEngine::Resource::ResourceManager::Get<Texture>("./data/texture/test.png"));
	StageRenderer4->SetColor(D3DCOLOR_ARGB(228, 255, 255, 255));
	StageObject4->AddBehaviour(StageRenderer4);

	// フェード用
	GameEngine::GameObject* FadeObject = GameEngine::GameObject::Instantiate();
	FadeObject->GetTransform()->SetPosition(&D3DXVECTOR3(400.0f, 300.0f, 0.0f));
	FadeObject->GetTransform()->SetScale(&D3DXVECTOR3(800.0f, 600.0f, 50.0f));
	auto fade = new Game::Fade();
	auto FadeRenderer = new GameEngine::Behaviour::UIRenderer(GameEngine::Resource::ResourceManager::Get<Texture>("./data/texture/test.png"));
	FadeRenderer->SetColor(D3DCOLOR_ARGB(255, 0, 0, 0));
	FadeObject->AddBehaviour(FadeRenderer);
	FadeObject->AddBehaviour(fade);
	return false;
}


}