//
//		ファイル名:Stage3Scene.cpp
//

#include "Stage3Scene.h"
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

Stage3Scene::Stage3Scene()
{

}

Stage3Scene::~Stage3Scene()
{
	SAFE_DELETE(farre);
}

bool Stage3Scene::Init()
{
	Fade::StartFadeIn();

	using Texture = GameEngine::Resource::Texture;
	using ResourceManager = GameEngine::Resource::ResourceManager;
	GameEngine::Environment::Get()->AttachPipeline(new Pipeline::Echo());

	//プレイヤー
	auto player = GameFactory::CreatePlayer();

	// BGM・SE用
	GameEngine::GameObject* stageSoundObject = GameEngine::GameObject::Instantiate();
	auto stageSoundPlay = new GameEngine::Behaviour::SoundPlay();
	stageSoundPlay->SetSound(GameEngine::Sound::Sound::CreateFromWaveFile("./data/sound/game_honpen.wav", XAUDIO2_LOOP_INFINITE));
	stageSoundObject->AddBehaviour(stageSoundPlay);
	stageSoundPlay->Play();

	//ステージ
	StageLoader::LoadStage("./data/stage/stage3.txt");
	
	// その１
	GimmickFactory::InstantiatePillar(&D3DXVECTOR3(-240.0f, 0.0f, -50.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	GimmickFactory::InstantiatePillar(&D3DXVECTOR3(-240.0f, 0.0f, -120.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	GimmickFactory::InstantiatePillar(&D3DXVECTOR3(-240.0f, 0.0f, -210.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	
	GimmickFactory::InstantiatePillar(&D3DXVECTOR3(-240.0f, 0.0f, 60.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	GimmickFactory::InstantiatePillar(&D3DXVECTOR3(-240.0f, 0.0f, 120.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	GimmickFactory::InstantiatePillar(&D3DXVECTOR3(-240.0f, 0.0f, 220.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));

	GimmickFactory::InstantiatePillar(&D3DXVECTOR3(-320.0f, 0.0f, -210.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	GimmickFactory::InstantiatePillar(&D3DXVECTOR3(-410.0f, 0.0f, -210.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	GimmickFactory::InstantiatePillar(&D3DXVECTOR3(-500.0f, 0.0f, -210.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	GimmickFactory::InstantiatePillar(&D3DXVECTOR3(-600.0f, 0.0f, -210.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));

	GimmickFactory::InstantiatePillar(&D3DXVECTOR3(-320.0f, 0.0f, 220.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	GimmickFactory::InstantiatePillar(&D3DXVECTOR3(-410.0f, 0.0f, 220.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	GimmickFactory::InstantiatePillar(&D3DXVECTOR3(-500.0f, 0.0f, 220.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	GimmickFactory::InstantiatePillar(&D3DXVECTOR3(-600.0f, 0.0f, 220.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));

	GimmickFactory::InstantiatePillar(&D3DXVECTOR3(-660.0f, 0.0f, -50.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	GimmickFactory::InstantiatePillar(&D3DXVECTOR3(-660.0f, 0.0f, -120.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	GimmickFactory::InstantiatePillar(&D3DXVECTOR3(-660.0f, 0.0f, -210.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
													
	GimmickFactory::InstantiatePillar(&D3DXVECTOR3(-660.0f, 0.0f, 60.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	GimmickFactory::InstantiatePillar(&D3DXVECTOR3(-660.0f, 0.0f, 120.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	GimmickFactory::InstantiatePillar(&D3DXVECTOR3(-660.0f, 0.0f, 220.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));

	GimmickFactory::InstantiatePillar(&D3DXVECTOR3(-410.0f, 0.0f, -80.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	GimmickFactory::InstantiatePillar(&D3DXVECTOR3(-410.0f, 0.0f, 95.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));

	GimmickFactory::InstantiatePillar(&D3DXVECTOR3(-500.0f, 0.0f, -80.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	GimmickFactory::InstantiatePillar(&D3DXVECTOR3(-500.0f, 0.0f, 95.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));


	GimmickFactory::InstantiateBronzeStatue(&D3DXVECTOR3(-360.0f, 0.0f, -200.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	GimmickFactory::InstantiateBronzeStatue(&D3DXVECTOR3(-460.0f, 0.0f, 0.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	GimmickFactory::InstantiateBronzeStatue(&D3DXVECTOR3(-560.0f, 0.0f, 100.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));


	// その２
	GimmickFactory::InstantiatePillar(&D3DXVECTOR3(-950.0f, 0.0f, -50.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	GimmickFactory::InstantiatePillar(&D3DXVECTOR3(-950.0f, 0.0f, -120.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	GimmickFactory::InstantiatePillar(&D3DXVECTOR3(-950.0f, 0.0f, -210.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));

	GimmickFactory::InstantiatePillar(&D3DXVECTOR3(-950.0f, 0.0f, 60.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	GimmickFactory::InstantiatePillar(&D3DXVECTOR3(-950.0f, 0.0f, 120.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	GimmickFactory::InstantiatePillar(&D3DXVECTOR3(-950.0f, 0.0f, 220.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));

	//GimmickFactory::InstantiateArmor(&D3DXVECTOR3(-970.0f, 0.0f, -80.0f), &D3DXVECTOR3(0.0f, -90.0f, 0.0f));

	GimmickFactory::InstantiateArmor(&D3DXVECTOR3(-970.0f, 0.0f, 90.0f), &D3DXVECTOR3(0.0f, -90.0f, 0.0f));
	//GimmickFactory::InstantiateArmor(&D3DXVECTOR3(-970.0f, 0.0f, 190.0f), &D3DXVECTOR3(0.0f, -90.0f, 0.0f));
	
	GimmickFactory::InstantiateArmor(&D3DXVECTOR3(-1030.0f, 0.0f, -110.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	GimmickFactory::InstantiateArmor(&D3DXVECTOR3(-1090.0f, 0.0f, -110.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));

	GimmickFactory::InstantiateArmor(&D3DXVECTOR3(-1070.0f, 0.0f, 190.0f), &D3DXVECTOR3(0.0f, 180.0f, 0.0f));
	GimmickFactory::InstantiateArmor(&D3DXVECTOR3(-1170.0f, 0.0f, 190.0f), &D3DXVECTOR3(0.0f, 180.0f, 0.0f));

	GimmickFactory::InstantiateBrokenPillar(&D3DXVECTOR3(-1110.0f, 0.0f, 0.0f), &D3DXVECTOR3(0.0f, -90.0f, 0.0f));
	//GimmickFactory::InstantiateBrokenPillar(&D3DXVECTOR3(-1160.0f, 0.0f, 50.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	//GimmickFactory::InstantiateBrokenPillar(&D3DXVECTOR3(-1210.0f, 0.0f, 0.0f), &D3DXVECTOR3(0.0f, 90.0f, 0.0f));

	GimmickFactory::InstantiateBronzeStatue(&D3DXVECTOR3(-1260.0f, 0.0f, -50.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));

	GimmickFactory::InstantiateArmor(&D3DXVECTOR3(-1140.0f, 0.0f, -120.0f), &D3DXVECTOR3(0.0f, -90.0f, 0.0f));
	GimmickFactory::InstantiateArmor(&D3DXVECTOR3(-1140.0f, 0.0f, -200.0f), &D3DXVECTOR3(0.0f, -90.0f, 0.0f));

	GimmickFactory::InstantiatePillar(&D3DXVECTOR3(-1200.0f, 0.0f, -210.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	GimmickFactory::InstantiatePillar(&D3DXVECTOR3(-1280.0f, 0.0f, -210.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	GimmickFactory::InstantiatePillar(&D3DXVECTOR3(-1370.0f, 0.0f, -210.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));

	//GimmickFactory::InstantiateBrokenPillar(&D3DXVECTOR3(-1300.0f, 0.0f, 100.0f), &D3DXVECTOR3(0.0f, 90.0f, 0.0f));

	GimmickFactory::InstantiatePillar(&D3DXVECTOR3(-1370.0f, 0.0f, -40.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	GimmickFactory::InstantiatePillar(&D3DXVECTOR3(-1370.0f, 0.0f, 50.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));


	// その３
	GimmickFactory::InstantiatePillar(&D3DXVECTOR3(-1650.0f, 0.0f, -50.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	GimmickFactory::InstantiatePillar(&D3DXVECTOR3(-1650.0f, 0.0f, -120.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	GimmickFactory::InstantiatePillar(&D3DXVECTOR3(-1650.0f, 0.0f, -210.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
													 
	GimmickFactory::InstantiatePillar(&D3DXVECTOR3(-1650.0f, 0.0f, 60.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	GimmickFactory::InstantiatePillar(&D3DXVECTOR3(-1650.0f, 0.0f, 120.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	GimmickFactory::InstantiatePillar(&D3DXVECTOR3(-1650.0f, 0.0f, 220.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));

	GimmickFactory::InstantiatePillar(&D3DXVECTOR3(-1730.0f, 0.0f, -210.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	GimmickFactory::InstantiatePillar(&D3DXVECTOR3(-1820.0f, 0.0f, -210.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	GimmickFactory::InstantiatePillar(&D3DXVECTOR3(-1920.0f, 0.0f, -210.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	GimmickFactory::InstantiatePillar(&D3DXVECTOR3(-2020.0f, 0.0f, -210.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));

	GimmickFactory::InstantiatePillar(&D3DXVECTOR3(-1730.0f, 0.0f, 220.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	GimmickFactory::InstantiatePillar(&D3DXVECTOR3(-1820.0f, 0.0f, 220.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	GimmickFactory::InstantiatePillar(&D3DXVECTOR3(-1920.0f, 0.0f, 220.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	GimmickFactory::InstantiatePillar(&D3DXVECTOR3(-2020.0f, 0.0f, 220.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));

	GimmickFactory::InstantiatePillar(&D3DXVECTOR3(-2080.0f, 0.0f, -50.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	GimmickFactory::InstantiatePillar(&D3DXVECTOR3(-2080.0f, 0.0f, -120.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	GimmickFactory::InstantiatePillar(&D3DXVECTOR3(-2080.0f, 0.0f, -210.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
													  
	GimmickFactory::InstantiatePillar(&D3DXVECTOR3(-2080.0f, 0.0f, 60.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	GimmickFactory::InstantiatePillar(&D3DXVECTOR3(-2080.0f, 0.0f, 120.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	GimmickFactory::InstantiatePillar(&D3DXVECTOR3(-2080.0f, 0.0f, 220.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));

	GimmickFactory::InstantiateArmor(&D3DXVECTOR3(-1710.0f, 0.0f, -50.0f), &D3DXVECTOR3(0.0f, 90.0f, 0.0f));
	//GimmickFactory::InstantiateArmor(&D3DXVECTOR3(-1680.0f, 0.0f, -80.0f), &D3DXVECTOR3(0.0f, 90.0f, 0.0f));
	GimmickFactory::InstantiateArmor(&D3DXVECTOR3(-1710.0f, 0.0f, -120.0f), &D3DXVECTOR3(0.0f, 90.0f, 0.0f));
	GimmickFactory::InstantiateArmor(&D3DXVECTOR3(-1710.0f, 0.0f, 60.0f), &D3DXVECTOR3(0.0f, 90.0f, 0.0f));
	//GimmickFactory::InstantiateArmor(&D3DXVECTOR3(-1680.0f, 0.0f, 90.0f), &D3DXVECTOR3(0.0f, 90.0f, 0.0f));
	GimmickFactory::InstantiateArmor(&D3DXVECTOR3(-1710.0f, 0.0f, 130.0f), &D3DXVECTOR3(0.0f, 90.0f, 0.0f));
	
	//GimmickFactory::InstantiateArmor(&D3DXVECTOR3(-2030.0f, 0.0f, 60.0f), &D3DXVECTOR3(0.0f, -90.0f, 0.0f));
	//GimmickFactory::InstantiateArmor(&D3DXVECTOR3(-2050.0f, 0.0f, 90.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	GimmickFactory::InstantiateArmor(&D3DXVECTOR3(-2030.0f, 0.0f, 130.0f), &D3DXVECTOR3(0.0f, -90.0f, 0.0f));

	GimmickFactory::InstantiateBronzeStatue(&D3DXVECTOR3(-2040.0f, 0.0f, 180.0f), &D3DXVECTOR3(0.0f, 90.0f, 0.0f));
	GimmickFactory::InstantiateBronzeStatue(&D3DXVECTOR3(-2040.0f, 0.0f, -10.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));

	//GimmickFactory::InstantiateBrokenPillar(&D3DXVECTOR3(-1770.0f, 0.0f, -180.0f), &D3DXVECTOR3(0.0f, 90.0f, 0.0f));

	GimmickFactory::InstantiateArmor(&D3DXVECTOR3(-1840.0f, 0.0f, -180.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	GimmickFactory::InstantiateArmor(&D3DXVECTOR3(-1970.0f, 0.0f, -180.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	GimmickFactory::InstantiateArmor(&D3DXVECTOR3(-2040.0f, 0.0f, -180.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));

	//GimmickFactory::InstantiateBrokenPillar(&D3DXVECTOR3(-2200.0f, 0.0f, 0.0f), &D3DXVECTOR3(0.0f, 90.0f, 0.0f));

	GimmickFactory::InstantiateBell(&D3DXVECTOR3(-2300.0f, 0.0f, 0.0f), &D3DXVECTOR3(0.0f, 90.0f, 0.0f));


	// UIゲージの枠用
	GameFactory::CreateUIgaugeEdge();

	// UIゲージ
	auto hoverGauge = GameFactory::CreateHoverGauge();
	auto sonarGauge = GameFactory::CreateSonarGauge();
	hoverGauge->FindBehaviour<Behaviour::UIgauge>()->SetPlayer(player->FindBehaviour<Player>());
	sonarGauge->FindBehaviour<Behaviour::UIgauge>()->SetPlayer(player->FindBehaviour<Player>());

	// フェード用
	GameFactory::CreateFade();

	return false;
}

}
}
}