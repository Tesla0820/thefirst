//
//		ファイル名:GameOverScene.cpp
//

#include "GameOverScene.h"
#include "../../../GameEngine/GameEngine.h"
#include "../ResultManager.h"
#include "../../Common/Fade.h"


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
		GameEngine::GameObject* ManagerObject = GameEngine::GameObject::Instantiate();
		auto resultmanager = new Game::ResultManager();
		ManagerObject->AddBehaviour(resultmanager);


		GameEngine::GameObject* BackgroundObject = GameEngine::GameObject::Instantiate();
		BackgroundObject->GetTransform()->SetPosition(&D3DXVECTOR3(400.0f, 300.0f, 0.0f));
		BackgroundObject->GetTransform()->SetScale(&D3DXVECTOR3(800.0f, 600.0f, 50.0f));
		auto backGroundRenderer = new GameEngine::Behaviour::UIRenderer(GameEngine::Resource::ResourceManager::Get<Texture>("./data/texture/test.png"));
		backGroundRenderer->SetColor(D3DCOLOR_ARGB(128, 255, 255, 255));
		BackgroundObject->AddBehaviour(backGroundRenderer);


		GameEngine::GameObject* GameOverObject = GameEngine::GameObject::Instantiate();
		GameOverObject->GetTransform()->SetPosition(&D3DXVECTOR3(400.0f, 200.0f, 0.0f));
		GameOverObject->GetTransform()->SetScale(&D3DXVECTOR3(600.0f, 150.0f, 50.0f));
		auto GameOverRenderer = new GameEngine::Behaviour::UIRenderer(GameEngine::Resource::ResourceManager::Get<Texture>("./data/texture/test.png"));
		GameOverRenderer->SetColor(D3DCOLOR_ARGB(255, 255, 255, 255));
		GameOverObject->AddBehaviour(GameOverRenderer);


		GameEngine::GameObject* PushEnterObject = GameEngine::GameObject::Instantiate();
		PushEnterObject->GetTransform()->SetPosition(&D3DXVECTOR3(400.0f, 450.0f, 0.0f));
		PushEnterObject->GetTransform()->SetScale(&D3DXVECTOR3(400.0f, 100.0f, 50.0f));
		auto PushEnterRenderer = new GameEngine::Behaviour::UIRenderer(GameEngine::Resource::ResourceManager::Get<Texture>("./data/texture/test.png"));
		PushEnterRenderer->SetColor(D3DCOLOR_ARGB(128, 255, 255, 255));
		PushEnterObject->AddBehaviour(PushEnterRenderer);

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
}