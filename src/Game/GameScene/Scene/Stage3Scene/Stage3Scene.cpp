//
//		�t�@�C����:Stage3Scene.cpp
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

	//�v���C���[
	auto player = GameFactory::CreatePlayer();

	// BGM�ESE�p
	GameEngine::GameObject* stageSoundObject = GameEngine::GameObject::Instantiate();
	auto stageSoundPlay = new GameEngine::Behaviour::SoundPlay();
	stageSoundPlay->SetSound(GameEngine::Sound::Sound::CreateFromWaveFile("./data/sound/game_honpen.wav", XAUDIO2_LOOP_INFINITE));
	stageSoundObject->AddBehaviour(stageSoundPlay);
	stageSoundPlay->Play();

	//�X�e�[�W
	StageLoader::LoadStage("./data/stage/stage3.txt");

	// UI�Q�[�W�̘g�p
	GameEngine::GameObject* uiObject = GameEngine::GameObject::Instantiate();
	uiObject->GetTransform()->SetPosition(&D3DXVECTOR3(400.0f, 300.0f, 0.0f));
	uiObject->GetTransform()->SetScale(&D3DXVECTOR3(800.0f, 600.0f, 50.0f));
	auto uiRenderer = new GameEngine::Behaviour::UIRenderer(GameEngine::Resource::ResourceManager::Get<Texture>("./data/texture/UIgauge.png"));
	uiRenderer->SetColor(D3DCOLOR_ARGB(255, 255, 255, 255));
	uiObject->AddBehaviour(uiRenderer);

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