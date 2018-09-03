//
//		ファイル名:TutorialScene.cpp
//

#include "TutorialScene.h"
#include "../../../../GameEngine/GameEngine.h"
#include "../../../Common/Pipeline/Echo.h"
#include "../../../Common/Fade.h"
#include "../../Behaviour/UIgauge.h"
#include "../../GameFactory.h"
#include "../../StageLoader.h"
#include "../../GimmickFactory.h"
#include "TutorialManager.h"

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
  using Texture = GameEngine::Resource::Texture;
  using ResourceManager = GameEngine::Resource::ResourceManager;
  GameEngine::Environment::Get()->AttachPipeline(new Pipeline::Echo());

  //GameEngine::GameObject* object2 = GameEngine::GameObject::Instantiate();
  //auto transform = object2->GetTransform();
  //transform->SetPosition(&D3DXVECTOR3(0.0f, 0.0f, 0.0f));
  //auto meshRenderer = new GameEngine::Behaviour::MeshRenderer();
  //meshRenderer->SetMesh(std::shared_ptr<GameEngine::Resource::Mesh::IMesh>(new GameEngine::Resource::Mesh::MeshD3DX(TEXT("./data/model/stage.x"))));
  //object2->AddBehaviour(meshRenderer);

  //プレイヤー
  GameFactory::CreatePlayer();

  // マネージャー用
  GameEngine::GameObject* tutorialManagerObject = GameEngine::GameObject::Instantiate();
  auto tutorialmanager = new Game::GameScene::Scene::TutorialManager();
  tutorialManagerObject->AddBehaviour(tutorialmanager);
  auto tutorialManagerSoundPlay = new GameEngine::Behaviour::SoundPlay();
  tutorialManagerSoundPlay->SetSound(GameEngine::Sound::Sound::CreateFromWaveFile("./data/sound/game_honpen.wav", XAUDIO2_LOOP_INFINITE));
  tutorialManagerObject->AddBehaviour(tutorialManagerSoundPlay);
  tutorialManagerSoundPlay->Play();

  //ギミック
  //GimmickFactory::InstantiateArmor(&D3DXVECTOR3(0.0f, 0.0f, 10.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
  //GimmickFactory::InstantiateBell(&D3DXVECTOR3(0.0f, 0.0f, 0.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
  //GimmickFactory::InstantiateBrokenPillar(&D3DXVECTOR3(0.0f, 0.0f, 0.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
  //GimmickFactory::InstantiateBronzeStatue(&D3DXVECTOR3(0.0f, 0.0f, 5.0f), &D3DXVECTOR3(0.0f, 90.0f, 0.0f));
  //GimmickFactory::InstantiatePillar(&D3DXVECTOR3(0.0f, 0.0f, 0.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
  //GimmickFactory::InstantiateThorns(&D3DXVECTOR3(0.0f, 0.0f, 10.0f), &D3DXVECTOR3(0.0f, 90.0f, 0.0f));

  // UIゲージ
  GameFactory::CreateUIgauge();

  StageLoader::LoadStage("./data/stage/stage0.txt");

  //�t�F�[�h
  GameFactory::CreateFade();

  return false;
}
  
}
}
}