//
//		�t�@�C����:main.cpp
//

// �C���N���[�h��
#include "main.h"
#include "../GameEngine/GameEngine.h"
#include "TitleScene/TitleScene.h"
#include "GameScene/GameScene.h"

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
	GameEngine::Scene::SceneManager::RegisterScene(new Game::GameScene());
}
