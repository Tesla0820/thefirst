//
//		ファイル名:TitleScene.cpp
//

#include "TitleScene.h"
#include "../../GameEngine/GameEngine.h"
#include "Pipeline/Echo.h"
#include "../GameScene/player.h"

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

	//地面
	GameEngine::GameObject* object = GameEngine::GameObject::Instantiate();
	auto groundCollider = new GameEngine::Behaviour::BoxCollider(D3DXVECTOR3(0.0f, -1.1f, 0.0f), D3DXVECTOR3(100.0f, 1.0f, 100.0f));
	object->AddBehaviour(groundCollider);

	//プレイヤー
	object = GameEngine::GameObject::Instantiate();
	auto camera = new GameEngine::Behaviour::Camera();
	auto player = new GameScene::Player();
	auto collider = new GameEngine::Behaviour::SphereCollider(D3DXVECTOR3(0.0f, 0.0f, 0.0f), 5.0f);
	collider->EnableTrigger(false);
	collider->EnableFreeze(false);
	object->AddBehaviour(camera);
	object->AddBehaviour(player);
	object->AddBehaviour(collider);

	camera->SetCurrent();
	camera->EnablePerspectiveMode(true);
	object->GetTransform()->SetPosition(&D3DXVECTOR3(0.0f,8.0f,-8.0f));
	
	//ステージファイル
	object = GameEngine::GameObject::Instantiate();
	auto transform = object->GetTransform();
	transform->SetPosition(&D3DXVECTOR3(0.0f,0.0f,0.0f));
	auto meshRenderer = new GameEngine::Behaviour::MeshRenderer();
	meshRenderer->SetMesh(std::shared_ptr<GameEngine::Resource::Mesh::IMesh>(new GameEngine::Resource::Mesh::MeshD3DX(TEXT("./data/model/stage.x"))));
	object->AddBehaviour(meshRenderer);

	//テスト用箱
	object = GameEngine::GameObject::Instantiate();
	object->AddBehaviour(new GameEngine::Behaviour::BoxCollider(D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXVECTOR3(1.0f, 1.0f, 1.0f)));
	auto meshRenderer2 = new GameEngine::Behaviour::MeshRenderer();
	meshRenderer2->SetMesh(std::shared_ptr<GameEngine::Resource::Mesh::IMesh>(new GameEngine::Resource::Mesh::MeshD3DX(TEXT("./data/model/test.x"))));
	object->AddBehaviour(meshRenderer2);
	object->GetTransform()->Offset(&D3DXVECTOR3(0.0f, 3.0f, 20.0f));
	return false;
}


}