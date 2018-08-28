//
//		�t�@�C����:TutorialManager.cpp
//

#include "TutorialManager.h"
#include "../../../../GameEngine/GameEngine.h"
#include "../../../../GameEngine/Input.h"
#include "../../../../GameEngine/Scene/SceneManager.h"

namespace Game { namespace GameScene { namespace Scene
{

	TutorialManager::TutorialManager()
	{

	}

	TutorialManager::~TutorialManager()
	{

	}


	//===============================================
	// ����������
	//===============================================
	void TutorialManager::Start()
	{
		
	}

	//=================================================
	// �X�V����
	//=================================================
	void TutorialManager::Update()
	{
		// ���̃V�[���ֈړ�
		if (GameEngine::Input::GetKey(DIK_RETURN, TRIGGER))	// ��
		{
			GameEngine::Scene::SceneManager::LoadScene(5);		// �X�e�[�W�N���A��
		}


	}
}
}
}