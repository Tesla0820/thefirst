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
	using Texture = GameEngine::Resource::Texture;
	using ResourceManager	= GameEngine::Resource::ResourceManager;
	GameEngine::GameObject* object = GameEngine::GameObject::Instantiate();
	auto titlemanager = new Game::TitleManager();
	object->AddBehaviour(titlemanager);


	GameEngine::GameObject* BackgroundObject = GameEngine::GameObject::Instantiate();
	BackgroundObject->GetTransform()->SetPosition(&D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	BackgroundObject->GetTransform()->SetScale(&D3DXVECTOR3(50.0f, 50.0f, 50.0f));
	auto backGroundRenderer = new GameEngine::Behaviour::UIRenderer(GameEngine::Resource::ResourceManager::Get<Texture>("./data/texture/test.png"));
	BackgroundObject->AddBehaviour(backGroundRenderer);

	GameEngine::GameObject* TitleObject = GameEngine::GameObject::Instantiate();
	TitleObject->GetTransform()->SetPosition(&D3DXVECTOR3(0.0f, 0.0f, 0.0f));


	GameEngine::GameObject* PushEnterObject = GameEngine::GameObject::Instantiate();
	PushEnterObject->GetTransform()->SetPosition(&D3DXVECTOR3(0.0f, 0.0f, 0.0f));

	return false;
}


}