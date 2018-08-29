//
//		�t�@�C����:ResultManager.cpp
//

#include "ResultManager.h"
#include "../../GameEngine/GameEngine.h"
#include "../../GameEngine/Input.h"
#include "../../GameEngine/Scene/SceneManager.h"
#include "../Common/Fade.h"

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
			GameEngine::Scene::SceneManager::LoadScene(0);		// �^�C�g����
		}
	}


}