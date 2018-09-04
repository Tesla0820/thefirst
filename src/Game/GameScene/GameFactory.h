//
//		ƒtƒ@ƒCƒ‹–¼:GameFactory.h
//

#ifndef HEADER_GAME_FACTORY_H
#define HEADER_GAME_FACTORY_H

#include "../../GameEngine/GameObject.h"

namespace Game { namespace GameScene
{

class GameFactory
{
  public:
  static GameEngine::GameObject* CreateGround();
  static GameEngine::GameObject* CreatePlayer();
  static GameEngine::GameObject* CreateSonarEffect();
  static GameEngine::GameObject* CreateFade();
  static GameEngine::GameObject* CreateHoverGauge();
  static GameEngine::GameObject* CreateSonarGauge();
  static GameEngine::GameObject* CreateUIgaugeEdge();
};

}
}
#endif