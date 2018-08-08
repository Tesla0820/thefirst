//
//		ファイル名:main.cpp
//

// インクルード部
#include "main.h"
#include "../GameEngine/GameEngine.h"
#include "TitleScene/TitleScene.h"

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
	GameEngine::Scene::SceneManager::RegisterScene(new Game::TitleScene());
}
