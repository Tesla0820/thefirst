//
//		ファイル名:TutorialScene.cpp
//

#include "TutorialScene.h"
#include "../../../../GameEngine/GameEngine.h"
#include "../../../Common/Pipeline/Echo.h"
#include "../../../Common/Fade.h"
#include "../../Behaviour/UIgauge.h"
#include "../../Behaviour/player.h"
#include "../../Behaviour/Sonar.h"
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

  //ソナー
  auto sonar = GameFactory::CreateSonarEffect();

  //プレイヤー
  auto player = GameFactory::CreatePlayer();
  player->FindBehaviour<Behaviour::Player>()->SetSonar(sonar->FindBehaviour<Behaviour::Sonar>());

  // マネージャー用
  GameEngine::GameObject* tutorialManagerObject = GameEngine::GameObject::Instantiate();
  auto tutorialmanager = new Game::GameScene::Scene::TutorialManager();
  tutorialManagerObject->AddBehaviour(tutorialmanager);
  auto tutorialManagerSoundPlay = new GameEngine::Behaviour::SoundPlay();
  tutorialManagerSoundPlay->SetSound(GameEngine::Sound::Sound::CreateFromWaveFile("./data/sound/game_honpen.wav", XAUDIO2_LOOP_INFINITE));
  tutorialManagerObject->AddBehaviour(tutorialManagerSoundPlay);
  tutorialManagerSoundPlay->Play(); 

  //ステージ
  StageLoader::LoadStage("./data/stage/stage0.txt");

  GimmickFactory::InstantiateBronzeStatue(&D3DXVECTOR3(-100.0f, 0.0f, 0.0f), &D3DXVECTOR3(0.0f, 90.0f, 0.0f), &D3DXVECTOR3(-100.0f, 0.0f, 0.0f), &D3DXVECTOR3(-100.0f, 0.0f, 0.0f), 1.0F);

  
  //GimmickFactory::InstantiateBrokenPillar(&D3DXVECTOR3(-100.0f, 0.0f, 0.0f), &D3DXVECTOR3(0.0f, 90.0f, 0.0f));
  //GimmickFactory::InstantiateArmor(&D3DXVECTOR3(-410.0f, 0.0f, -60.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));

  //GimmickFactory::InstantiatePillar(&D3DXVECTOR3(-450.0f, 0.0f, 40.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
  //GimmickFactory::InstantiatePillar(&D3DXVECTOR3(-450.0f, 0.0f, -60.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
  //GimmickFactory::InstantiateArmor(&D3DXVECTOR3(-510.0f, 0.0f, 40.0f), &D3DXVECTOR3(0.0f, 180.0f, 0.0f));
  //GimmickFactory::InstantiateArmor(&D3DXVECTOR3(-510.0f, 0.0f, -60.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
  //GimmickFactory::InstantiatePillar(&D3DXVECTOR3(-590.0f, 0.0f, 40.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
  //GimmickFactory::InstantiatePillar(&D3DXVECTOR3(-590.0f, 0.0f, -60.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));


  //GimmickFactory::InstantiateThorns(&D3DXVECTOR3(-800.0f, 0.0f, 45.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
  //GimmickFactory::InstantiateThorns(&D3DXVECTOR3(-800.0f, 0.0f, -62.0f), &D3DXVECTOR3(0.0f, 180.0f, 0.0f));

  //GimmickFactory::InstantiatePillar(&D3DXVECTOR3(-890.0f, 0.0f, 40.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
  //GimmickFactory::InstantiatePillar(&D3DXVECTOR3(-890.0f, 0.0f, -60.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
  //
  //GimmickFactory::InstantiateBell(&D3DXVECTOR3(-970.0f, 0.0f, 0.0f), &D3DXVECTOR3(0.0f, 90.0f, 0.0f));

  // UIゲージの枠
  GameFactory::CreateUIgaugeEdge();

  // UIゲージ
  auto hoverGauge = GameFactory::CreateHoverGauge();
  auto sonarGauge = GameFactory::CreateSonarGauge();
  hoverGauge->FindBehaviour<Behaviour::UIgauge>()->SetPlayer(player->FindBehaviour<Behaviour::Player>());
  sonarGauge->FindBehaviour<Behaviour::UIgauge>()->SetPlayer(player->FindBehaviour<Behaviour::Player>());
  //フェード
  GameFactory::CreateFade();

  return false;
}
  
}
}
}