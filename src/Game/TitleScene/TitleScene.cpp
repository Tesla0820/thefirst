//
//		ƒtƒ@ƒCƒ‹–¼:TitleScene.cpp
//

#include "TitleScene.h"
#include "Pipeline/Echo.h"
#include "../../GameEngine/GameEngine.h"
#include "../GameScene/player.h"
#include "../../Game/TitleScene/Behavior/Gimmick.h"

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
	GameEngine::Environment::Get()->AttachPipeline(new Pipeline::Echo());
	GameEngine::GameObject* object;
	//’n–Ê
	object = GameEngine::GameObject::Instantiate();
	auto groundCollider = new GameEngine::Behaviour::BoxCollider(D3DXVECTOR3(0.0f, -10.0f, 0.0f), D3DXVECTOR3(100.0f, 10.0f, 100.0f));
	object->AddBehaviour(groundCollider);

	//ƒvƒŒƒCƒ„[
	object = GameEngine::GameObject::Instantiate();
	auto player = new GameScene::Player();
	auto camera = new GameEngine::Behaviour::Camera();
	auto collider = new GameEngine::Behaviour::SphereCollider(D3DXVECTOR3(0.0f, 0.0f, 0.0f), 5.0f);
	camera->EnablePerspectiveMode(true);
	camera->SetCurrent();
	collider->EnableTrigger(false);
	collider->EnableFreeze(false);
	object->AddBehaviour(camera);
	object->AddBehaviour(player);
	object->AddBehaviour(collider);
	object->GetTransform()->SetPosition(&D3DXVECTOR3(0.0f,6.0f,-8.0f));

	
	//ƒXƒe[ƒWƒtƒ@ƒCƒ‹
	object = GameEngine::GameObject::Instantiate();
	auto transform = object->GetTransform();
	auto meshRenderer = new GameEngine::Behaviour::MeshRenderer();
	transform->SetPosition(&D3DXVECTOR3(0.0f,0.0f,0.0f));
	meshRenderer->SetMesh(std::shared_ptr<GameEngine::Resource::Mesh::IMesh>(new GameEngine::Resource::Mesh::MeshD3DX(TEXT("./data/model/stage.x"))));
	object->AddBehaviour(meshRenderer);

  InstantiateGimmick(new Game::Behaviour::Douzou, &D3DXVECTOR3(0.0F, 0.0F, 20.0F), 0.0F, 0.0F, 0.0F);
  InstantiateGimmick(new Game::Behaviour::Douzou, &D3DXVECTOR3(0.0F, 0.0F, 40.0F), 0.0F, 0.0F, 0.0F);
  InstantiateGimmick(new Game::Behaviour::Douzou, &D3DXVECTOR3(0.0F, 0.0F, 60.0F), 0.0F, 0.0F, 0.0F);
  InstantiateGimmick(new Game::Behaviour::Douzou, &D3DXVECTOR3(0.0F, 0.0F, 80.0F), 0.0F, 0.0F, 0.0F);

	//ƒeƒXƒg—p” 
	object = GameEngine::GameObject::Instantiate();
	object->AddBehaviour(new GameEngine::Behaviour::BoxCollider(D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXVECTOR3(1.0f, 1.0f, 1.0f)));
	auto meshRenderer2 = new GameEngine::Behaviour::MeshRenderer();
	meshRenderer2->SetMesh(std::shared_ptr<GameEngine::Resource::Mesh::IMesh>(new GameEngine::Resource::Mesh::MeshD3DX(TEXT("./data/model/test.x"))));
	object->AddBehaviour(meshRenderer2);
	object->GetTransform()->Offset(&D3DXVECTOR3(0.0f, 3.0f, 20.0f));

	return false;
}

}