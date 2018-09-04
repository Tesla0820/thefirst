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
#include "GameScene/Scene/OperationScene/OperationScene.h"
#include "GameScene/Scene/Operation2Scene/Operation2Scene.h"
#include "GameScene/Scene/Operation3Scene/Operation3Scene.h"


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

	GameEngine::Scene::SceneManager::RegisterScene(new Game::TitleScene());	//0
	GameEngine::Scene::SceneManager::RegisterScene(new Game::GameScene::Scene::TutorialScene);	//1
	GameEngine::Scene::SceneManager::RegisterScene(new Game::GameScene::Scene::Stage1Scene);	//2
	GameEngine::Scene::SceneManager::RegisterScene(new Game::GameScene::Scene::Stage2Scene);	//3
	GameEngine::Scene::SceneManager::RegisterScene(new Game::GameScene::Scene::Stage3Scene);	//4
	GameEngine::Scene::SceneManager::RegisterScene(new Game::ResultScene::StageClearScene());	//5
	GameEngine::Scene::SceneManager::RegisterScene(new Game::ResultScene::GameClearScene());	//6
	GameEngine::Scene::SceneManager::RegisterScene(new Game::ResultScene::GameOverScene());		//7
	GameEngine::Scene::SceneManager::RegisterScene(new Game::GameScene::Scene::OperationScene());	//8
	GameEngine::Scene::SceneManager::RegisterScene(new Game::GameScene::Scene::Operation2Scene());	//9
	GameEngine::Scene::SceneManager::RegisterScene(new Game::GameScene::Scene::Operation3Scene());	//10

}
