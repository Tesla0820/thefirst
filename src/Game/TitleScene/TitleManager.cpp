//
//		�t�@�C����:TitleManager.cpp
//

#include "TitleManager.h"
#include "../../GameEngine/GameEngine.h"
#include "../../GameEngine/Input.h"
#include "../../GameEngine/Scene/SceneManager.h"
#include "../GameScene/Scene/StageManager.h"
#include "../Common/Fade.h"

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
		GameEngine::GameObject* object = this->GetAttachedObject();
		_mode = MODE_TUTORIAL;
		_alpha = 0;
		_transform = object->GetTransform();
		_soundPlay = object->FindBehaviour<GameEngine::Behaviour::SoundPlay>();
		_soundPlay->Play();
	}

	//=================================================
	// �X�V����
	//=================================================
	void TitleManager::Update()
	{
		D3DXVECTOR3 pos = { 0.0f,0.0f,0.0f };
		

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

		if (this->_mode == MODE_TUTORIAL)
		{
			pos = D3DXVECTOR3(245.0f, 400.0f, 0.0f);
			
		}
		else if (this->_mode == MODE_STAGE1)
		{
			pos = D3DXVECTOR3(245.0f, 450.0f, 0.0f);
		}
		else if (this->_mode == MODE_STAGE2)
		{
			pos = D3DXVECTOR3(245.0f, 500.0f, 0.0f);
		}
		else if (this->_mode == MODE_STAGE3)
		{
			pos = D3DXVECTOR3(245.0f, 550.0f, 0.0f);
		}

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

		
		_transform->SetPosition(&pos);
		
	}


}