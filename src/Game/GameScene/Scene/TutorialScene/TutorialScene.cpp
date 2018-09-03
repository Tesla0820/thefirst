//
//		�t�@�C����:TutorialScene.cpp
//

#include "TutorialScene.h"
#include "../../../../GameEngine/GameEngine.h"
#include "../../../Common/Pipeline/Echo.h"
#include "TutorialManager.h"
#include "../../../Common/Fade.h"
#include "../../GameFactory.h"
#include "../../Behaviour/GimmickFactory.h"

namespace Game { namespace GameScene { namespace Scene
{

	TutorialScene::TutorialScene()
	{

	}

	TutorialScene::~TutorialScene()
	{
		SAFE_DELETE(farre);
	}

	bool TutorialScene::Init()
	{
		Fade::StartFadeIn();

		using Texture = GameEngine::Resource::Texture;
		using ResourceManager = GameEngine::Resource::ResourceManager;
		GameEngine::Environment::Get()->AttachPipeline(new Pipeline::Echo());

		//�n��
		GameFactory::CreateGround();

		//�v���C���[
		GameFactory::CreatePlayer();

		GameEngine::GameObject* object2 = GameEngine::GameObject::Instantiate();
		auto transform = object2->GetTransform();
		transform->SetPosition(&D3DXVECTOR3(0.0f, 0.0f, 10.0f));
		auto meshRenderer = new Game::MeshRendererEx();
		meshRenderer->SetMesh(std::shared_ptr<GameEngine::Resource::Mesh::IMesh>(new GameEngine::Resource::Mesh::MeshD3DX(TEXT("./data/model/stage.x"))));
		object2->AddBehaviour(meshRenderer);

		GameEngine::GameObject* object4 = GameEngine::GameObject::Instantiate();
		auto tutorialmanager = new Game::GameScene::Scene::TutorialManager();
		object4->AddBehaviour(tutorialmanager);

        //�M�~�b�N
        //Behaviour::GimmickFactory::InstantiateArmor(&D3DXVECTOR3(0.0f, 0.0f, 10.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
        //Behaviour::GimmickFactory::InstantiateBell(&D3DXVECTOR3(0.0f, 0.0f, 0.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
        //Behaviour::GimmickFactory::InstantiateBrokenPillar(&D3DXVECTOR3(0.0f, 0.0f, 0.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
        //Behaviour::GimmickFactory::InstantiateBronzeStatue(&D3DXVECTOR3(0.0f, 0.0f, 5.0f), &D3DXVECTOR3(0.0f, 90.0f, 0.0f));
        //Behaviour::GimmickFactory::InstantiatePillar(&D3DXVECTOR3(0.0f, 0.0f, 0.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
        //Behaviour::GimmickFactory::InstantiateThorns(&D3DXVECTOR3(0.0f, 0.0f, 10.0f), &D3DXVECTOR3(0.0f, 90.0f, 0.0f));
        Behaviour::GimmickFactory::InstantiateThornsMove(&D3DXVECTOR3(0.0f, 0.0f, 10.0f), &D3DXVECTOR3(270.0f, 90.0f, 0.0f));

		// �t�F�[�h�p
		GameEngine::GameObject* FadeObject = GameEngine::GameObject::Instantiate();
		FadeObject->GetTransform()->SetPosition(&D3DXVECTOR3(400.0f, 300.0f, 0.0f));
		FadeObject->GetTransform()->SetScale(&D3DXVECTOR3(800.0f, 600.0f, 50.0f));
		auto fade = new Game::Fade();
		auto FadeRenderer = new GameEngine::Behaviour::UIRenderer();
		FadeRenderer->SetColor(D3DCOLOR_ARGB(255, 0, 0, 0));
		FadeObject->AddBehaviour(FadeRenderer);
		FadeObject->AddBehaviour(fade);

		

		return false;
	}
}
}
}