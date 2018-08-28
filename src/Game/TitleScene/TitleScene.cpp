//
//		ƒtƒ@ƒCƒ‹–¼:TitleScene.cpp
//

#include "../../GameEngine/GameEngine.h"
#include "TitleScene.h"
#include "Pipeline/Echo.h"
#include "TitleManager.h"
#include "Behavior/Gimmick.h"
#include "../GameScene/player.h"

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
	GameEngine::GameObject* object = GameEngine::GameObject::Instantiate();
	auto titlemanager = new Game::TitleManager();
	object->AddBehaviour(titlemanager);


	GameEngine::GameObject* BackgroundObject = GameEngine::GameObject::Instantiate();
	BackgroundObject->GetTransform()->SetPosition(&D3DXVECTOR3(0.0f, 0.0f, 0.0f));


	GameEngine::GameObject* TitleObject = GameEngine::GameObject::Instantiate();
	TitleObject->GetTransform()->SetPosition(&D3DXVECTOR3(0.0f, 0.0f, 0.0f));


	GameEngine::GameObject* PushEnterObject = GameEngine::GameObject::Instantiate();
	PushEnterObject->GetTransform()->SetPosition(&D3DXVECTOR3(0.0f, 0.0f, 0.0f));

	return false;
}

}