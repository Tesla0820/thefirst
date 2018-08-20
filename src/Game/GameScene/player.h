//
//		ƒtƒ@ƒCƒ‹–¼:player.h
//

#ifndef HEADER_PLAYER_H
#define HEADER_PLAYER_H

#include "../../GameEngine/GameEngine_inner.h"
#include "../../GameEngine/GameEngine.h"
#include "../../GameEngine/Vertex.h"
#include "../../GameEngine/Behaviour/Behaviour.h"


namespace Game
{
	class Player : public GameEngine::Behaviour::Behaviour
	{

	private:
		//GameEngine::Vertex VPlayer;
		D3DXVECTOR3 _pos;
		
	public:
		Player();
		Player(D3DXVECTOR3(pos));
		~Player();
		virtual void Start() override;
		virtual void Update() override;
		Player* GetPlayer();
	};
}
#endif