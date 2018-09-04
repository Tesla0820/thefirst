//
//		ファイル名:StageClearManager.cpp
//

#include "StageClearManager.h"
#include "../../../GameEngine/GameEngine.h"
#include "../../../GameEngine/Input.h"
#include "../../../GameEngine/Scene/SceneManager.h"
#include "../../GameScene/Scene/StageManager.h"
#include "../../Common/Fade.h"


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
		_soundPlays = GetAttachedObject()->FindBehaviours<GameEngine::Behaviour::SoundPlay>();
	}

	//=================================================
	// 更新処理
	//=================================================
	void StageClearManager::Update()
	{
		// 次のシーンへ移動
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
			Game::GameScene::StageManager::NextStage();
		}	
	}

}
}