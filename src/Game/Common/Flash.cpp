//
//		ファイル名:TitleManager.cpp
//

#include "Flash.h"
#include "../../GameEngine/GameEngine.h"
#include "../../GameEngine/Input.h"
#include "../../GameEngine/Scene/SceneManager.h"
#include "../GameScene/Scene/StageManager.h"

namespace Game
{

	Flash::Flash()
	{

	}

	Flash::~Flash()
	{

	}


	//===============================================
	// 初期化処理
	//===============================================
	void Flash::Start()
	{
		
		_alpha = 0;
		_render = this->GetAttachedObject()->FindBehaviour<GameEngine::Behaviour::UIRenderer>();
	}

	//=================================================
	// 更新処理
	//=================================================
	void Flash::Update()
	{
		if (_alpha == 255)
		{
			_plus = false;
			_minus = true;
		}
		if (_alpha == 0)
		{
			_plus = true;
			_minus = false;
		}

		if (_plus)
		{
			_alpha += 5;
		}
		if (_minus)
		{
			_alpha -= 5;
		}

		_render->SetColor(D3DCOLOR_ARGB(_alpha, 255, 255, 255));
	}


}