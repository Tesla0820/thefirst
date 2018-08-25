//
//		�t�@�C����:TitleManager.cpp
//

#include "TitleManager.h"
#include "../../GameEngine/GameEngine.h"
#include "../../GameEngine/Input.h"
#include "../../GameEngine/Scene/SceneManager.h"

namespace Game
{

	TitleManager::TitleManager()
	{

	}

	TitleManager::~TitleManager()
	{
		
	}


	//===============================================
	// ����������
	//===============================================
	void TitleManager::Start()
	{
		
	}

	//=================================================
	// �X�V����
	//=================================================
	void TitleManager::Update()
	{
		// ���̃V�[���ֈړ�
		if (GameEngine::Input::GetKey(DIK_RETURN, TRIGGER))
		{
			GameEngine::Scene::SceneManager::LoadScene(1);
		}

		
	}


}