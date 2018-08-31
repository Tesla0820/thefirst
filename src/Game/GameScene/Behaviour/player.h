//
//		�t�@�C����:player.h
//

#ifndef HEADER_PLAYER_H
#define HEADER_PLAYER_H

#include "player.h"
#include "Sonar.h"

namespace Game { namespace GameScene
{
	class Player : public GameEngine::Behaviour::Behaviour,public GameEngine::Behaviour::ICollisionHandler
	{
	private:

		Sonar* _sonar;

		GameEngine::Behaviour::SoundPlay* _soundPlay;
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
		// ICollisionHandler ����Čp������܂���
		virtual void OnCollision(GameEngine::Behaviour::Collider * from) override;

	};
}
}
#endif