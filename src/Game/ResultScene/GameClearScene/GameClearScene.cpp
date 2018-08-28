//
//		ƒtƒ@ƒCƒ‹–¼:GameClearScene.cpp
//

#include "GameClearScene.h"
#include "../../../GameEngine/GameEngine.h"
#include "../ResultManager.h"


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
		GameEngine::GameObject* ManagerObject = GameEngine::GameObject::Instantiate();
		auto resultmanager = new Game::ResultManager();
		ManagerObject->AddBehaviour(resultmanager);


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