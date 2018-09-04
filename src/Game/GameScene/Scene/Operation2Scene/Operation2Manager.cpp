//
//		�t�@�C����:Operation2Manager.cpp
//

#include "Operation2Manager.h"
#include "../../../../GameEngine/GameEngine.h"
#include "../../../../GameEngine/Input.h"
#include "../../../../GameEngine/Scene/SceneManager.h"
#include "../../../Common/Fade.h"

namespace Game { namespace GameScene { namespace Scene
{

	Operation2Manager::Operation2Manager()
	{

	}

	Operation2Manager::~Operation2Manager()
	{

	}


	//===============================================
	// ����������
	//===============================================
	void Operation2Manager::Start()
	{
		_soundPlay = GetAttachedObject()->FindBehaviour<GameEngine::Behaviour::SoundPlay>();
	}

	//=================================================
	// �X�V����
	//=================================================
	void Operation2Manager::Update()
	{
		if (Fade::EndFadeIn())
		{
			//���̃V�[����
			if (GameEngine::Input::GetKey(DIK_RETURN, TRIGGER))
			{
				_soundPlay->Play();
				Fade::StartFadeOut();
			}
		}
		if (Fade::EndFadeOut())
		{
			GameEngine::Scene::SceneManager::LoadScene(10);		// ���������ʂR��
		}
	}

}
}
}