//
//		t@CΌ:Stage2Scene.cpp
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

	//vC[
	auto player = GameFactory::CreatePlayer();

	// BGMESEp
	GameEngine::GameObject* stageSoundObject = GameEngine::GameObject::Instantiate();
	auto stageSoundPlay = new GameEngine::Behaviour::SoundPlay();
	stageSoundPlay->SetSound(GameEngine::Sound::Sound::CreateFromWaveFile("./data/sound/game_honpen.wav", XAUDIO2_LOOP_INFINITE));
	stageSoundObject->AddBehaviour(stageSoundPlay);
	stageSoundPlay->Play();

	//Xe[Wf[^
	StageLoader::LoadStage("./data/stage/stage2.txt");

	//σκ½
	GimmickFactory::InstantiateBrokenPillar(&D3DXVECTOR3(-100.0f, 0.0f, 0.0f), &D3DXVECTOR3(0.0f, 90.0f, 0.0f));
	GimmickFactory::InstantiateBrokenPillar(&D3DXVECTOR3(-100.0f, 0.0f, 0.0f), &D3DXVECTOR3(0.0f, 90.0f, 0.0f));
	GimmickFactory::InstantiateBrokenPillar(&D3DXVECTOR3(-100.0f, 0.0f, 0.0f), &D3DXVECTOR3(0.0f, 90.0f, 0.0f));
	GimmickFactory::InstantiateBrokenPillar(&D3DXVECTOR3(-100.0f, 0.0f, 0.0f), &D3DXVECTOR3(0.0f, 90.0f, 0.0f));
	GimmickFactory::InstantiateBrokenPillar(&D3DXVECTOR3(-100.0f, 0.0f, 0.0f), &D3DXVECTOR3(0.0f, 90.0f, 0.0f));

	GimmickFactory::InstantiateBrokenPillar(&D3DXVECTOR3(-100.0f, 0.0f, 0.0f), &D3DXVECTOR3(0.0f, 90.0f, 0.0f));
	GimmickFactory::InstantiateBrokenPillar(&D3DXVECTOR3(-100.0f, 0.0f, 0.0f), &D3DXVECTOR3(0.0f, 90.0f, 0.0f));
	GimmickFactory::InstantiateBrokenPillar(&D3DXVECTOR3(-100.0f, 0.0f, 0.0f), &D3DXVECTOR3(0.0f, 90.0f, 0.0f));

	//
	GimmickFactory::InstantiatePillar(&D3DXVECTOR3(0.0f, 0.0f, 20.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	GimmickFactory::InstantiatePillar(&D3DXVECTOR3(0.0f, 0.0f, 20.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	GimmickFactory::InstantiatePillar(&D3DXVECTOR3(0.0f, 0.0f, 20.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	GimmickFactory::InstantiatePillar(&D3DXVECTOR3(0.0f, 0.0f, 20.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	GimmickFactory::InstantiatePillar(&D3DXVECTOR3(0.0f, 0.0f, 20.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));

	GimmickFactory::InstantiatePillar(&D3DXVECTOR3(0.0f, 0.0f, 20.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	GimmickFactory::InstantiatePillar(&D3DXVECTOR3(0.0f, 0.0f, 20.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	GimmickFactory::InstantiatePillar(&D3DXVECTOR3(0.0f, 0.0f, 20.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	GimmickFactory::InstantiatePillar(&D3DXVECTOR3(0.0f, 0.0f, 20.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	GimmickFactory::InstantiatePillar(&D3DXVECTOR3(0.0f, 0.0f, 20.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));

	GimmickFactory::InstantiatePillar(&D3DXVECTOR3(0.0f, 0.0f, 20.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	GimmickFactory::InstantiatePillar(&D3DXVECTOR3(0.0f, 0.0f, 20.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	GimmickFactory::InstantiatePillar(&D3DXVECTOR3(0.0f, 0.0f, 20.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	GimmickFactory::InstantiatePillar(&D3DXVECTOR3(0.0f, 0.0f, 20.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	GimmickFactory::InstantiatePillar(&D3DXVECTOR3(0.0f, 0.0f, 20.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));

	GimmickFactory::InstantiatePillar(&D3DXVECTOR3(0.0f, 0.0f, 20.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	GimmickFactory::InstantiatePillar(&D3DXVECTOR3(0.0f, 0.0f, 20.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	GimmickFactory::InstantiatePillar(&D3DXVECTOR3(0.0f, 0.0f, 20.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	GimmickFactory::InstantiatePillar(&D3DXVECTOR3(0.0f, 0.0f, 20.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	GimmickFactory::InstantiatePillar(&D3DXVECTOR3(0.0f, 0.0f, 20.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));

	GimmickFactory::InstantiatePillar(&D3DXVECTOR3(0.0f, 0.0f, 20.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	GimmickFactory::InstantiatePillar(&D3DXVECTOR3(0.0f, 0.0f, 20.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));

	//gQ
	GimmickFactory::InstantiateThorns(&D3DXVECTOR3(0.0f, 0.0f, 20.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	GimmickFactory::InstantiateThorns(&D3DXVECTOR3(0.0f, 0.0f, 20.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	GimmickFactory::InstantiateThorns(&D3DXVECTOR3(0.0f, 0.0f, 20.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	GimmickFactory::InstantiateThorns(&D3DXVECTOR3(0.0f, 0.0f, 20.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	GimmickFactory::InstantiateThorns(&D3DXVECTOR3(0.0f, 0.0f, 20.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));

	GimmickFactory::InstantiateThorns(&D3DXVECTOR3(0.0f, 0.0f, 20.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));


	//ςΡo·gQ
	GimmickFactory::InstantiateThornsMove(&D3DXVECTOR3(0.0f, 0.0f, 20.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	GimmickFactory::InstantiateThornsMove(&D3DXVECTOR3(0.0f, 0.0f, 20.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	GimmickFactory::InstantiateThornsMove(&D3DXVECTOR3(0.0f, 0.0f, 20.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	GimmickFactory::InstantiateThornsMove(&D3DXVECTOR3(0.0f, 0.0f, 20.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	GimmickFactory::InstantiateThornsMove(&D3DXVECTOR3(0.0f, 0.0f, 20.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));

	GimmickFactory::InstantiateThornsMove(&D3DXVECTOR3(0.0f, 0.0f, 20.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	GimmickFactory::InstantiateThornsMove(&D3DXVECTOR3(0.0f, 0.0f, 20.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	GimmickFactory::InstantiateThornsMove(&D3DXVECTOR3(0.0f, 0.0f, 20.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	GimmickFactory::InstantiateThornsMove(&D3DXVECTOR3(0.0f, 0.0f, 20.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	GimmickFactory::InstantiateThornsMove(&D3DXVECTOR3(0.0f, 0.0f, 20.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));

	GimmickFactory::InstantiateThornsMove(&D3DXVECTOR3(0.0f, 0.0f, 20.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	GimmickFactory::InstantiateThornsMove(&D3DXVECTOR3(0.0f, 0.0f, 20.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	GimmickFactory::InstantiateThornsMove(&D3DXVECTOR3(0.0f, 0.0f, 20.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	GimmickFactory::InstantiateThornsMove(&D3DXVECTOR3(0.0f, 0.0f, 20.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));

	//Z
	GimmickFactory::InstantiateArmor(&D3DXVECTOR3(0.0f, 0.0f, 20.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	GimmickFactory::InstantiateArmor(&D3DXVECTOR3(0.0f, 0.0f, 20.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	GimmickFactory::InstantiateArmor(&D3DXVECTOR3(0.0f, 0.0f, 20.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	GimmickFactory::InstantiateArmor(&D3DXVECTOR3(0.0f, 0.0f, 20.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	GimmickFactory::InstantiateArmor(&D3DXVECTOR3(0.0f, 0.0f, 20.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	GimmickFactory::InstantiateArmor(&D3DXVECTOR3(0.0f, 0.0f, 20.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));

	//ΰ
	GimmickFactory::InstantiateBell(&D3DXVECTOR3(0.0f, 7.0f, 20.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));

	//Ί
	GimmickFactory::InstantiateBronzeStatue(&D3DXVECTOR3(0.0f, 7.0f, 10.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	GimmickFactory::InstantiateBronzeStatue(&D3DXVECTOR3(0.0f, 7.0f, 10.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));

	// UIQ[WΜgp
	GameFactory::CreateUIgaugeEdge();

	// UIQ[W
	auto hoverGauge = GameFactory::CreateHoverGauge();
	auto sonarGauge = GameFactory::CreateSonarGauge();
	hoverGauge->FindBehaviour<Behaviour::UIgauge>()->SetPlayer(player->FindBehaviour<Player>());
	sonarGauge->FindBehaviour<Behaviour::UIgauge>()->SetPlayer(player->FindBehaviour<Player>());

	// tF[hp
	GameFactory::CreateFade();

	return false;
}

}
}
}