//
//		�t�@�C����:GameOverScene.cpp
//

#include "GameOverScene.h"
#include "../../../GameEngine/GameEngine.h"
#include "../ResultManager.h"
#include "../../Common/Fade.h"
#include "../../Common/Flash.h"

namespace Game { namespace ResultScene
{

	GameOverScene::GameOverScene()
	{

	}

	GameOverScene::~GameOverScene()
	{
		SAFE_DELETE(farre);
	}

	bool GameOverScene::Init()
	{
		Fade::StartFadeIn();

		using Texture = GameEngine::Resource::Texture;
		using ResourceManager = GameEngine::Resource::ResourceManager;

		// �}�l�[�W���[�p
		GameEngine::GameObject* resultManagerObject = GameEngine::GameObject::Instantiate();
		auto resultmanager = new Game::ResultManager();
		auto resultManagerSoundPlay = new GameEngine::Behaviour::SoundPlay();
		resultManagerSoundPlay->SetSound(GameEngine::Sound::Sound::CreateFromWaveFile("./data/sound/game_over.wav", XAUDIO2_LOOP_INFINITE));
		resultManagerObject->AddBehaviour(resultmanager);
		resultManagerObject->AddBehaviour(resultManagerSoundPlay);
		resultManagerSoundPlay->Play();

		// �Q�[���I�[�o�[��ʂ̔w�i�p
		GameEngine::GameObject* backgroundObject = GameEngine::GameObject::Instantiate();
		backgroundObject->GetTransform()->SetPosition(&D3DXVECTOR3(400.0f, 300.0f, 0.0f));
		backgroundObject->GetTransform()->SetScale(&D3DXVECTOR3(800.0f, 600.0f, 50.0f));
		auto backgroundRenderer = new GameEngine::Behaviour::UIRenderer(GameEngine::Resource::ResourceManager::Get<Texture>("./data/texture/gameoverBG.png"));
		backgroundRenderer->SetColor(D3DCOLOR_ARGB(255, 255, 255, 255));
		backgroundObject->AddBehaviour(backgroundRenderer);

		// �Q�[���I�[�o�[�̕����p
		GameEngine::GameObject* gameoverObject = GameEngine::GameObject::Instantiate();
		gameoverObject->GetTransform()->SetPosition(&D3DXVECTOR3(400.0f, 200.0f, 0.0f));
		gameoverObject->GetTransform()->SetScale(&D3DXVECTOR3(600.0f, 150.0f, 50.0f));
		auto gameoverRenderer = new GameEngine::Behaviour::UIRenderer(GameEngine::Resource::ResourceManager::Get<Texture>("./data/texture/GAME_OVER.png"));
		gameoverRenderer->SetColor(D3DCOLOR_ARGB(255, 255, 255, 255));
		gameoverObject->AddBehaviour(gameoverRenderer);


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