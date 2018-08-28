//
//		�t�@�C����:main.cpp
//

// �C���N���[�h��
#include "main.h"
#include "../GameEngine/GameEngine.h"
#include "TitleScene/TitleScene.h"
#include "GameScene/Scene/TutorialScene/TutorialScene.h"
#include "GameScene/Scene/Stage1Scene/Stage1Scene.h"
#include "GameScene/Scene/Stage2Scene/Stage2Scene.h"
#include "GameScene/Scene/Stage3Scene/Stage3Scene.h"
#include "ResultScene/StageClearScene/StageClearScene.h"
#include "ResultScene/GameClearScene/GameClearScene.h"
#include "ResultScene/GameOverScene/GameOverScene.h"

// �v���g�^�C�v�錾
int Run(); //�v���O�����̎��s
void RegisterScenes();

// ���C���֐�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);	
	UNREFERENCED_PARAMETER(lpCmdLine);
	UNREFERENCED_PARAMETER(nCmdShow);

	int result;
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	// COM ���C�u����������
	CoInitializeEx(NULL, COINIT_MULTITHREADED);

	//���s
	result = Run();

	// COM ���C�u���������
	CoUninitialize();

	//return (int)msg.wParam;
	return result;
}

int Run()
{
	int result;
	GameEngine::Environment* _environment;
	
	//������
	GameEngine::Environment::Create();

	_environment = GameEngine::Environment::Get();
	//�V�[���o�^
	RegisterScenes();
	//���s
	result = _environment->Run();
	_environment = nullptr;
	GameEngine::Environment::Release();
	//���s
	//���ʂ̎擾
	return result;
}

void RegisterScenes()
{

	GameEngine::Scene::SceneManager::RegisterScene(new Game::TitleScene());
	GameEngine::Scene::SceneManager::RegisterScene(new Game::GameScene::Scene::TutorialScene());
	GameEngine::Scene::SceneManager::RegisterScene(new Game::GameScene::Scene::Stage1Scene());
	GameEngine::Scene::SceneManager::RegisterScene(new Game::GameScene::Scene::Stage2Scene());
	GameEngine::Scene::SceneManager::RegisterScene(new Game::GameScene::Scene::Stage3Scene());
	GameEngine::Scene::SceneManager::RegisterScene(new Game::ResultScene::StageClearScene());
	GameEngine::Scene::SceneManager::RegisterScene(new Game::ResultScene::GameClearScene());
	GameEngine::Scene::SceneManager::RegisterScene(new Game::ResultScene::GameOverScene());
}
