//
//		�t�@�C����:TitleManager.cpp
//

#include "TitleManager.h"
#include "../../GameEngine/GameEngine.h"
#include "../../GameEngine/Input.h"
#include "../../GameEngine/Scene/SceneManager.h"
#include "../GameScene/Scene/StageManager.h"

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
		this->_mode = MODE_TUTORIAL;
	}

	//=================================================
	// �X�V����
	//=================================================
	void TitleManager::Update()
	{
		// �X�e�[�W�I��
		if (GameEngine::Input::GetKey(DIK_UP, TRIGGER))
		{
			this->_mode--;
			if (this->_mode < 0)
			{
				this->_mode = MODE_TUTORIAL;
			}
		}
		else if (GameEngine::Input::GetKey(DIK_DOWN, TRIGGER))
		{
			this->_mode++;
			if (this->_mode >= MODE_MAX)
			{
				this->_mode = MODE_STAGE3;
			}
		}

		// ���̃V�[���ֈړ�
		if (GameEngine::Input::GetKey(DIK_RETURN, TRIGGER))
		{
			if (this->_mode == MODE_TUTORIAL)
			{
				GameEngine::Scene::SceneManager::LoadScene(1);		// �`���[�g���A����
				Game::GameScene::StageManager::SetStage(0);
			}
			else if (this->_mode == MODE_STAGE1)
			{
				GameEngine::Scene::SceneManager::LoadScene(2);		// �X�e�[�W�P��
				Game::GameScene::StageManager::SetStage(1);
			}
			else if (this->_mode == MODE_STAGE2)
			{
				GameEngine::Scene::SceneManager::LoadScene(3);		// �X�e�[�W�Q��
				Game::GameScene::StageManager::SetStage(2);
			}
			else if (this->_mode == MODE_STAGE3)
			{
				GameEngine::Scene::SceneManager::LoadScene(4);		// �X�e�[�W�R��
				Game::GameScene::StageManager::SetStage(3);
			}
		}
		

		
	}


}