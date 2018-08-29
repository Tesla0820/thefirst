//
//		ファイル名:StageClearScene.cpp
//

#include "StageClearScene.h"
#include "../../../GameEngine/GameEngine.h"
#include "../ResultManager.h"
#include "StageClearManager.h"
#include "../../Common/Fade.h"

namespace Game {
	namespace ResultScene
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
			GameEngine::GameObject* ManagerObject = GameEngine::GameObject::Instantiate();
			auto stageclearmanager = new Game::ResultScene::StageClearManager ();
			ManagerObject->AddBehaviour(stageclearmanager);


			GameEngine::GameObject* BackgroundObject = GameEngine::GameObject::Instantiate();
			BackgroundObject->GetTransform()->SetPosition(&D3DXVECTOR3(400.0f, 300.0f, 0.0f));
			BackgroundObject->GetTransform()->SetScale(&D3DXVECTOR3(800.0f, 600.0f, 50.0f));
			auto backGroundRenderer = new GameEngine::Behaviour::UIRenderer(GameEngine::Resource::ResourceManager::Get<Texture>("./data/texture/test.png"));
			backGroundRenderer->SetColor(D3DCOLOR_ARGB(128, 255, 255, 255));
			BackgroundObject->AddBehaviour(backGroundRenderer);


			GameEngine::GameObject* StageClearObject = GameEngine::GameObject::Instantiate();
			StageClearObject->GetTransform()->SetPosition(&D3DXVECTOR3(400.0f, 200.0f, 0.0f));
			StageClearObject->GetTransform()->SetScale(&D3DXVECTOR3(600.0f, 150.0f, 50.0f));
			auto StageClearRenderer = new GameEngine::Behaviour::UIRenderer(GameEngine::Resource::ResourceManager::Get<Texture>("./data/texture/test.png"));
			StageClearRenderer->SetColor(D3DCOLOR_ARGB(255, 255, 255, 255));
			StageClearObject->AddBehaviour(StageClearRenderer);


			GameEngine::GameObject* PushEnterObject = GameEngine::GameObject::Instantiate();
			PushEnterObject->GetTransform()->SetPosition(&D3DXVECTOR3(400.0f, 450.0f, 0.0f));
			PushEnterObject->GetTransform()->SetScale(&D3DXVECTOR3(400.0f, 100.0f, 50.0f));
			auto PushEnterRenderer = new GameEngine::Behaviour::UIRenderer(GameEngine::Resource::ResourceManager::Get<Texture>("./data/texture/title.png"));
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