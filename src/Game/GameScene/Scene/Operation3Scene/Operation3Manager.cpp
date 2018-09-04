//
//		ファイル名:Operation3Manager.cpp
//

#include "Operation3Manager.h"
#include "../../../../GameEngine/GameEngine.h"
#include "../../../../GameEngine/Input.h"
#include "../../../../GameEngine/Scene/SceneManager.h"
#include "../../../Common/Fade.h"

namespace Game { namespace GameScene { namespace Scene
{

	Operation3Manager::Operation3Manager()
	{

	}

	Operation3Manager::~Operation3Manager()
	{

	}


	//===============================================
	// 初期化処理
	//===============================================
	void Operation3Manager::Start()
	{
		_soundPlay = GetAttachedObject()->FindBehaviour<GameEngine::Behaviour::SoundPlay>();
	}

	//=================================================
	// 更新処理
	//=================================================
	void Operation3Manager::Update()
	{
		if (Fade::EndFadeIn())
		{
			//次のシーンへ
			if (GameEngine::Input::GetKey(DIK_RETURN, TRIGGER))
			{
				_soundPlay->Play();
				Fade::StartFadeOut();
			}
		}
		if (Fade::EndFadeOut())
		{
			GameEngine::Scene::SceneManager::LoadScene(1);		// チュートリアルへ
		}
	}

}
}
}