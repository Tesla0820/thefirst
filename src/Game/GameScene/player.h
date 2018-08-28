//
//		ƒtƒ@ƒCƒ‹–¼:player.h
//

#ifndef HEADER_PLAYER_H
#define HEADER_PLAYER_H

#include "../../GameEngine/GameEngine_inner.h"
#include "../../GameEngine/GameEngine.h"
#include "../../GameEngine/Vertex.h"
#include "../../GameEngine/Behaviour/Behaviour.h"
#include "../../GameEngine/Behaviour/Collider/SphereCollider.h"

namespace Game { namespace GameScene
{
	class Player : public GameEngine::Behaviour::Behaviour
	{

	private:
		GameEngine::Behaviour::Transform* _transform;
		GameEngine::Behaviour::SphereCollider* _sphere;
		float angle;
		int maxFuel;
		int currentFuel;
		int delay;
		float ground;
	public:
		virtual void Start() override;
		virtual void Update() override;
	};
}
}
#endif