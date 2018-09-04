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
		_soundPlays = GetAttachedObject()->FindBehaviours<GameEngine::Behaviour::SoundPlay>();

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
				_soundPlays[1]->Play();
				Fade::StartFadeOut();
			}
		}
		if (Fade::EndFadeOut())
		{
			GameEngine::Scene::SceneManager::LoadScene(0);		// �^�C�g����
		}
	}


}