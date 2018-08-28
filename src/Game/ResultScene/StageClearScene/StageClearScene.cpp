//
//		ƒtƒ@ƒCƒ‹–¼:StageClearScene.cpp
//

#include "StageClearScene.h"
#include "../../../GameEngine/GameEngine.h"
#include "../ResultManager.h"
#include "StageClearManager.h"

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
			GameEngine::GameObject* ManagerObject = GameEngine::GameObject::Instantiate();
			auto stageclearmanager = new Game::ResultScene::StageClearManager ();
			ManagerObject->AddBehaviour(stageclearmanager);


			GameEngine::GameObject* BackgroundObject = GameEngine::GameObject::Instantiate();
			BackgroundObject->GetTransform()->SetPosition(&D3DXVECTOR3(0.0f, 0.0f, 0.0f));


			GameEngine::GameObject* TitleObject = GameEngine::GameObject::Instantiate();
			TitleObject->GetTransform()->SetPosition(&D3DXVECTOR3(0.0f, 0.0f, 0.0f));


			GameEngine::GameObject* PushEnterObject = GameEngine::GameObject::Instantiate();
			PushEnterObject->GetTransform()->SetPosition(&D3DXVECTOR3(0.0f, 0.0f, 0.0f));

			return false;
		}

	}
}