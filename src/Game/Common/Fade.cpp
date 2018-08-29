//
//		�t�@�C����:Fade.cpp
//

#include "Fade.h"
#include "../../GameEngine/GameEngine.h"
#include "../../GameEngine/Input.h"
#include "../../GameEngine/Scene/SceneManager.h"

namespace Game
{
	int Fade::_fade;
	int Fade::_dir;


	Fade::Fade()
	{

	}

	Fade::~Fade()
	{

	}


	//===============================================
	// ����������
	//===============================================
	void Fade::Start()
	{
		_fade = FADE_TIME;
		_dir = -1;
		_alpha = 0;
		_red = 0;
		_blue = 0;
		_green = 0;
		_render = this->GetAttachedObject()->FindBehaviour<GameEngine::Behaviour::UIRenderer>();

	}

	//=================================================
	// �X�V����
	//=================================================
	void Fade::Update()
	{
		this->_fade += this->_dir;
		if (this->_fade < 0)
		{
			this->_fade = 0;
		}
		else if (this->_fade > FADE_TIME)
		{
			this->_fade = FADE_TIME;
		}

		this->_alpha = this->_fade * 255 / FADE_TIME;
		// �A���t�@�l�Ƃ���Set()��`��
		_render->SetColor(D3DCOLOR_ARGB(_alpha, _red, _green, _blue));


	}


	void Fade::StartFadeIn()
	{
		_fade = FADE_TIME;
		_dir = -1;
	}

	void Fade::StartFadeOut()
	{
		_fade = 0;
		_dir = 1;
	}


	int Fade::EndFadeIn()
	{
		return(_dir < 0 && _fade <= 0);
	}


	int Fade::EndFadeOut()
	{
		return(_dir > 0 && _fade >= FADE_TIME);
	}
}