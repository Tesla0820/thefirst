// SphereCollider.h

#ifndef HEADER_SPHERE_COLLIDER_H 
#define HEADER_SPHERE_COLLIDER_H

#include <vector>
#include "../../GameEngine_inner.h"
#include "Collider.h"


namespace GameEngine { namespace Behaviour
{

class BoxCollider;

//�����̂̔�����s���N���X�ł��B
class SphereCollider :public Collider
{
private:
	D3DXVECTOR3 _oldPosition;
	D3DXVECTOR3	_center;	// ���S���W
	float _radius;			// ���a

public:
	SphereCollider();
	SphereCollider(D3DXVECTOR3 center, float radius);
	D3DXVECTOR3 GetCenterPosition();
	float GetRadius();
	virtual void Start() override;
	virtual void Hit(Collider* collider) override;
	void HitToSphere(SphereCollider* collider);
	void HitToBox(BoxCollider* collider);
};

}
}




#endif