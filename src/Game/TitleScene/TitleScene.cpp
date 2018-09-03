//
//		�t�@�C����:TitleScene.cpp
//

#include "TitleScene.h"
#include "../../GameEngine/GameEngine.h"
#include "../Common/Pipeline/Echo.h"
#include "TitleManager.h"
#include "../Common/Fade.h"

namespace Game
{

TitleScene::TitleScene()
{

}

TitleScene::~TitleScene()
{
	SAFE_DELETE(farre);
}

bool TitleScene::Init()
{
	Fade::StartFadeIn();

	using Texture = GameEngine::Resource::Texture;
	using ResourceManager	= GameEngine::Resource::ResourceManager;

	// �w�i�̕`��
	GameEngine::GameObject* backgroundObject = GameEngine::GameObject::Instantiate();
	backgroundObject->GetTransform()->SetPosition(&D3DXVECTOR3(400.0f, 300.0f, 0.0f));
	backgroundObject->GetTransform()->SetScale(&D3DXVECTOR3(800.0f, 600.0f, 50.0f));
	auto backgroundRenderer = new GameEngine::Behaviour::UIRenderer(GameEngine::Resource::ResourceManager::Get<Texture>("./data/texture/titlebackground.png"));
	backgroundRenderer->SetColor(D3DCOLOR_ARGB(255, 255, 255, 255));
	backgroundObject->AddBehaviour(backgroundRenderer);


	GameEngine::GameObject* titleManagerObject = GameEngine::GameObject::Instantiate();
	titleManagerObject->GetTransform()->SetPosition(&D3DXVECTOR3(300.0f, 400.0f, 0.0f));
	titleManagerObject->GetTransform()->SetScale(&D3DXVECTOR3(50.0f, 50.0f, 50.0f));
	auto titleManager = new Game::TitleManager();
	auto titleManagerRenderer = new GameEngine::Behaviour::UIRenderer(GameEngine::Resource::ResourceManager::Get<Texture>("./data/texture/select.png"));
	auto titleManagerSoundPlay = new GameEngine::Behaviour::SoundPlay();
	titleManagerRenderer->SetColor(D3DCOLOR_ARGB(255, 255, 255, 255));
	titleManagerSoundPlay->SetSound(GameEngine::Sound::Sound::CreateFromWaveFile("./data/sound/title.wav",XAUDIO2_LOOP_INFINITE));
	titleManagerObject->AddBehaviour(titleManagerRenderer);
	titleManagerObject->AddBehaviour(titleManager);
	titleManagerObject->AddBehaviour(titleManagerSoundPlay);
	titleManagerSoundPlay->Play();

	// �^�C�g���̕`��
	GameEngine::GameObject* titleObject = GameEngine::GameObject::Instantiate();
	titleObject->GetTransform()->SetPosition(&D3DXVECTOR3(400.0f, 300.0f, 0.0f));
	titleObject->GetTransform()->SetScale(&D3DXVECTOR3(600.0f, 150.0f, 50.0f));
	auto titleRenderer = new GameEngine::Behaviour::UIRenderer(GameEngine::Resource::ResourceManager::Get<Texture>("./data/texture/title.png"));
	titleRenderer->SetColor(D3DCOLOR_ARGB(255, 255, 255, 255));
	titleObject->AddBehaviour(titleRenderer);

	// �`���[�g���A���̕����̕\��
	GameEngine::GameObject* stageObject = GameEngine::GameObject::Instantiate();
	stageObject->GetTransform()->SetPosition(&D3DXVECTOR3(400.0f, 400.0f, 0.0f));
	stageObject->GetTransform()->SetScale(&D3DXVECTOR3(250.0f, 70.0f, 50.0f));
	auto stageRenderer = new GameEngine::Behaviour::UIRenderer(GameEngine::Resource::ResourceManager::Get<Texture>("./data/texture/tutorial.png"));
	stageRenderer->SetColor(D3DCOLOR_ARGB(255, 255, 255, 255));
	stageObject->AddBehaviour(stageRenderer);

	// �X�e�[�W�P�̕����̕\��
	GameEngine::GameObject* stageObject2 = GameEngine::GameObject::Instantiate();
	stageObject2->GetTransform()->SetPosition(&D3DXVECTOR3(400.0f, 450.0f, 0.0f));
	stageObject2->GetTransform()->SetScale(&D3DXVECTOR3(250.0f, 70.0f, 50.0f));
	auto stageRenderer2 = new GameEngine::Behaviour::UIRenderer(GameEngine::Resource::ResourceManager::Get<Texture>("./data/texture/stage1.png"));
	stageRenderer2->SetColor(D3DCOLOR_ARGB(255, 255, 255, 255));
	stageObject2->AddBehaviour(stageRenderer2);

	// �X�e�[�W�Q�̕����̕\��
	GameEngine::GameObject* stageObject3 = GameEngine::GameObject::Instantiate();
	stageObject3->GetTransform()->SetPosition(&D3DXVECTOR3(400.0f, 500.0f, 0.0f));
	stageObject3->GetTransform()->SetScale(&D3DXVECTOR3(250.0f, 70.0f, 50.0f));
	auto stageRenderer3 = new GameEngine::Behaviour::UIRenderer(GameEngine::Resource::ResourceManager::Get<Texture>("./data/texture/stage2.png"));
	stageRenderer3->SetColor(D3DCOLOR_ARGB(255, 255, 255, 255));
	stageObject3->AddBehaviour(stageRenderer3);

	// �X�e�[�W�R�̕����̕\��
	GameEngine::GameObject* stageObject4 = GameEngine::GameObject::Instantiate();
	stageObject4->GetTransform()->SetPosition(&D3DXVECTOR3(400.0f, 550.0f, 0.0f));
	stageObject4->GetTransform()->SetScale(&D3DXVECTOR3(250.0f, 70.0f, 50.0f));
	auto stageRenderer4 = new GameEngine::Behaviour::UIRenderer(GameEngine::Resource::ResourceManager::Get<Texture>("./data/texture/stage3.png"));
	stageRenderer4->SetColor(D3DCOLOR_ARGB(255, 255, 255, 255));
	stageObject4->AddBehaviour(stageRenderer4);

	// �t�F�[�h�p
	GameEngine::GameObject* fadeObject = GameEngine::GameObject::Instantiate();
	fadeObject->GetTransform()->SetPosition(&D3DXVECTOR3(400.0f, 300.0f, 0.0f));
	fadeObject->GetTransform()->SetScale(&D3DXVECTOR3(800.0f, 600.0f, 50.0f));
	auto fade = new Game::Fade();
	auto fadeRenderer = new GameEngine::Behaviour::UIRenderer();
	fadeRenderer->SetColor(D3DCOLOR_ARGB(255, 0, 0, 0));
	fadeObject->AddBehaviour(fadeRenderer);
	fadeObject->AddBehaviour(fade);
	return false;
}


}