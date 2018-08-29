//
//		�t�@�C����:TutorialManager.cpp
//

#include "TutorialManager.h"
#include "../../../../GameEngine/GameEngine.h"
#include "../../../../GameEngine/Input.h"
#include "../../../../GameEngine/Scene/SceneManager.h"
#include "../../../Common/Fade.h"

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
		if (Fade::EndFadeIn())
		{
			//���̃V�[����
			if (GameEngine::Input::GetKey(DIK_RETURN, TRIGGER))
			{
				Fade::StartFadeOut();
			}
		}
		if (Fade::EndFadeOut())
		{
			GameEngine::Scene::SceneManager::LoadScene(5);		// �X�e�[�W�N���A��
		}


	}
}
}
}