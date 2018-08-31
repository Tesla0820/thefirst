//
//		ƒtƒ@ƒCƒ‹–¼:Flash.h
//

#ifndef HEADER_FLASH_H
#define HEADER_FLASH_H

#include "../../GameEngine/GameEngine.h"
#include "../../GameEngine/Behaviour/Behaviour.h"

namespace Game
{
	class Flash :public GameEngine::Behaviour::Behaviour
	{

	private:
		int _alpha;
		bool _plus;
		bool _minus;
		GameEngine::Behaviour::UIRenderer* _render;
	public:
		Flash();
		~Flash();
		virtual void Start() override;
		virtual void Update() override;

	};
}
#endif