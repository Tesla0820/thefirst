// SphereCollider.h

#ifndef HEADER_SPHERE_COLLIDER_H 
#define HEADER_SPHERE_COLLIDER_H

#include "Collider.h"


namespace GameEngine { namespace Behaviour
{

class BoxCollider;

//�����̂̔�����s���N���X�ł��B
class SphereCollider : public Collider
{
private:
	void HitToSphere(SphereCollider* collider);
	void HitToBox(BoxCollider* collider);

	D3DXVECTOR3 _oldPosition;
	D3DXVECTOR3	_center;	// ���S���W
	float _radius;			// ���a

protected:
	virtual void Hit(Collider* collider) override;

public:
	SphereCollider();
	SphereCollider(D3DXVECTOR3 center, float radius);
	D3DXVECTOR3 GetCenterPosition();
	float GetRadius();
	virtual void Start() override;
};

}
}




#endif