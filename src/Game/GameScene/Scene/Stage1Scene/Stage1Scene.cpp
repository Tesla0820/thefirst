//
//		�t�@�C����:Stage1Scene.cpp
//

#include "Stage1Scene.h"
#include "../../../../GameEngine/GameEngine.h"
#include "../../../Common/Pipeline/Echo.h"
#include "../StageManager.h"
#include "../../../Common/Fade.h"
#include "../../Behaviour/GimmickFactory.h"

namespace Game { namespace GameScene { namespace Scene
{

	Stage1Scene::Stage1Scene()
	{

	}

	Stage1Scene::~Stage1Scene()
	{
		SAFE_DELETE(farre);
	}

	bool Stage1Scene::Init()
	{
		Fade::StartFadeIn();

		using Texture = GameEngine::Resource::Texture;
		using ResourceManager = GameEngine::Resource::ResourceManager;
		GameEngine::Environment::Get()->AttachPipeline(new Pipeline::Echo());

		GameEngine::GameObject* object = GameEngine::GameObject::Instantiate();
		auto camera = new GameEngine::Behaviour::Camera();
		object->AddBehaviour(camera);
		camera->SetCurrent();
		camera->EnablePerspectiveMode(true);
		object->GetTransform()->SetPosition(&D3DXVECTOR3(0.0f, 5.0f, 0.0f));
		GameEngine::GameObject* object2 = GameEngine::GameObject::Instantiate();
		auto transform = object2->GetTransform();
		transform->SetPosition(&D3DXVECTOR3(0.0f, -20.0f, 0.0f));
		auto meshRenderer = new Game::MeshRendererEx();
		meshRenderer->SetMesh(std::shared_ptr<GameEngine::Resource::Mesh::IMesh>(new GameEngine::Resource::Mesh::MeshD3DX(TEXT("./data/model/stage.x"))));
		object2->AddBehaviour(meshRenderer);
		
        Behaviour::GimmickFactory::InstantiateBell(&D3DXVECTOR3(0.0f, 0.0f, 10.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));

		// BGM�ESE�p
		GameEngine::GameObject* stageSoundObject = GameEngine::GameObject::Instantiate();
		auto stageSoundPlay = new GameEngine::Behaviour::SoundPlay();
		stageSoundPlay->SetSound(GameEngine::Sound::Sound::CreateFromWaveFile("./data/sound/game_honpen.wav", XAUDIO2_LOOP_INFINITE));
		stageSoundObject->AddBehaviour(stageSoundPlay);
		stageSoundPlay->Play();


		// �t�F�[�h�p
		GameEngine::GameObject* fadeObject = GameEngine::GameObject::Instantiate();
		fadeObject->GetTransform()->SetPosition(&D3DXVECTOR3(400.0f, 300.0f, 0.0f));
		fadeObject->GetTransform()->SetScale(&D3DXVECTOR3(800.0f, 600.0f, 50.0f));
		auto fade = new Game::Fade();
		auto fadeRenderer = new GameEngine::Behaviour::UIRenderer();
		fadeRenderer->SetColor(D3DCOLOR_ARGB(255, 0, 0, 0));
		fadeObject->AddBehaviour(fadeRenderer);
		fadeObject->AddBehaviour(fade);

		return false;
	}
}
}
}