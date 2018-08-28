//
//		�t�@�C����:StageClearManager.cpp
//

#include "StageClearManager.h"
#include "../../../GameEngine/GameEngine.h"
#include "../../../GameEngine/Input.h"
#include "../../../GameEngine/Scene/SceneManager.h"
#include "../../GameScene/Scene/StageManager.h"


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
		//this->_Stage = this->_stagemanager->GetStage();
	}

	//=================================================
	// �X�V����
	//=================================================
	void StageClearManager::Update()
	{
		// ���̃V�[���ֈړ�

		if (GameEngine::Input::GetKey(DIK_RETURN, TRIGGER))
		{
			//if (this->_Stage == 0)
			//{
			//	GameEngine::Scene::SceneManager::LoadScene(2);	// �X�e�[�W1��
			//}
			//else if (this->_Stage == 1)
			//{
			//	GameEngine::Scene::SceneManager::LoadScene(3);	// �X�e�[�W2��
			//}
			//else if (this->_Stage == 2)
			//{
			//	GameEngine::Scene::SceneManager::LoadScene(4);	// �X�e�[�W3��
			//}
			Game::GameScene::StageManager::NextStage();
		}	
	}

}
}