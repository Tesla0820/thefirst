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
		GameEngine::GameObject* ManagerObject = GameEngine::GameObject::Instantiate();
		auto resultmanager = new Game::ResultManager();
		ManagerObject->AddBehaviour(resultmanager);


		GameEngine::GameObject* BackgroundObject = GameEngine::GameObject::Instantiate();
		BackgroundObject->GetTransform()->SetPosition(&D3DXVECTOR3(400.0f, 300.0f, 0.0f));
		BackgroundObject->GetTransform()->SetScale(&D3DXVECTOR3(800.0f, 600.0f, 50.0f));
		auto backGroundRenderer = new GameEngine::Behaviour::UIRenderer(GameEngine::Resource::ResourceManager::Get<Texture>("./data/texture/GAME_CLEAR_BG.png"));
		backGroundRenderer->SetColor(D3DCOLOR_ARGB(255, 255, 255, 255));
		BackgroundObject->AddBehaviour(backGroundRenderer);


		GameEngine::GameObject* GameClearObject = GameEngine::GameObject::Instantiate();
		GameClearObject->GetTransform()->SetPosition(&D3DXVECTOR3(400.0f, 200.0f, 0.0f));
		GameClearObject->GetTransform()->SetScale(&D3DXVECTOR3(600.0f, 150.0f, 50.0f));
		auto GameClearRenderer = new GameEngine::Behaviour::UIRenderer(GameEngine::Resource::ResourceManager::Get<Texture>("./data/texture/GAME_CLEAR.png"));
		GameClearRenderer->SetColor(D3DCOLOR_ARGB(255, 255, 255, 255));
		GameClearObject->AddBehaviour(GameClearRenderer);


		// PushEnter用
		GameEngine::GameObject* PushEnterObject = GameEngine::GameObject::Instantiate();
		PushEnterObject->GetTransform()->SetPosition(&D3DXVECTOR3(400.0f, 450.0f, 0.0f));
		PushEnterObject->GetTransform()->SetScale(&D3DXVECTOR3(400.0f, 300.0f, 50.0f));
		auto flash = new Game::Flash();
		auto PushEnterRenderer = new GameEngine::Behaviour::UIRenderer(GameEngine::Resource::ResourceManager::Get<Texture>("./data/texture/pushenter.png"));
		PushEnterObject->AddBehaviour(flash);
		PushEnterRenderer->SetColor(D3DCOLOR_ARGB(255, 255, 255, 255));
		PushEnterObject->AddBehaviour(PushEnterRenderer);

		// フェード用
		GameEngine::GameObject* FadeObject = GameEngine::GameObject::Instantiate();
		FadeObject->GetTransform()->SetPosition(&D3DXVECTOR3(400.0f, 300.0f, 0.0f));
		FadeObject->GetTransform()->SetScale(&D3DXVECTOR3(800.0f, 600.0f, 50.0f));
		auto fade = new Game::Fade();
		auto FadeRenderer = new GameEngine::Behaviour::UIRenderer();
		FadeRenderer->SetColor(D3DCOLOR_ARGB(255, 0, 0, 0));
		FadeObject->AddBehaviour(FadeRenderer);
		FadeObject->AddBehaviour(fade);

		return false;
	}

}
}