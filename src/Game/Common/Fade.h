//
//		ファイル名:GameManager.h
//

#ifndef HEADER_FADE_H
#define HEADER_FADE_H

#include "../../GameEngine/GameEngine.h"
#include "../../GameEngine/Behaviour/Behaviour.h"

namespace Game
{
	//フェード速度（フレーム数）
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
		static void StartFadeIn();			//フェードイン開始
		static void StartFadeOut();			//フェードアウト開始
		static int EndFadeIn();				//フェードイン終了
		static int EndFadeOut();			//フェードアウト終了

	};
}
#endif