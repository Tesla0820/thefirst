//
//		ファイル名:TutorialScene.cpp
//

#include "TutorialScene.h"
#include "../../../../GameEngine/GameEngine.h"
#include "../../../Common/Pipeline/Echo.h"
#include "../../../Common/Fade.h"
#include "../../Behaviour/UIgauge.h"
#include "../../GimmickFactory.h"
#include "../../GameFactory.h"
#include "../../StageLoader.h"
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

  //プレイヤー
  auto player = GameFactory::CreatePlayer();

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
  //GimmickFactory::InstantiateThornsMove(&D3DXVECTOR3(0.0f, 0.0f, 10.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
  
  //ステージ
  StageLoader::LoadStage("./data/stage/stage0.txt");
  
  
  
  GimmickFactory::InstantiateBrokenPillar(&D3DXVECTOR3(-100.0f, 0.0f, 0.0f), &D3DXVECTOR3(0.0f, 90.0f, 0.0f));
  GimmickFactory::InstantiateArmor(&D3DXVECTOR3(-410.0f, 0.0f, -60.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));

  GimmickFactory::InstantiatePillar(&D3DXVECTOR3(-450.0f, 0.0f, 40.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
  GimmickFactory::InstantiatePillar(&D3DXVECTOR3(-450.0f, 0.0f, -60.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
  GimmickFactory::InstantiateArmor(&D3DXVECTOR3(-510.0f, 0.0f, 40.0f), &D3DXVECTOR3(0.0f, 180.0f, 0.0f));
  GimmickFactory::InstantiateArmor(&D3DXVECTOR3(-510.0f, 0.0f, -60.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));

  GimmickFactory::InstantiatePillar(&D3DXVECTOR3(-590.0f, 0.0f, 40.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
  GimmickFactory::InstantiatePillar(&D3DXVECTOR3(-590.0f, 0.0f, -60.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));


  GimmickFactory::InstantiateThorns(&D3DXVECTOR3(-800.0f, 0.0f, 45.0f), &D3DXVECTOR3(0.0f, 180.0f, 0.0f));
  GimmickFactory::InstantiateThorns(&D3DXVECTOR3(-800.0f, 0.0f, -62.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));

  GimmickFactory::InstantiatePillar(&D3DXVECTOR3(-890.0f, 0.0f, 40.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
  GimmickFactory::InstantiatePillar(&D3DXVECTOR3(-890.0f, 0.0f, -60.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));


  GimmickFactory::InstantiateBell(&D3DXVECTOR3(-970.0f, 0.0f, 0.0f), &D3DXVECTOR3(0.0f, 90.0f, 0.0f));


  // UIゲージの枠
  GameFactory::CreateUIgaugeEdge();

  // UIゲージ
  auto uiGauge=GameFactory::CreateUIgauge();
  uiGauge->FindBehaviour<Behaviour::UIgauge>()->SetPlayer(player->FindBehaviour<Player>());

  //フェード
  GameFactory::CreateFade();

  return false;
}
  
}
}
}