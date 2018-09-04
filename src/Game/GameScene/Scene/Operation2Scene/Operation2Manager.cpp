//
//		ファイル名:Operation2Manager.cpp
//

#include "Operation2Manager.h"
#include "../../../../GameEngine/GameEngine.h"
#include "../../../../GameEngine/Input.h"
#include "../../../../GameEngine/Scene/SceneManager.h"
#include "../../../Common/Fade.h"

namespace Game { namespace GameScene { namespace Scene
{

	Operation2Manager::Operation2Manager()
	{

	}

	Operation2Manager::~Operation2Manager()
	{

	}


	//===============================================
	// 初期化処理
	//===============================================
	void Operation2Manager::Start()
	{
				
	}

	//=================================================
	// 更新処理
	//=================================================
	void Operation2Manager::Update()
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
			GameEngine::Scene::SceneManager::LoadScene(10);		// 操作説明画面３へ
		}
	}

}
}
}