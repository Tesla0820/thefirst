//
//		ファイル名:StageClearManager.cpp
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
	// 初期化処理
	//===============================================
	void StageClearManager::Start()
	{
		//this->_Stage = this->_stagemanager->GetStage();
	}

	//=================================================
	// 更新処理
	//=================================================
	void StageClearManager::Update()
	{
		// 次のシーンへ移動

		if (GameEngine::Input::GetKey(DIK_RETURN, TRIGGER))
		{
			//if (this->_Stage == 0)
			//{
			//	GameEngine::Scene::SceneManager::LoadScene(2);	// ステージ1へ
			//}
			//else if (this->_Stage == 1)
			//{
			//	GameEngine::Scene::SceneManager::LoadScene(3);	// ステージ2へ
			//}
			//else if (this->_Stage == 2)
			//{
			//	GameEngine::Scene::SceneManager::LoadScene(4);	// ステージ3へ
			//}
			Game::GameScene::StageManager::NextStage();
		}	
	}

}
}