//
//		�t�@�C����:OperationManager.cpp
//

#include "OperationManager.h"
#include "../../../../GameEngine/GameEngine.h"
#include "../../../../GameEngine/Input.h"
#include "../../../../GameEngine/Scene/SceneManager.h"
#include "../../../Common/Fade.h"

namespace Game { namespace GameScene { namespace Scene
{

	OperationManager::OperationManager()
	{

	}

	OperationManager::~OperationManager()
	{

	}


	//===============================================
	// ����������
	//===============================================
	void OperationManager::Start()
	{
				
	}

	//=================================================
	// �X�V����
	//=================================================
	void OperationManager::Update()
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
			GameEngine::Scene::SceneManager::LoadScene(1);		// �X�e�[�W�N���A��
		}
	}

}
}
}