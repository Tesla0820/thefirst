//
//		ファイル名:TitleManager.cpp
//

#include "ResultManager.h"
#include "../../GameEngine/GameEngine.h"
#include "../../GameEngine/Input.h"
#include "../../GameEngine/Scene/SceneManager.h"

namespace Game
{

	ResultManager::ResultManager()
	{

	}

	ResultManager::~ResultManager()
	{

	}


	//===============================================
	// 初期化処理
	//===============================================
	void ResultManager::Start()
	{
		
	}

	//=================================================
	// 更新処理
	//=================================================
	void ResultManager::Update()
	{
		// 次のシーンへ移動
		if (GameEngine::Input::GetKey(DIK_RETURN, TRIGGER))
		{
			GameEngine::Scene::SceneManager::LoadScene(0);		// タイトルへ
		}
	}


}