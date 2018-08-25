//
//		ƒtƒ@ƒCƒ‹–¼:TitleScene.cpp
//

#include "TitleScene.h"
#include "../../GameEngine/GameEngine.h"
#include "Pipeline/Echo.h"
#include "TitleManager.h"

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

	return false;
}


}