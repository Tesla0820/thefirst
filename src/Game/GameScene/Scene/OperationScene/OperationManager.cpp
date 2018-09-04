//
//		ファイル名:OperationManager.cpp
//

#include "OperationManager.h"
#include "../../../../GameEngine/GameEngine.h"
#include "../../../../GameEngine/Input.h"
#include "../../../../GameEngine/Scene/SceneManager.h"
#include "../../../Common/Fade.h"

namespace Game { namespace GameScene { namespace Scene
{

	OperationManager::OperationManager()
	{

	}

	OperationManager::~OperationManager()
	{

	}


	//===============================================
	// 初期化処理
	//===============================================
	void OperationManager::Start()
	{
		_soundPlays = GetAttachedObject()->FindBehaviours<GameEngine::Behaviour::SoundPlay>();

	}

	//=================================================
	// 更新処理
	//=================================================
	void OperationManager::Update()
	{
		if (Fade::EndFadeIn())
		{
			//次のシーンへ
			if (GameEngine::Input::GetKey(DIK_RETURN, TRIGGER))
			{
				_soundPlays[1]->Play();
				Fade::StartFadeOut();
			}
		}
		if (Fade::EndFadeOut())
		{
			GameEngine::Scene::SceneManager::LoadScene(9);		// 操作説明画面２へ
		}
	}

}
}
}