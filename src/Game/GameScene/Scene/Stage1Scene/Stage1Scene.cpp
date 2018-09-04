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

	//プレイヤー
	auto player = GameFactory::CreatePlayer();
		
    //ギミック
    //GimmickFactory::InstantiateArmor(&D3DXVECTOR3(0.0f, 0.0f, 20.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
    //GimmickFactory::InstantiateBell(&D3DXVECTOR3(0.0f, 7.0f, 20.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
    //GimmickFactory::InstantiateBrokenPillar(&D3DXVECTOR3(0.0f, 0.0f, 20.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
    //GimmickFactory::InstantiateBronzeStatue(&D3DXVECTOR3(0.0f, 7.0f, 10.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
    //GimmickFactory::InstantiatePillar(&D3DXVECTOR3(0.0f, 0.0f, 20.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
    //GimmickFactory::InstantiateThorns(&D3DXVECTOR3(0.0f, 0.0f, 20.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
    //GimmickFactory::InstantiateThornsMove(&D3DXVECTOR3(0.0f, 0.0f, 20.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));

	// BGM・SE用
	GameEngine::GameObject* stageSoundObject = GameEngine::GameObject::Instantiate();
	auto stageSoundPlay = new GameEngine::Behaviour::SoundPlay();
	stageSoundPlay->SetSound(GameEngine::Sound::Sound::CreateFromWaveFile("./data/sound/game_honpen.wav", XAUDIO2_LOOP_INFINITE));
	stageSoundObject->AddBehaviour(stageSoundPlay);
	stageSoundPlay->Play();

	//ステージ
	StageLoader::LoadStage("./data/stage/stage1.txt");

	//壊れた柱
	GimmickFactory::InstantiateBrokenPillar(&D3DXVECTOR3(0.0f, 0.0f, 20.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	GimmickFactory::InstantiateBrokenPillar(&D3DXVECTOR3(0.0f, 0.0f, 20.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	GimmickFactory::InstantiateBrokenPillar(&D3DXVECTOR3(0.0f, 0.0f, 20.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));

	//柱
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

	//トゲ
	GimmickFactory::InstantiateThorns(&D3DXVECTOR3(0.0f, 0.0f, 20.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	GimmickFactory::InstantiateThorns(&D3DXVECTOR3(0.0f, 0.0f, 20.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	GimmickFactory::InstantiateThorns(&D3DXVECTOR3(0.0f, 0.0f, 20.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	GimmickFactory::InstantiateThorns(&D3DXVECTOR3(0.0f, 0.0f, 20.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	GimmickFactory::InstantiateThorns(&D3DXVECTOR3(0.0f, 0.0f, 20.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));

	GimmickFactory::InstantiateThorns(&D3DXVECTOR3(0.0f, 0.0f, 20.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	GimmickFactory::InstantiateThorns(&D3DXVECTOR3(0.0f, 0.0f, 20.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	GimmickFactory::InstantiateThorns(&D3DXVECTOR3(0.0f, 0.0f, 20.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	GimmickFactory::InstantiateThorns(&D3DXVECTOR3(0.0f, 0.0f, 20.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	GimmickFactory::InstantiateThorns(&D3DXVECTOR3(0.0f, 0.0f, 20.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));

	GimmickFactory::InstantiateThorns(&D3DXVECTOR3(0.0f, 0.0f, 20.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	GimmickFactory::InstantiateThorns(&D3DXVECTOR3(0.0f, 0.0f, 20.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	GimmickFactory::InstantiateThorns(&D3DXVECTOR3(0.0f, 0.0f, 20.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	GimmickFactory::InstantiateThorns(&D3DXVECTOR3(0.0f, 0.0f, 20.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	GimmickFactory::InstantiateThorns(&D3DXVECTOR3(0.0f, 0.0f, 20.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));

	GimmickFactory::InstantiateThorns(&D3DXVECTOR3(0.0f, 0.0f, 20.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	GimmickFactory::InstantiateThorns(&D3DXVECTOR3(0.0f, 0.0f, 20.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	GimmickFactory::InstantiateThorns(&D3DXVECTOR3(0.0f, 0.0f, 20.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));

	//鎧
	GimmickFactory::InstantiateArmor(&D3DXVECTOR3(0.0f, 0.0f, 20.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	GimmickFactory::InstantiateArmor(&D3DXVECTOR3(0.0f, 0.0f, 20.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	GimmickFactory::InstantiateArmor(&D3DXVECTOR3(0.0f, 0.0f, 20.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	GimmickFactory::InstantiateArmor(&D3DXVECTOR3(0.0f, 0.0f, 20.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));

	//鐘
	GimmickFactory::InstantiateBell(&D3DXVECTOR3(0.0f, 7.0f, 20.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));

	// UIゲージの枠用
	GameEngine::GameObject* uiObject = GameEngine::GameObject::Instantiate();
	uiObject->GetTransform()->SetPosition(&D3DXVECTOR3(400.0f, 300.0f, 0.0f));
	uiObject->GetTransform()->SetScale(&D3DXVECTOR3(800.0f, 600.0f, 50.0f));
	auto uiRenderer = new GameEngine::Behaviour::UIRenderer(GameEngine::Resource::ResourceManager::Get<Texture>("./data/texture/UIgauge.png"));
	uiRenderer->SetColor(D3DCOLOR_ARGB(255, 255, 255, 255));
	uiObject->AddBehaviour(uiRenderer);

	// UIゲージ
	auto uiGauge = GameFactory::CreateUIgauge();
	uiGauge->FindBehaviour<Behaviour::UIgauge>()->SetPlayer(player->FindBehaviour<Player>());

	// フェード用
	GameFactory::CreateFade();

	return false;
}

}
}
}