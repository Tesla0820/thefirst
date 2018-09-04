//
//		�t�@�C����:Operation2Manager.h
//

#ifndef HEADER_OPERATION2MANAGER_H
#define HEADER_OPERATION2MANAGER_H

#include "../../../../GameEngine/GameEngine.h"
#include "../../../../GameEngine/Behaviour/Behaviour.h"

namespace Game { namespace GameScene { namespace Scene
{

class Operation2Manager :public GameEngine::Behaviour::Behaviour
{

private:
	GameEngine::Behaviour::SoundPlay* _soundPlay;

public:
	Operation2Manager();
	~Operation2Manager();
	virtual void Start() override;
	virtual void Update() override;
};

}
}
}
#endif