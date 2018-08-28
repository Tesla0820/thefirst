//
//		ƒtƒ@ƒCƒ‹–¼:TitleScene.cpp
//

#include "TitleScene.h"
#include "../../GameEngine/GameEngine.h"
namespace Game
{

TitleScene::TitleScene()
{

}

TitleScene::~TitleScene()
{

}

bool TitleScene::Init()
{
	GameEngine::GameObject* object=GameEngine::GameObject::Instantiate();
	auto camera = new GameEngine::Behaviour::Camera();
	object->AddBehaviour(camera);
	camera->SetCurrent();
	camera->EnablePerspectiveMode(true);
	GameEngine::GameObject* object2 = GameEngine::GameObject::Instantiate();
	auto transform = object2->GetTransform();
	transform->SetPosition(&D3DXVECTOR3(0.0f,0.0f,10.0f));
	object2->AddBehaviour(new GameEngine::Behaviour::MeshRenderer());



	return false;
}


}