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
  
  // UIゲージの枠用
  GameEngine::GameObject* uiObject = GameEngine::GameObject::Instantiate();
  uiObject->GetTransform()->SetPosition(&D3DXVECTOR3(400.0f, 300.0f, 0.0f));
  uiObject->GetTransform()->SetScale(&D3DXVECTOR3(800.0f, 600.0f, 50.0f));
  auto uiRenderer = new GameEngine::Behaviour::UIRenderer(GameEngine::Resource::ResourceManager::Get<Texture>("./data/texture/UIgauge.png"));
  uiRenderer->SetColor(D3DCOLOR_ARGB(255, 255, 255, 255));
  uiObject->AddBehaviour(uiRenderer);

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