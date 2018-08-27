//
//		�t�@�C����:TitleScene.cpp
//

#include "TitleScene.h"
#include "../../GameEngine/GameEngine.h"
#include "Pipeline/Echo.h"
#include "../../Game/TitleScene/Behavior/Gimmick.h"

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
	object->GetTransform()->SetPosition(&D3DXVECTOR3(0.0f,5.0f,0.0f));


	GameEngine::GameObject* object2 = GameEngine::GameObject::Instantiate();
	auto transform = object2->GetTransform();
	transform->SetPosition(&D3DXVECTOR3(0.0f,0.0f,0.0f));
	auto meshRenderer = new GameEngine::Behaviour::MeshRenderer();
	meshRenderer->SetMesh(std::shared_ptr<GameEngine::Resource::Mesh::IMesh>(new GameEngine::Resource::Mesh::MeshD3DX(TEXT("./data/model/stage.x"))));
	object2->AddBehaviour(meshRenderer);

    InstantiateGimmick(new Game::Behaviour::Douzou, &D3DXVECTOR3(0.0F, 0.0F, 20.0F), 0.0F, 0.0F, 0.0F);
    InstantiateGimmick(new Game::Behaviour::Douzou, &D3DXVECTOR3(0.0F, 0.0F, 40.0F), 0.0F, 0.0F, 0.0F);
    InstantiateGimmick(new Game::Behaviour::Douzou, &D3DXVECTOR3(0.0F, 0.0F, 60.0F), 0.0F, 0.0F, 0.0F);
    InstantiateGimmick(new Game::Behaviour::Douzou, &D3DXVECTOR3(0.0F, 0.0F, 80.0F), 0.0F, 0.0F, 0.0F);

    return false;
}

}