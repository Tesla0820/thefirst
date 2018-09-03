//
//		ファイル名:TutorialScene.cpp
//

#include "TutorialScene.h"
#include "../../../../GameEngine/GameEngine.h"
#include "../../../Common/Pipeline/Echo.h"
#include "TutorialManager.h"
#include "../../../Common/Fade.h"
#include "../../GameFactory.h"
#include "../../Behaviour/UIgauge.h"

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

		//地面
		GameFactory::CreateGround();

		//プレイヤー
		GameFactory::CreatePlayer();


		GameEngine::GameObject* object2 = GameEngine::GameObject::Instantiate();
		auto transform = object2->GetTransform();
		transform->SetPosition(&D3DXVECTOR3(0.0f, 0.0f, 0.0f));
		auto meshRenderer = new GameEngine::Behaviour::MeshRenderer();
		meshRenderer->SetMesh(std::shared_ptr<GameEngine::Resource::Mesh::IMesh>(new GameEngine::Resource::Mesh::MeshD3DX(TEXT("./data/model/stage.x"))));
		object2->AddBehaviour(meshRenderer);

		

		// マネージャー用
		GameEngine::GameObject* tutorialManagerObject = GameEngine::GameObject::Instantiate();
		auto tutorialmanager = new Game::GameScene::Scene::TutorialManager();
		tutorialManagerObject->AddBehaviour(tutorialmanager);
		auto tutorialManagerSoundPlay = new GameEngine::Behaviour::SoundPlay();
		tutorialManagerSoundPlay->SetSound(GameEngine::Sound::Sound::CreateFromWaveFile("./data/sound/game_honpen.wav", XAUDIO2_LOOP_INFINITE));
		tutorialManagerObject->AddBehaviour(tutorialManagerSoundPlay);
		tutorialManagerSoundPlay->Play();

		// フェード用
		GameEngine::GameObject* fadeObject = GameEngine::GameObject::Instantiate();
		fadeObject->GetTransform()->SetPosition(&D3DXVECTOR3(400.0f, 300.0f, 0.0f));
		fadeObject->GetTransform()->SetScale(&D3DXVECTOR3(800.0f, 600.0f, 50.0f));
		auto fade = new Game::Fade();
		auto fadeRenderer = new GameEngine::Behaviour::UIRenderer();
		fadeRenderer->SetColor(D3DCOLOR_ARGB(255, 0, 0, 0));
		fadeObject->AddBehaviour(fadeRenderer);
		fadeObject->AddBehaviour(fade);
	
		// UIゲージ
		GameFactory::CreateUIgauge();



		return false;
	}
}
}
}