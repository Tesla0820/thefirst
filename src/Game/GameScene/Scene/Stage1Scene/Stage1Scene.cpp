//
//		ファイル名:Stage1Scene.cpp
//

#include "Stage1Scene.h"
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

bool Stage1Scene::Init()
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

	//ステージ
	StageLoader::LoadStage("./data/stage/stage1.txt");

	//壊れた柱
	GimmickFactory::InstantiateBrokenPillar(&D3DXVECTOR3(-377.5f, 0.0f, -130.5f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	GimmickFactory::InstantiateBrokenPillar(&D3DXVECTOR3(-497.5f, 0.0f, -190.5f), &D3DXVECTOR3(0.0f, 180.0f, 0.0f));
	
    GimmickFactory::InstantiateBrokenPillar(&D3DXVECTOR3(-802.5f, 0.0f, -25.5f), &D3DXVECTOR3(0.0f, 90.0f, 0.0f));

	//柱
	GimmickFactory::InstantiatePillar(&D3DXVECTOR3( -62.5f, 0.0f,  52.5f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	GimmickFactory::InstantiatePillar(&D3DXVECTOR3(-262.5f, 0.0f,  52.5f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	GimmickFactory::InstantiatePillar(&D3DXVECTOR3(-172.5f, 0.0f, -45.5f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	GimmickFactory::InstantiatePillar(&D3DXVECTOR3(-262.5f, 0.0f, -92.5f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	GimmickFactory::InstantiatePillar(&D3DXVECTOR3(-172.5f, 0.0f,-182.5f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));

	GimmickFactory::InstantiatePillar(&D3DXVECTOR3(-367.5f, 0.0f,-210.5f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	GimmickFactory::InstantiatePillar(&D3DXVECTOR3(-487.5f, 0.0f, -112.5f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	GimmickFactory::InstantiatePillar(&D3DXVECTOR3(-592.5f, 0.0f,-210.5f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	
    GimmickFactory::InstantiatePillar(&D3DXVECTOR3(-502.5f, 0.0f,  17.5f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
    GimmickFactory::InstantiatePillar(&D3DXVECTOR3(-502.5f, 0.0f, 217.5f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	GimmickFactory::InstantiatePillar(&D3DXVECTOR3(-602.5f, 0.0f, 117.5f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));

	GimmickFactory::InstantiatePillar(&D3DXVECTOR3(-679.5f, 0.0f, 219.5f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	GimmickFactory::InstantiatePillar(&D3DXVECTOR3(-769.5f, 0.0f, 125.5f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	GimmickFactory::InstantiatePillar(&D3DXVECTOR3(-865.5f, 0.0f, 219.5f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	
    
    GimmickFactory::InstantiatePillar(&D3DXVECTOR3(-865.5f, 0.0f,  42.5f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	GimmickFactory::InstantiatePillar(&D3DXVECTOR3(-772.5f, 0.0f, -17.5f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	GimmickFactory::InstantiatePillar(&D3DXVECTOR3(-865.5f, 0.0f, -110.5f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	GimmickFactory::InstantiatePillar(&D3DXVECTOR3(-772.5f, 0.0f,-182.5f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));

	//トゲ
	GimmickFactory::InstantiateThorns(&D3DXVECTOR3(-150.0f, 0.0f, 70.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
    GimmickFactory::InstantiateThorns(&D3DXVECTOR3(-210.0f, 0.0f, 70.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));

    GimmickFactory::InstantiateThorns(&D3DXVECTOR3(-280.0f, 0.0f, -20.0f), &D3DXVECTOR3(0.0f, 270.0f, 0.0f));

    GimmickFactory::InstantiateThorns(&D3DXVECTOR3(-150.0f, 0.0f, -115.0f), &D3DXVECTOR3(0.0f, 90.0f, 0.0f));

	GimmickFactory::InstantiateThorns(&D3DXVECTOR3(-612.5f, 0.0f, -70.5f), &D3DXVECTOR3(0.0f, 270.0f, 0.0f));
    GimmickFactory::InstantiateThorns(&D3DXVECTOR3(-612.5f, 0.0f, -110.5f), &D3DXVECTOR3(0.0f, 270.0f, 0.0f));

	GimmickFactory::InstantiateThorns(&D3DXVECTOR3(-487.5f, 0.0f, 100.5f), &D3DXVECTOR3(0.0f, 90.0f, 0.0f));
    GimmickFactory::InstantiateThorns(&D3DXVECTOR3(-487.5f, 0.0f, 140.5f), &D3DXVECTOR3(0.0f, 90.0f, 0.0f));

	GimmickFactory::InstantiateThorns(&D3DXVECTOR3(-877.5f, 0.0f, 129.5f), &D3DXVECTOR3(0.0f, 270.0f, 0.0f));
	GimmickFactory::InstantiateThorns(&D3DXVECTOR3(-877.5f, 0.0f, 89.5f), &D3DXVECTOR3(0.0f, 270.0f, 0.0f));

	//鎧
	GimmickFactory::InstantiateArmor(&D3DXVECTOR3(-639.5f, 0.0f, 219.5f), &D3DXVECTOR3(0.0f, 180.0f, 0.0f));
    GimmickFactory::InstantiateArmor(&D3DXVECTOR3(-639.5f, 0.0f, 125.5f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
    GimmickFactory::InstantiateArmor(&D3DXVECTOR3(-719.5f, 0.0f, 219.5f), &D3DXVECTOR3(0.0f, 180.0f, 0.0f));
    GimmickFactory::InstantiateArmor(&D3DXVECTOR3(-719.5f, 0.0f, 125.5f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));

	//鐘
	GimmickFactory::InstantiateBell(&D3DXVECTOR3(-1000.5f, 0.0f, -160.5f), &D3DXVECTOR3(0.0f, 90.0f, 0.0f));

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