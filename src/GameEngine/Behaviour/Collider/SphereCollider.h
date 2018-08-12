// SphereCollider.h

#ifndef HEADER_SPHERE_COLLIDER_H 
#define HEADER_SPHERE_COLLIDER_H

#include <vector>
#include "../../GameEngine_inner.h"
#include "Collider.h"
#include "BoxCollider.h"


namespace GameEngine { namespace Behaviour
{

//�����̂̔�����s���N���X�ł��B
class SphereCollider :public Collider
{
private:
	D3DXVECTOR3	_center;	// ���S���W
	float _radius;			// ���a

public:
	SphereCollider(D3DXVECTOR3 center, float radius);
	virtual ~SphereCollider();
	float* GetRadius();
	virtual void Hit() override;
	void HitToSphere(SphereCollider* collider);
	void HitToBox(BoxCollider* collider);
};

}
}




#endif