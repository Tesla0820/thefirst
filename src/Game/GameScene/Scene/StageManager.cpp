//
//		ファイル名:StageManager.cpp
//

#include "StageManager.h"
#include "../../../GameEngine/GameEngine.h"
#include "../../../GameEngine/Input.h"
#include "../../../GameEngine/Scene/SceneManager.h"

namespace Game { namespace GameScene
{

//=====================================================
// 現在のステージの番号のセット
//=====================================================
void StageManager::SetStage(int stage)
{
	_stage = stage;
}

//=====================================================
// ステージの読み込み（_stageの番号を使って）
//=====================================================
void StageManager::LoadStage()
{
	if (_stage >= _maxStage)
	{
		//存在するステージ数を越したとき
		_stage = 0;
		GameEngine::Scene::SceneManager::LoadScene(6);
		return;
	}
	else
	{
		//次のステージに遷移
		GameEngine::Scene::SceneManager::LoadScene(1 + _stage);
	}
}

//=====================================================
//次のステージへ遷移
//=====================================================
void StageManager::NextStage()
{
	_stage++;
	LoadStage();
}
		
}
}