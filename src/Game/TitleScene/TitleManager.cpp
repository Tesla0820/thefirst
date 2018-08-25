//
//		ファイル名:TitleManager.cpp
//

#include "TitleManager.h"
#include "../../GameEngine/GameEngine.h"
#include "../../GameEngine/Input.h"
#include "../../GameEngine/Scene/SceneManager.h"

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
		
	}

	//=================================================
	// 更新処理
	//=================================================
	void TitleManager::Update()
	{
		// 次のシーンへ移動
		if (GameEngine::Input::GetKey(DIK_RETURN, TRIGGER))
		{
			GameEngine::Scene::SceneManager::LoadScene(1);
		}

		
	}


}