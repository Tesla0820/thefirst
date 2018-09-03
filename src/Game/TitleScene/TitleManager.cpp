//
//		ファイル名:TitleManager.cpp
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
	// 初期化処理
	//===============================================
	void TitleManager::Start()
	{
		_mode = MODE_TUTORIAL;
		_red = 0;
		_green = 0;
		_blue = 0;
		_alpha = 0;
		_transform = this->GetAttachedObject()->GetTransform();
		_render = this->GetAttachedObject()->FindBehaviour<GameEngine::Behaviour::UIRenderer>();
	}

	//=================================================
	// 更新処理
	//=================================================
	void TitleManager::Update()
	{
		D3DXVECTOR3 pos = { 0.0f,0.0f,0.0f };


		// ステージ選択
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
			pos = D3DXVECTOR3(260.0f, 400.0f, 0.0f);

		}
		else if (this->_mode == MODE_STAGE1)
		{
			pos = D3DXVECTOR3(260.0f, 450.0f, 0.0f);
		}
		else if (this->_mode == MODE_STAGE2)
		{
			pos = D3DXVECTOR3(260.0f, 500.0f, 0.0f);
		}
		else if (this->_mode == MODE_STAGE3)
		{
			pos = D3DXVECTOR3(260.0f, 550.0f, 0.0f);
		}

		if (Fade::EndFadeIn())
		{
			//次のシーンへ
			if (GameEngine::Input::GetKey(DIK_RETURN, TRIGGER))
			{
				Fade::StartFadeOut();
			}
		}
		if (Fade::EndFadeOut())
		{
			if (this->_mode == MODE_TUTORIAL)
			{
				GameEngine::Scene::SceneManager::LoadScene(8);		// チュートリアルの前の操作説明へ
				Game::GameScene::StageManager::SetStage(0);
			}
			else if (this->_mode == MODE_STAGE1)
			{
				GameEngine::Scene::SceneManager::LoadScene(2);		// ステージ１へ
				Game::GameScene::StageManager::SetStage(1);
			}
			else if (this->_mode == MODE_STAGE2)
			{
				GameEngine::Scene::SceneManager::LoadScene(3);		// ステージ２へ
				Game::GameScene::StageManager::SetStage(2);
			}
			else if (this->_mode == MODE_STAGE3)
			{
				GameEngine::Scene::SceneManager::LoadScene(4);		// ステージ３へ
				Game::GameScene::StageManager::SetStage(3);
			}
		}

		if (_red >= 255)
		{
			_plus = false;
		}
		else if (_red <= 0)
		{
			_plus = true;
		}
		if (_plus)
		{
			_red += 5;
		}
		else
		{
			_red -= 5;
		}


		_transform->SetPosition(&pos);
		_render->SetColor(D3DCOLOR_ARGB(255, _red, _green, _blue));
	}


}