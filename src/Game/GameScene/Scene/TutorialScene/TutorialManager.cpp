//
//		ファイル名:TutorialManager.cpp
//

#include "TutorialManager.h"
#include "../../../../GameEngine/GameEngine.h"
#include "../../../../GameEngine/Input.h"
#include "../../../../GameEngine/Scene/SceneManager.h"

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
		// 次のシーンへ移動
		if (GameEngine::Input::GetKey(DIK_RETURN, TRIGGER))	// 仮
		{
			GameEngine::Scene::SceneManager::LoadScene(5);		// ステージクリアへ
		}


	}
}
}
}