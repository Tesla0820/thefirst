//
//		ƒtƒ@ƒCƒ‹–¼:Sonar.h
//

#ifndef HEADER_SONAR_H
#define HEADER_SONAR_H

#include "../../GameEngine/GameEngine.h"

namespace Game { namespace GameScene
{

class Sonar:public GameEngine::Behaviour::Behaviour
{
	private:
		void SonarEnable();
		void SonarDisable();

		GameEngine::Behaviour::SphereCollider* _collider;
		int _time;
		bool _isUsing;
		D3DXVECTOR3 _position;
		D3DXVECTOR3 _direction;

		static constexpr int maxTime = 300;
	public:
		Sonar() = default;
		virtual void Start() override;
		virtual void Update() override;
		bool Ping();
		void SetCollider(GameEngine::Behaviour::SphereCollider* collider);

};

}
}
#endif