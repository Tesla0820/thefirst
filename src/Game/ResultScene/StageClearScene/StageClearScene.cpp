//
//		ファイル名:StageClearScene.cpp
//

#include "StageClearScene.h"
#include "../../../GameEngine/GameEngine.h"
#include "../ResultManager.h"
#include "StageClearManager.h"
#include "../../Common/Fade.h"
#include "../../Common/Flash.h"

namespace Game { namespace ResultScene
{

	StageClearScene::StageClearScene()
	{

	}

	StageClearScene::~StageClearScene()
	{
		SAFE_DELETE(farre);
	}

	bool StageClearScene::Init()
	{
		Fade::StartFadeIn();

		using Texture = GameEngine::Resource::Texture;
		using ResourceManager = GameEngine::Resource::ResourceManager;

		// マネージャー用
		GameEngine::GameObject* stageclearManagerObject = GameEngine::GameObject::Instantiate();
		auto stageclearManager = new Game::ResultScene::StageClearManager();
		auto stageclearManagerSoundPlay = new GameEngine::Behaviour::SoundPlay();
		auto stageclearManagerSoundPlay2 = new GameEngine::Behaviour::SoundPlay();
		stageclearManagerSoundPlay->SetSound(GameEngine::Sound::Sound::CreateFromWaveFile("./data/sound/stage_clear.wav", XAUDIO2_LOOP_INFINITE));
		stageclearManagerSoundPlay2->SetSound(GameEngine::Sound::Sound::CreateFromWaveFile("./data/sound/stage_clear.wav", XAUDIO2_LOOP_INFINITE));
		stageclearManagerObject->AddBehaviour(stageclearManager);
		stageclearManagerObject->AddBehaviour(stageclearManagerSoundPlay);
		stageclearManagerObject->AddBehaviour(stageclearManagerSoundPlay2);
		stageclearManagerSoundPlay->Play();

		// ステージクリア画面の背景用
		GameEngine::GameObject* backgroundObject = GameEngine::GameObject::Instantiate();
		backgroundObject->GetTransform()->SetPosition(&D3DXVECTOR3(400.0f, 300.0f, 0.0f));
		backgroundObject->GetTransform()->SetScale(&D3DXVECTOR3(800.0f, 600.0f, 50.0f));
		auto backgroundRenderer = new GameEngine::Behaviour::UIRenderer(GameEngine::Resource::ResourceManager::Get<Texture>("./data/texture/STAGE_CLEAR_BG.png"));
		backgroundRenderer->SetColor(D3DCOLOR_ARGB(255, 255, 255, 255));
		backgroundObject->AddBehaviour(backgroundRenderer);

		// ステージクリアの文字用
		GameEngine::GameObject* stageclearObject = GameEngine::GameObject::Instantiate();
		stageclearObject->GetTransform()->SetPosition(&D3DXVECTOR3(400.0f, 200.0f, 0.0f));
		stageclearObject->GetTransform()->SetScale(&D3DXVECTOR3(600.0f, 150.0f, 50.0f));
		auto stageclearRenderer = new GameEngine::Behaviour::UIRenderer(GameEngine::Resource::ResourceManager::Get<Texture>("./data/texture/STAGE_CLEAR.png"));
		stageclearRenderer->SetColor(D3DCOLOR_ARGB(255, 255, 255, 255));
		stageclearObject->AddBehaviour(stageclearRenderer);


		// PushEnter用
		GameEngine::GameObject* pushenterObject = GameEngine::GameObject::Instantiate();
		pushenterObject->GetTransform()->SetPosition(&D3DXVECTOR3(400.0f, 400.0f, 0.0f));
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