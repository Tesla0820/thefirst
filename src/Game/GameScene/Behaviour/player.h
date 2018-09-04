//
//		ƒtƒ@ƒCƒ‹–¼:player.h
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
		float _angle;
		int _maxFuel;
		int _currentFuel;
		int _delay;
		int _state;

		void UpdatePlayer();
		void UpdateClear();
		void UpdateOver();
	public:

		virtual void Start() override;
		virtual void Update() override;
		virtual void OnCollision(GameEngine::Behaviour::Collider * from) override;
		float GetSonarRate();
		float GetHoverRate();

	};
}
}
#endif