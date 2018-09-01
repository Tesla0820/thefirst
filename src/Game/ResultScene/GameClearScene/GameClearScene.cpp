//
//		�t�@�C����:GameClearScene.cpp
//

#include "GameClearScene.h"
#include "../../../GameEngine/GameEngine.h"
#include "../ResultManager.h"
#include "../../Common/Fade.h"
#include "../../Common/Flash.h"


namespace Game { namespace ResultScene
{

	GameClearScene::GameClearScene()
	{

	}

	GameClearScene::~GameClearScene()
	{
		SAFE_DELETE(farre);
	}

	bool GameClearScene::Init()
	{
		Fade::StartFadeIn();

		using Texture = GameEngine::Resource::Texture;
		using ResourceManager = GameEngine::Resource::ResourceManager;

		// �}�l�[�W���[�p
		GameEngine::GameObject* resultManagerObject = GameEngine::GameObject::Instantiate();
		auto resultmanager = new Game::ResultManager();
		auto resultManagerSoundPlay = new GameEngine::Behaviour::SoundPlay();
		resultManagerSoundPlay->SetSound(GameEngine::Sound::Sound::CreateFromWaveFile("./data/sound/game_clear.wav", XAUDIO2_LOOP_INFINITE));
		resultManagerObject->AddBehaviour(resultmanager);
		resultManagerObject->AddBehaviour(resultManagerSoundPlay);
		resultManagerSoundPlay->Play();

		// �Q�[���N���A��ʂ̔w�i�p
		GameEngine::GameObject* backgroundObject = GameEngine::GameObject::Instantiate();
		backgroundObject->GetTransform()->SetPosition(&D3DXVECTOR3(400.0f, 300.0f, 0.0f));
		backgroundObject->GetTransform()->SetScale(&D3DXVECTOR3(800.0f, 600.0f, 50.0f));
		auto backgroundRenderer = new GameEngine::Behaviour::UIRenderer(GameEngine::Resource::ResourceManager::Get<Texture>("./data/texture/GAME_CLEAR_BG.png"));
		backgroundRenderer->SetColor(D3DCOLOR_ARGB(255, 255, 255, 255));
		backgroundObject->AddBehaviour(backgroundRenderer);

		// �Q�[���N���A�̕����p
		GameEngine::GameObject* gameClearObject = GameEngine::GameObject::Instantiate();
		gameClearObject->GetTransform()->SetPosition(&D3DXVECTOR3(400.0f, 200.0f, 0.0f));
		gameClearObject->GetTransform()->SetScale(&D3DXVECTOR3(600.0f, 150.0f, 50.0f));
		auto gameClearRenderer = new GameEngine::Behaviour::UIRenderer(GameEngine::Resource::ResourceManager::Get<Texture>("./data/texture/STAGE_CLEAR.png"));
		gameClearRenderer->SetColor(D3DCOLOR_ARGB(255, 255, 255, 255));
		gameClearObject->AddBehaviour(gameClearRenderer);


		// PushEnter�p
		GameEngine::GameObject* pushenterObject = GameEngine::GameObject::Instantiate();
		pushenterObject->GetTransform()->SetPosition(&D3DXVECTOR3(400.0f, 400.0f, 0.0f));
		pushenterObject->GetTransform()->SetScale(&D3DXVECTOR3(400.0f, 300.0f, 50.0f));
		auto flash = new Game::Flash();
		auto pushenterRenderer = new GameEngine::Behaviour::UIRenderer(GameEngine::Resource::ResourceManager::Get<Texture>("./data/texture/pushenter.png"));
		pushenterObject->AddBehaviour(flash);
		pushenterRenderer->SetColor(D3DCOLOR_ARGB(255, 255, 255, 255));
		pushenterObject->AddBehaviour(pushenterRenderer);

		// �t�F�[�h�p
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