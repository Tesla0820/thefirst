//
//		ファイル名:GameClearScene.cpp
//

#include "GameClearScene.h"
#include "../../../GameEngine/GameEngine.h"
#include "../ResultManager.h"
#include "../../Common/Fade.h"
#include "../../Common/Flash.h"


namespace Game { namespace ResultScene
{

bool GameClearScene::Init()
{
	Fade::StartFadeIn();

	using Texture = GameEngine::Resource::Texture;
	using ResourceManager = GameEngine::Resource::ResourceManager;

	// マネージャー用
	GameEngine::GameObject* resultManagerObject = GameEngine::GameObject::Instantiate();
	auto resultmanager = new Game::ResultManager();
	auto resultManagerSoundPlay = new GameEngine::Behaviour::SoundPlay();
	auto resultManagerSoundPlay2 = new GameEngine::Behaviour::SoundPlay();
	resultManagerSoundPlay->SetSound(GameEngine::Sound::Sound::CreateFromWaveFile("./data/sound/game_clear.wav", XAUDIO2_LOOP_INFINITE));
	resultManagerSoundPlay2->SetSound(GameEngine::Sound::Sound::CreateFromWaveFile("./data/sound/decision.wav", XAUDIO2_NO_LOOP_REGION));
	resultManagerObject->AddBehaviour(resultmanager);
	resultManagerObject->AddBehaviour(resultManagerSoundPlay);
	resultManagerObject->AddBehaviour(resultManagerSoundPlay2);
	resultManagerSoundPlay->Play();

	// ゲームクリア画面の背景用
	GameEngine::GameObject* backgroundObject = GameEngine::GameObject::Instantiate();
	backgroundObject->GetTransform()->SetPosition(&D3DXVECTOR3(800.0f, 600.0f, 0.0f));
	backgroundObject->GetTransform()->SetScale(&D3DXVECTOR3(1600.0f, 1200.0f, 50.0f));
	auto backgroundRenderer = new GameEngine::Behaviour::UIRenderer(GameEngine::Resource::ResourceManager::Get<Texture>("./data/texture/gameclearBG.png"));
	backgroundRenderer->SetColor(D3DCOLOR_ARGB(255, 255, 255, 255));
	backgroundObject->AddBehaviour(backgroundRenderer);

	// ゲームクリアの文字用
	GameEngine::GameObject* gameClearObject = GameEngine::GameObject::Instantiate();
	gameClearObject->GetTransform()->SetPosition(&D3DXVECTOR3(800.0f, 400.0f, 0.0f));
	gameClearObject->GetTransform()->SetScale(&D3DXVECTOR3(1200.0f, 300.0f, 50.0f));
	auto gameClearRenderer = new GameEngine::Behaviour::UIRenderer(GameEngine::Resource::ResourceManager::Get<Texture>("./data/texture/GAME_CLEAR.png"));
	gameClearRenderer->SetColor(D3DCOLOR_ARGB(255, 255, 255, 255));
	gameClearObject->AddBehaviour(gameClearRenderer);


	// PushEnter用
	GameEngine::GameObject* pushenterObject = GameEngine::GameObject::Instantiate();
	pushenterObject->GetTransform()->SetPosition(&D3DXVECTOR3(800.0f, 800.0f, 0.0f));
	pushenterObject->GetTransform()->SetScale(&D3DXVECTOR3(800.0f, 600.0f, 50.0f));
	auto flash = new Game::Flash();
	auto pushenterRenderer = new GameEngine::Behaviour::UIRenderer(GameEngine::Resource::ResourceManager::Get<Texture>("./data/texture/pushenter.png"));
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