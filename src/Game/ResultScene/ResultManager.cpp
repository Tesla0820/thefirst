//
//		�t�@�C����:TitleManager.cpp
//

#include "ResultManager.h"
#include "../../GameEngine/GameEngine.h"
#include "../../GameEngine/Input.h"
#include "../../GameEngine/Scene/SceneManager.h"

namespace Game
{

	ResultManager::ResultManager()
	{

	}

	ResultManager::~ResultManager()
	{

	}


	//===============================================
	// ����������
	//===============================================
	void ResultManager::Start()
	{
		
	}

	//=================================================
	// �X�V����
	//=================================================
	void ResultManager::Update()
	{
		// ���̃V�[���ֈړ�
		if (GameEngine::Input::GetKey(DIK_RETURN, TRIGGER))
		{
			GameEngine::Scene::SceneManager::LoadScene(0);		// �^�C�g����
		}
	}


}