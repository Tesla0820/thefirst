//
//		�t�@�C����:StageClearManager.cpp
//

#include "StageClearManager.h"
#include "../../../GameEngine/GameEngine.h"
#include "../../../GameEngine/Input.h"
#include "../../../GameEngine/Scene/SceneManager.h"
#include "../../GameScene/Scene/StageManager.h"
#include "../../Common/Fade.h"


namespace Game { namespace ResultScene
{
	StageClearManager::StageClearManager()
	{

	}

	StageClearManager::~StageClearManager()
	{

	}

	//===============================================
	// ����������
	//===============================================
	void StageClearManager::Start()
	{
		//_render = this->GetAttachedObject()->FindBehaviour<GameEngine::Behaviour::UIRenderer>();

	}

	//=================================================
	// �X�V����
	//=================================================
	void StageClearManager::Update()
	{
		// ���̃V�[���ֈړ�
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
			Game::GameScene::StageManager::NextStage();
		}	
	}

}
}