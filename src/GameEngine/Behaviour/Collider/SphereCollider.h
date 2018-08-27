// SphereCollider.h

#ifndef HEADER_SPHERE_COLLIDER_H 
#define HEADER_SPHERE_COLLIDER_H

#include "Collider.h"


namespace GameEngine { namespace Behaviour
{

class BoxCollider;

//直方体の判定を行うクラスです。
class SphereCollider : public Collider
{
private:
	void HitToSphere(SphereCollider* collider);
	void HitToBox(BoxCollider* collider);

	D3DXVECTOR3 _oldPosition;
	D3DXVECTOR3	_center;	// 中心座標
	float _radius;			// 半径

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