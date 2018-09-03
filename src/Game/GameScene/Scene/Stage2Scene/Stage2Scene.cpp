//
//		�t�@�C����:Stage2Scene.cpp
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

	//�v���C���[
	auto player = GameFactory::CreatePlayer();

	// BGM�ESE�p
	GameEngine::GameObject* stageSoundObject = GameEngine::GameObject::Instantiate();
	auto stageSoundPlay = new GameEngine::Behaviour::SoundPlay();
	stageSoundPlay->SetSound(GameEngine::Sound::Sound::CreateFromWaveFile("./data/sound/game_honpen.wav", XAUDIO2_LOOP_INFINITE));
	stageSoundObject->AddBehaviour(stageSoundPlay);
	stageSoundPlay->Play();

	//�X�e�[�W�f�[�^
	StageLoader::LoadStage("./data/stage/stage2.txt");

	// UI�Q�[�W
	auto uiGauge = GameFactory::CreateUIgauge();
	uiGauge->FindBehaviour<Behaviour::UIgauge>()->SetPlayer(player->FindBehaviour<Player>());

	// �t�F�[�h�p
	GameFactory::CreateFade();

	return false;
}

}
}
}