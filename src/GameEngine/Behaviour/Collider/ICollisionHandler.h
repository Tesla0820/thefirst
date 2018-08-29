//
//		ƒtƒ@ƒCƒ‹–¼:ICollisionHandler.h
//

#ifndef HEADER_ICOLLISION_HANDLER_H
#define HEADER_ICOLLISION_HANDLER_H


namespace GameEngine { namespace Behaviour
{
class Collider;

struct ICollisionHandler
{
	virtual void OnCollision(Collider* from) = 0;
	virtual ~ICollisionHandler() = default;

};
}
}
#endif