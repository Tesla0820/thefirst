//
//		ファイル名:TutorialManager.cpp
//

#include "TutorialManager.h"
#include "../../../../GameEngine/GameEngine.h"
#include "../../../../GameEngine/Input.h"
#include "../../../../GameEngine/Scene/SceneManager.h"
#include "../../../Common/Fade.h"

namespace Game { namespace GameScene { namespace Scene
{

	TutorialManager::TutorialManager()
	{

	}

	TutorialManager::~TutorialManager()
	{

	}


	//===============================================
	// 初期化処理
	//===============================================
	void TutorialManager::Start()
	{
		
	}

	//=================================================
	// 更新処理
	//=================================================
	void TutorialManager::Update()
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
			GameEngine::Scene::SceneManager::LoadScene(5);		// ステージクリアへ
		}


	}
}
}
}