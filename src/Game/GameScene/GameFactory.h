//
//		�t�@�C����:GameFactory.h
//

#ifndef HEADER_GAME_FACTORY_H
#define HEADER_GAME_FACTORY_H

#include "../../GameEngine/GameObject.h"

namespace Game { namespace GameScene
{
	

	class GameFactory
	{
		public:
		static void CreateGround();
		static void CreatePlayer();
		static GameEngine::GameObject* CreateUIgauge();

	};
}
}
#endif