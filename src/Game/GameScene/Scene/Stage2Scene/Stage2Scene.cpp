//
//		ファイル名:Stage2Scene.cpp
//

#include "Stage2Scene.h"
#include "../../../../GameEngine/GameEngine.h"
#include "../../../Common/Pipeline/Echo.h"
#include "../../../Common/Fade.h"
#include "../../Behaviour/UIgauge.h"
#include "../../GimmickFactory.h"
#include "../../GameFactory.h"
#include "../../StageLoader.h"
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
	Fade::StartFadeIn();

	using Texture = GameEngine::Resource::Texture;
	using ResourceManager = GameEngine::Resource::ResourceManager;
	GameEngine::Environment::Get()->AttachPipeline(new Pipeline::Echo());

	//ソナー
	auto sonar = GameFactory::CreateSonarEffect();

	//プレイヤー
	auto player = GameFactory::CreatePlayer();
	player->FindBehaviour<Behaviour::Player>()->SetSonar(sonar->FindBehaviour<Behaviour::Sonar>());

	// BGM・SE用
	GameEngine::GameObject* stageSoundObject = GameEngine::GameObject::Instantiate();
	auto stageSoundPlay = new GameEngine::Behaviour::SoundPlay();
	stageSoundPlay->SetSound(GameEngine::Sound::Sound::CreateFromWaveFile("./data/sound/game_honpen.wav", XAUDIO2_LOOP_INFINITE));
	stageSoundObject->AddBehaviour(stageSoundPlay);
	stageSoundPlay->Play();

	//ステージデータ
	StageLoader::LoadStage("./data/stage/stage2.txt");

	//壊れた柱
	//GimmickFactory::InstantiateBrokenPillar(&D3DXVECTOR3(-100.0f, 0.0f, 0.0f), &D3DXVECTOR3(0.0f, 90.0f, 0.0f));
	//GimmickFactory::InstantiateBrokenPillar(&D3DXVECTOR3(-100.0f, 0.0f, 0.0f), &D3DXVECTOR3(0.0f, 90.0f, 0.0f));
	//GimmickFactory::InstantiateBrokenPillar(&D3DXVECTOR3(-50.0f, 0.0f, -520.0f), &D3DXVECTOR3(0.0f, 90.0f, 0.0f));
	//GimmickFactory::InstantiateBrokenPillar(&D3DXVECTOR3(-50.0f, 0.0f, -420.0f), &D3DXVECTOR3(0.0f, 90.0f, 0.0f));

	GimmickFactory::InstantiateBrokenPillar(&D3DXVECTOR3(-190.0f, 0.0f, -734.0f), &D3DXVECTOR3(0.0f, 180.0f, 0.0f));
	
    GimmickFactory::InstantiateBrokenPillar(&D3DXVECTOR3(-260.0f, 0.0f, -204.0f), &D3DXVECTOR3(0.0f, 90.0f, 0.0f));

	//柱
    GimmickFactory::InstantiatePillar(&D3DXVECTOR3(60.0f, 0.0f, -111.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
    GimmickFactory::InstantiatePillar(&D3DXVECTOR3(-40.0f, 0.0f, -204.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));

    GimmickFactory::InstantiatePillar(&D3DXVECTOR3(180.0f, 0.0f, -204.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	GimmickFactory::InstantiatePillar(&D3DXVECTOR3(356.0f, 0.0f, -111.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	GimmickFactory::InstantiatePillar(&D3DXVECTOR3(440.0f, 0.0f, -204.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	GimmickFactory::InstantiatePillar(&D3DXVECTOR3(534.0f, 0.0f, -111.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));

    GimmickFactory::InstantiatePillar(&D3DXVECTOR3(534.0f, 0.0f, -295.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
    GimmickFactory::InstantiatePillar(&D3DXVECTOR3(440.0f, 0.0f, -400.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
    GimmickFactory::InstantiatePillar(&D3DXVECTOR3(534.0f, 0.0f, -558.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
    GimmickFactory::InstantiatePillar(&D3DXVECTOR3(440.0f, 0.0f, -651.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
    GimmickFactory::InstantiatePillar(&D3DXVECTOR3(534.0f, 0.0f, -744.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));

	GimmickFactory::InstantiatePillar(&D3DXVECTOR3(356.0f, 0.0f, -744.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	GimmickFactory::InstantiatePillar(&D3DXVECTOR3(250.0f, 0.0f, -651.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	GimmickFactory::InstantiatePillar(&D3DXVECTOR3(144.0f, 0.0f, -744.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	GimmickFactory::InstantiatePillar(&D3DXVECTOR3(38.0f, 0.0f, -651.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	GimmickFactory::InstantiatePillar(&D3DXVECTOR3(-68.0f, 0.0f, -744.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	GimmickFactory::InstantiatePillar(&D3DXVECTOR3(-214.0f, 0.0f, -651.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	GimmickFactory::InstantiatePillar(&D3DXVECTOR3(-310.0f, 0.0f, -744.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	
    GimmickFactory::InstantiatePillar(&D3DXVECTOR3(-310.0f, 0.0f, -558.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	GimmickFactory::InstantiatePillar(&D3DXVECTOR3(-214.0f, 0.0f, -450.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	GimmickFactory::InstantiatePillar(&D3DXVECTOR3(-310.0f, 0.0f, -355.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	GimmickFactory::InstantiatePillar(&D3DXVECTOR3(-310.0f, 0.0f, -260.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));

	//トゲ
	GimmickFactory::InstantiateThorns(&D3DXVECTOR3(370.0f, 0.0f, -637.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	GimmickFactory::InstantiateThorns(&D3DXVECTOR3(330.0f, 0.0f, -637.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));

	GimmickFactory::InstantiateThorns(&D3DXVECTOR3(60.0f, 0.0f, -758.0f), &D3DXVECTOR3(0.0f, 180.0f, 0.0f));
	GimmickFactory::InstantiateThorns(&D3DXVECTOR3(20.0f, 0.0f, -758.0f), &D3DXVECTOR3(0.0f, 180.0f, 0.0f));

	//飛び出すトゲ
	GimmickFactory::InstantiateThornsMove(&D3DXVECTOR3(130.0f, 0.0f, -110.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	GimmickFactory::InstantiateThornsMove(&D3DXVECTOR3(210.0f, 0.0f, -110.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	
    GimmickFactory::InstantiateThornsMove(&D3DXVECTOR3(260.0f, 0.0f, -758.0f), &D3DXVECTOR3(0.0f, 180.0f, 0.0f));
	GimmickFactory::InstantiateThornsMove(&D3DXVECTOR3(220.0f, 0.0f, -758.0f), &D3DXVECTOR3(0.0f, 180.0f, 0.0f));

	GimmickFactory::InstantiateThornsMove(&D3DXVECTOR3(160.0f, 0.0f, -637.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	GimmickFactory::InstantiateThornsMove(&D3DXVECTOR3(120.0f, 0.0f, -637.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));

	GimmickFactory::InstantiateThornsMove(&D3DXVECTOR3(-50.0f, 0.0f, -637.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	GimmickFactory::InstantiateThornsMove(&D3DXVECTOR3(-110.0f, 0.0f, -637.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));

	//鎧
	GimmickFactory::InstantiateArmor(&D3DXVECTOR3(-290.0f, 0.0f, -608.0f), &D3DXVECTOR3(0.0f, 90.0f, 0.0f));
	GimmickFactory::InstantiateArmor(&D3DXVECTOR3(-235.0f, 0.0f, -608.0f), &D3DXVECTOR3(0.0f, 270.0f, 0.0f));
  GimmickFactory::InstantiateArmor(&D3DXVECTOR3(-290.0f, 0.0f, -508.0f), &D3DXVECTOR3(0.0f, 90.0f, 0.0f));
  GimmickFactory::InstantiateArmor(&D3DXVECTOR3(-235.0f, 0.0f, -508.0f), &D3DXVECTOR3(0.0f, 270.0f, 0.0f));
  GimmickFactory::InstantiateArmor(&D3DXVECTOR3(-290.0f, 0.0f, -408.0f), &D3DXVECTOR3(0.0f, 90.0f, 0.0f));
  GimmickFactory::InstantiateArmor(&D3DXVECTOR3(-235.0f, 0.0f, -408.0f), &D3DXVECTOR3(0.0f, 270.0f, 0.0f));

  //銅像
  GimmickFactory::InstantiateBronzeStatue(&D3DXVECTOR3(490.0f, 7.0f, -700.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f)/*, &D3DXVECTOR3(490.0f, 7.0f, -700.0f), &D3DXVECTOR3(490.0f, 7.0f, -120.0f) 0.0F*/);

	//鐘
	GimmickFactory::InstantiateBell(&D3DXVECTOR3(-430.0f, 7.0f, -307.0f), &D3DXVECTOR3(0.0f, 90.0f, 0.0f));

	// UIゲージの枠用
	GameFactory::CreateUIgaugeEdge();

	// UIゲージ
	auto hoverGauge = GameFactory::CreateHoverGauge();
	auto sonarGauge = GameFactory::CreateSonarGauge();
	hoverGauge->FindBehaviour<Behaviour::UIgauge>()->SetPlayer(player->FindBehaviour<Behaviour::Player>());
	sonarGauge->FindBehaviour<Behaviour::UIgauge>()->SetPlayer(player->FindBehaviour<Behaviour::Player>());

	// フェード用
	GameFactory::CreateFade();

	return false;
}

}
}
}