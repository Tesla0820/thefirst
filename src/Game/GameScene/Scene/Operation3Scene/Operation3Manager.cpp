//
//		�t�@�C����:Operation3Manager.cpp
//

#include "Operation3Manager.h"
#include "../../../../GameEngine/GameEngine.h"
#include "../../../../GameEngine/Input.h"
#include "../../../../GameEngine/Scene/SceneManager.h"
#include "../../../Common/Fade.h"

namespace Game { namespace GameScene { namespace Scene
{

	Operation3Manager::Operation3Manager()
	{

	}

	Operation3Manager::~Operation3Manager()
	{

	}


	//===============================================
	// ����������
	//===============================================
	void Operation3Manager::Start()
	{
				
	}

	//=================================================
	// �X�V����
	//=================================================
	void Operation3Manager::Update()
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
			GameEngine::Scene::SceneManager::LoadScene(1);		// �`���[�g���A����
		}
	}

}
}
}