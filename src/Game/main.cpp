//
//		ファイル名:main.cpp
//

// インクルード部
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


// プロトタイプ宣言
int Run(); //プログラムの実行
void RegisterScenes();

// メイン関数
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);	
	UNREFERENCED_PARAMETER(lpCmdLine);
	UNREFERENCED_PARAMETER(nCmdShow);

	int result;
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	// COM ライブラリ初期化
	CoInitializeEx(NULL, COINIT_MULTITHREADED);

	//実行
	result = Run();

	// COM ライブラリを閉じる
	CoUninitialize();

	//return (int)msg.wParam;
	return result;
}

int Run()
{
	int result;
	GameEngine::Environment* _environment;
	
	//初期化
	GameEngine::Environment::Create();

	_environment = GameEngine::Environment::Get();
	//シーン登録
	RegisterScenes();
	//実行
	result = _environment->Run();
	_environment = nullptr;
	GameEngine::Environment::Release();
	//実行
	//結果の取得
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
