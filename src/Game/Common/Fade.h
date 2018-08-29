//
//		�t�@�C����:GameManager.h
//

#ifndef HEADER_FADE_H
#define HEADER_FADE_H

#include "../../GameEngine/GameEngine.h"
#include "../../GameEngine/Behaviour/Behaviour.h"

namespace Game
{
	//�t�F�[�h���x�i�t���[�����j
#define FADE_TIME		(60)

	class Fade :public GameEngine::Behaviour::Behaviour
	{

	private:
		static int _fade;
		static int _dir;
		int _alpha;
		int _red;
		int _green;
		int _blue;
		GameEngine::Behaviour::UIRenderer* _render;
	public:
		Fade();
		~Fade();
		virtual void Start() override;
		virtual void Update() override;
		static void StartFadeIn();			//�t�F�[�h�C���J�n
		static void StartFadeOut();			//�t�F�[�h�A�E�g�J�n
		static int EndFadeIn();				//�t�F�[�h�C���I��
		static int EndFadeOut();			//�t�F�[�h�A�E�g�I��

	};
}
#endif