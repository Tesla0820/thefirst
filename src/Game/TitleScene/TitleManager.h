//
//		ƒtƒ@ƒCƒ‹–¼:TitleManager.h
//

#ifndef HEADER_TITLEMANAGER_H
#define HEADER_TITLEMANAGER_H

#include "../../GameEngine/GameEngine.h"
#include "../../GameEngine/Behaviour/Behaviour.h"

namespace Game
{
	class TitleManager :public GameEngine::Behaviour::Behaviour
	{

	private:
		
	public:
		TitleManager();
		~TitleManager();
		virtual void Start() override;
		virtual void Update() override;

	};
}
#endif