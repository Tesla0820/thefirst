//
//		�t�@�C����:Stage2Scene.cpp
//

#include "Stage2Scene.h"
#include "../../../../GameEngine/GameEngine.h"
#include "../../../TitleScene/Pipeline/Echo.h"
#include "../StageManager.h"

namespace Game { namespace GameScene { namespace Scene
{

	Stage2Scene::Stage2Scene()
	{

	}

	Stage2Scene::~Stage2Scene()
	{
		SAFE_DELETE(farre);
	}

	bool Stage2Scene::Init()
	{
		GameEngine::Environment::Get()->AttachPipeline(new Pipeline::Echo());

		GameEngine::GameObject* object = GameEngine::GameObject::Instantiate();
		auto camera = new GameEngine::Behaviour::Camera();
		object->AddBehaviour(camera);
		camera->SetCurrent();
		camera->EnablePerspectiveMode(true);
		object->GetTransform()->SetPosition(&D3DXVECTOR3(0.0f, 5.0f, 0.0f));
		GameEngine::GameObject* object2 = GameEngine::GameObject::Instantiate();
		auto transform = object2->GetTransform();
		transform->SetPosition(&D3DXVECTOR3(0.0f, 0.0f, -50.0f));
		auto meshRenderer = new GameEngine::Behaviour::MeshRenderer();
		meshRenderer->SetMesh(std::shared_ptr<GameEngine::Resource::Mesh::IMesh>(new GameEngine::Resource::Mesh::MeshD3DX(TEXT("./data/model/stage.x"))));
		object2->AddBehaviour(meshRenderer);


		GameEngine::GameObject* ManagerObject = GameEngine::GameObject::Instantiate();
		auto stagemanager = new Game::GameScene::StageManager();
		ManagerObject->AddBehaviour(stagemanager);
		
		return false;
	}
}
}
}