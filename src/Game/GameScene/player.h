//
//		ƒtƒ@ƒCƒ‹–¼:player.h
//

#ifndef HEADER_PLAYER_H
#define HEADER_PLAYER_H

#include "../../GameEngine/GameEngine_inner.h"
#include "../../GameEngine/GameEngine.h"
#include "../../GameEngine/Vertex.h"
#include "../../GameEngine/Behaviour/Behaviour.h"


namespace Game { namespace GameScene
{
	class Player : public GameEngine::Behaviour::Behaviour
	{

	private:
		GameEngine::Behaviour::Transform* _transform;
		
	public:
		virtual void Start() override;
		virtual void Update() override;
	};
}
}
#endif