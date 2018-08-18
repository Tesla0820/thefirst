//
//		ƒtƒ@ƒCƒ‹–¼:TitleScene.cpp
//

#include "TitleScene.h"
#include "../../GameEngine/GameEngine.h"
#include "Pipeline/Echo.h"
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
	GameEngine::Environment::Get()->AttachPipeline(new Pipeline::Echo());

	GameEngine::GameObject* object=GameEngine::GameObject::Instantiate();
	auto camera = new GameEngine::Behaviour::Camera();
	object->AddBehaviour(camera);
	camera->SetCurrent();
	camera->EnablePerspectiveMode(true);
	GameEngine::GameObject* object2 = GameEngine::GameObject::Instantiate();
	auto transform = object2->GetTransform();
	transform->SetPosition(&D3DXVECTOR3(0.0f,0.0f,14.0f));
	auto meshRenderer = new GameEngine::Behaviour::MeshRenderer();
	meshRenderer->SetMesh(std::shared_ptr<GameEngine::Resource::Mesh::IMesh>(new GameEngine::Resource::Mesh::MeshD3DX(TEXT("./data/model/test.x"))));
	object2->AddBehaviour(meshRenderer);



	return false;
}


}