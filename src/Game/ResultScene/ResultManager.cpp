//
//		ファイル名:ResultManager.cpp
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
			GameEngine::Scene::SceneManager::LoadScene(0);		// タイトルへ
		}
	}


}